/*
 * Tulip Indicators Node.js Binding
 * https://tulipindicators.org/
 * Copyright (c) 2016-2019 Tulip Charts LLC
 * Lewis Van Winkle (LV@tulipcharts.org)
 *
 * This file is part of Tulip Indicators.
 *
 * Tulip Indicators is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * Tulip Indicators is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tulip Indicators.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include <nan.h>
#include <stdlib.h>
#include "external/indicators.h"
using namespace v8;


static double *get_array(Local<Array> input, int offset) {
    const int size = input->Length() - offset;

    double *ret = (double*)malloc(sizeof(double) * size);
    //TODO check ret

    int i;
    for (i = 0; i < size; ++i) {
        Nan::Maybe<double> d = Nan::To<double>(Nan::Get(input, i + offset).ToLocalChecked());
        ret[i] = d.FromMaybe(0.0);
    }

    return ret;
}


NAN_METHOD(startbyindex) {

    if (info.Length() != 2) {
        Nan::ThrowTypeError("Wrong number of arguments. Expecting: index, options.");
        return;
    }

    if (!info[0]->IsNumber()) {
        Nan::ThrowTypeError("Expecting first argument to be function index number.");
        return;
    }

    if (!info[1]->IsArray()) {
        Nan::ThrowTypeError("Expecting second argument to be array of options.");
        return;
    }

    const int index = Nan::To<int>(info[0]).FromMaybe(-1);
    if (index < 0 || index > TI_INDICATOR_COUNT) {
        Nan::ThrowTypeError("Invalid indicator index.");
        return;
    }

    const ti_indicator_info *ind = ti_indicators + index;


    Local<Array> options = Local<Array>::Cast(info[1]);
    if ((unsigned int)ind->options != options->Length()) {
        Nan::ThrowTypeError("Invalid number of options.");
        return;
    }


    double *option_array = get_array(options, 0);

    const int start = ind->start(option_array);

    free(option_array);


    info.GetReturnValue().Set(start);
}


NAN_METHOD(callbyindex) {

    if (info.Length() != 4) {
        Nan::ThrowTypeError("Wrong number of arguments. Expecting: index, inputs, options, and callback.");
        return;
    }

    if (!info[0]->IsNumber()) {
        Nan::ThrowTypeError("Expecting first argument to be function index number.");
        return;
    }

    if (!info[1]->IsArray()) {
        Nan::ThrowTypeError("Expecting second argument to be array of inputs.");
        return;
    }

    if (!info[2]->IsArray()) {
        Nan::ThrowTypeError("Expecting third argument to be array of options.");
        return;
    }

    if (!info[3]->IsFunction()) {
        Nan::ThrowTypeError("Expecting last argument to be callback function.");
        return;
    }

    const int index = Nan::To<int>(info[0]).FromMaybe(-1);
    if (index < 0 || index > TI_INDICATOR_COUNT) {
        Nan::ThrowTypeError("Invalid indicator index.");
        return;
    }

    const ti_indicator_info *ind = ti_indicators + index;



    Local<Array> inputs = Local<Array>::Cast(info[1]);
    if ((unsigned int)ind->inputs != inputs->Length()) {
        Nan::ThrowTypeError("Invalid number of inputs.");
        return;
    }


    Local<Array> options = Local<Array>::Cast(info[2]);
    if ((unsigned int)ind->options != options->Length()) {
        Nan::ThrowTypeError("Invalid number of options.");
        return;
    }




    double *input_arr[TI_MAXINDPARAMS] = {0};
    int in_size = -1;

    int i;

    /* Find smallest size of input. */
    for (i = 0; i < ind->inputs; ++i) {
        Local<v8::Value> input = Nan::Get(inputs, i).ToLocalChecked();

        if (!input->IsArray()) {
            Nan::ThrowTypeError("Expecting second argument to be array of arrays of numbers.");
            return;
        }

        const int size = Local<Array>::Cast(input)->Length();
        if (in_size == -1 || size < in_size) {
            in_size = size;
        }
    }




    /* Get input arrays. */
    for (i = 0; i < ind->inputs; ++i) {
        Local<Array> input = Local<Array>::Cast(Nan::Get(inputs, i).ToLocalChecked());

        const int offset = input->Length() - in_size;
        input_arr[i] = get_array(input, offset);
    }



    /* Get option array. */
    double *option_arr = get_array(options, 0);


    /* Setup output arrays. */
    const int start = ind->start(option_arr);
    const int out_size = start >= 0 ? in_size - start : 0;


    double *output_arr[TI_MAXINDPARAMS] = {0};
    for (i = 0; i < ind->outputs; ++i) {
        output_arr[i] = (double*)malloc(sizeof(double) * out_size);
    }


    /* Do the calculation. */
    int result = ind->indicator(in_size, input_arr, option_arr, output_arr);


    /* Clean up inputs. */
    for (i = 0; i < ind->inputs; ++i) {
        free(input_arr[i]);
    }


    /* Clean up options. */
    free(option_arr);


    Local<Value> cb_argv[2];

    if (result == TI_OKAY) {
        Local<Array> outputs = Nan::New<Array>(ind->outputs);

        for (i = 0; i < ind->outputs; ++i) {
            Local<Array> out = Nan::New<Array>(out_size);
            int j;
            for (j = 0; j < out_size; ++j) {
                Nan::Set(out, j, Nan::New(output_arr[i][j]));
            }
            Nan::Set(outputs, i, out);
        }

        cb_argv[0] = Nan::Null();
        cb_argv[1] = outputs;

    } else {

        cb_argv[0] = Nan::New<String>("Invalid options").ToLocalChecked();
        cb_argv[1] = Nan::Null();

    }


    /* Clean up outputs. */
    for (i = 0; i < ind->outputs; ++i) {
        free(output_arr[i]);
    }


    v8::Local<v8::Function> callbackHandle = info[3].As<v8::Function>();
    Nan::AsyncResource cb("tulind-callback");
    cb.runInAsyncScope(Nan::GetCurrentContext()->Global(), callbackHandle, 2, cb_argv);
}


NAN_MODULE_INIT(Init) {

    Local<FunctionTemplate> call = Nan::New<FunctionTemplate>(callbyindex);
    Nan::Set(target, Nan::New("callbyindex").ToLocalChecked(), Nan::GetFunction(call).ToLocalChecked());

    Local<FunctionTemplate> start = Nan::New<FunctionTemplate>(startbyindex);
    Nan::Set(target, Nan::New("startbyindex").ToLocalChecked(), Nan::GetFunction(start).ToLocalChecked());


    Local<v8::Object> indicators = Nan::New<v8::Object>();

    {
        const ti_indicator_info *info = ti_indicators;
        while (info->name != 0) {
            Local<v8::Object> ind = Nan::New<v8::Object>();
            Nan::Set(indicators, Nan::New(info->name).ToLocalChecked(), ind);

            Nan::Set(ind, Nan::New("index").ToLocalChecked(), Nan::New((int)(info - ti_indicators)));
            Nan::Set(ind, Nan::New("name").ToLocalChecked(), Nan::New(info->name).ToLocalChecked());
            Nan::Set(ind, Nan::New("full_name").ToLocalChecked(), Nan::New(info->full_name).ToLocalChecked());

            char const *type = "unknown";

            switch (info->type) {
                case TI_TYPE_OVERLAY:
                    type = "overlay";
                    break;
                case TI_TYPE_INDICATOR:
                    type = "indicator";
                    break;
                case TI_TYPE_MATH:
                    type = "math";
                    break;
                case TI_TYPE_SIMPLE:
                    type = "simple";
                    break;
                case TI_TYPE_COMPARATIVE:
                    type = "comparative";
                    break;
            }

            Nan::Set(ind, Nan::New("type").ToLocalChecked(), Nan::New(type).ToLocalChecked());

            Nan::Set(ind, Nan::New("inputs").ToLocalChecked(), Nan::New(info->inputs));
            Nan::Set(ind, Nan::New("options").ToLocalChecked(), Nan::New(info->options));
            Nan::Set(ind, Nan::New("outputs").ToLocalChecked(), Nan::New(info->outputs));

            int i;

            Local<Array> inputs = Nan::New<Array>(info->inputs);
            for (i = 0; i < info->inputs; ++i)
                Nan::Set(inputs, i, Nan::New(info->input_names[i]).ToLocalChecked());
            Nan::Set(ind, Nan::New("input_names").ToLocalChecked(), inputs);

            Local<Array> options = Nan::New<Array>(info->options);
            for (i = 0; i < info->options; ++i)
                Nan::Set(options, i, Nan::New(info->option_names[i]).ToLocalChecked());
            Nan::Set(ind, Nan::New("option_names").ToLocalChecked(), options);

            Local<Array> outputs = Nan::New<Array>(info->outputs);
            for (i = 0; i < info->outputs; ++i)
                Nan::Set(outputs, i, Nan::New(info->output_names[i]).ToLocalChecked());
            Nan::Set(ind, Nan::New("output_names").ToLocalChecked(), outputs);

            ++info;
        }

    }


    Nan::Set(target, Nan::New("indicators").ToLocalChecked(), indicators);

    Nan::Set(target, Nan::New("version").ToLocalChecked(), Nan::New(TI_VERSION).ToLocalChecked());

}

NODE_MODULE(tulind, Init)

