/*
 * TULIP INDICATORS AMALGAMATION
 * This is all of Tulip Indicators in one file.
 * To get the original sources, go to https://tulipindicators.org
 */


/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2018 Tulip Charts LLC
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


/*
 *
 * Version 0.8.4
 * Header Build 1537377628
 *
 */

 /*
  *
  * This file is generated. Do not modify directly.
  *
  */

#ifndef __TI_INDICATORS_H__
#define __TI_INDICATORS_H__


#define TI_VERSION "0.8.4"
#define TI_BUILD 1537377628


#ifndef TI_SKIP_SYSTEM_HEADERS
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


const char* ti_version();
long int ti_build();





#define TI_REAL double

#define TI_INDICATOR_COUNT 104 /* Total number of indicators. */

#define TI_OKAY                    0
#define TI_INVALID_OPTION          1

#define TI_TYPE_OVERLAY            1 /* These have roughly the same range as the input data. */
#define TI_TYPE_INDICATOR          2 /* Everything else (e.g. oscillators). */
#define TI_TYPE_MATH               3 /* These aren't so good for plotting, but are useful with formulas. */
#define TI_TYPE_SIMPLE             4 /* These apply a simple operator (e.g. addition, sin, sqrt). */
#define TI_TYPE_COMPARATIVE        5 /* These are designed to take inputs from different securities. i.e. compare stock A to stock B.*/

#define TI_MAXINDPARAMS 10 /* No indicator will use more than this many inputs, options, or outputs. */


typedef int (*ti_indicator_start_function)(TI_REAL const *options);
typedef int (*ti_indicator_function)(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);

typedef struct ti_indicator_info {
    char *name;
    char *full_name;
    ti_indicator_start_function start;
    ti_indicator_function indicator;
    int type, inputs, options, outputs;
    char *input_names[TI_MAXINDPARAMS];
    char *option_names[TI_MAXINDPARAMS];
    char *output_names[TI_MAXINDPARAMS];
} ti_indicator_info;


/*Complete array of all indicators. Last element is 0,0,0,0...*/
extern ti_indicator_info ti_indicators[];


/*Searches for an indicator by name. Returns 0 if not found.*/
const ti_indicator_info *ti_find_indicator(const char *name);






/*
 *
 *
 *
 *
 *
 *        All indicators below, sorted alphabetically.
 *
 *
 *
 *
 *
 */








/* Vector Absolute Value */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: abs */
int ti_abs_start(TI_REAL const *options);
int ti_abs(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Arccosine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: acos */
int ti_acos_start(TI_REAL const *options);
int ti_acos(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Accumulation/Distribution Line */
/* Type: indicator */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: none */
/* Outputs: ad */
int ti_ad_start(TI_REAL const *options);
int ti_ad(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Addition */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: real, real */
/* Options: none */
/* Outputs: add */
int ti_add_start(TI_REAL const *options);
int ti_add(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Accumulation/Distribution Oscillator */
/* Type: indicator */
/* Input arrays: 4    Options: 2    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: short period, long period */
/* Outputs: adosc */
int ti_adosc_start(TI_REAL const *options);
int ti_adosc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Average Directional Movement Index */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: dx */
int ti_adx_start(TI_REAL const *options);
int ti_adx(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Average Directional Movement Rating */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: dx */
int ti_adxr_start(TI_REAL const *options);
int ti_adxr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Awesome Oscillator */
/* Type: indicator */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: high, low */
/* Options: none */
/* Outputs: ao */
int ti_ao_start(TI_REAL const *options);
int ti_ao(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Absolute Price Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: real */
/* Options: short period, long period */
/* Outputs: apo */
int ti_apo_start(TI_REAL const *options);
int ti_apo(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Aroon */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 2 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: aroon_down, aroon_up */
int ti_aroon_start(TI_REAL const *options);
int ti_aroon(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Aroon Oscillator */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: aroonosc */
int ti_aroonosc_start(TI_REAL const *options);
int ti_aroonosc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Arcsine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: asin */
int ti_asin_start(TI_REAL const *options);
int ti_asin(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Arctangent */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: atan */
int ti_atan_start(TI_REAL const *options);
int ti_atan(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Average True Range */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: atr */
int ti_atr_start(TI_REAL const *options);
int ti_atr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Average Price */
/* Type: overlay */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: open, high, low, close */
/* Options: none */
/* Outputs: avgprice */
int ti_avgprice_start(TI_REAL const *options);
int ti_avgprice(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Bollinger Bands */
/* Type: overlay */
/* Input arrays: 1    Options: 2    Output arrays: 3 */
/* Inputs: real */
/* Options: period, stddev */
/* Outputs: bbands_lower, bbands_middle, bbands_upper */
int ti_bbands_start(TI_REAL const *options);
int ti_bbands(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Balance of Power */
/* Type: indicator */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: open, high, low, close */
/* Options: none */
/* Outputs: bop */
int ti_bop_start(TI_REAL const *options);
int ti_bop(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Commodity Channel Index */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: cci */
int ti_cci_start(TI_REAL const *options);
int ti_cci(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Ceiling */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: ceil */
int ti_ceil_start(TI_REAL const *options);
int ti_ceil(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Chande Momentum Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: cmo */
int ti_cmo_start(TI_REAL const *options);
int ti_cmo(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Cosine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: cos */
int ti_cos_start(TI_REAL const *options);
int ti_cos(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Hyperbolic Cosine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: cosh */
int ti_cosh_start(TI_REAL const *options);
int ti_cosh(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Crossany */
/* Type: math */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: real, real */
/* Options: none */
/* Outputs: crossany */
int ti_crossany_start(TI_REAL const *options);
int ti_crossany(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Crossover */
/* Type: math */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: real, real */
/* Options: none */
/* Outputs: crossover */
int ti_crossover_start(TI_REAL const *options);
int ti_crossover(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Chaikins Volatility */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: cvi */
int ti_cvi_start(TI_REAL const *options);
int ti_cvi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Linear Decay */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: decay */
int ti_decay_start(TI_REAL const *options);
int ti_decay(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Double Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: dema */
int ti_dema_start(TI_REAL const *options);
int ti_dema(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Directional Indicator */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: plus_di, minus_di */
int ti_di_start(TI_REAL const *options);
int ti_di(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Division */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: real, real */
/* Options: none */
/* Outputs: div */
int ti_div_start(TI_REAL const *options);
int ti_div(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Directional Movement */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 2 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: plus_dm, minus_dm */
int ti_dm_start(TI_REAL const *options);
int ti_dm(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Detrended Price Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: dpo */
int ti_dpo_start(TI_REAL const *options);
int ti_dpo(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Directional Movement Index */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: dx */
int ti_dx_start(TI_REAL const *options);
int ti_dx(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Exponential Decay */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: edecay */
int ti_edecay_start(TI_REAL const *options);
int ti_edecay(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: ema */
int ti_ema_start(TI_REAL const *options);
int ti_ema(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Ease of Movement */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, volume */
/* Options: none */
/* Outputs: emv */
int ti_emv_start(TI_REAL const *options);
int ti_emv(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Exponential */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: exp */
int ti_exp_start(TI_REAL const *options);
int ti_exp(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Fisher Transform */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 2 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: fisher, fisher_signal */
int ti_fisher_start(TI_REAL const *options);
int ti_fisher(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Floor */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: floor */
int ti_floor_start(TI_REAL const *options);
int ti_floor(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Forecast Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: fosc */
int ti_fosc_start(TI_REAL const *options);
int ti_fosc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Hull Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: hma */
int ti_hma_start(TI_REAL const *options);
int ti_hma(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Kaufman Adaptive Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: kama */
int ti_kama_start(TI_REAL const *options);
int ti_kama(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Klinger Volume Oscillator */
/* Type: indicator */
/* Input arrays: 4    Options: 2    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: short period, long period */
/* Outputs: kvo */
int ti_kvo_start(TI_REAL const *options);
int ti_kvo(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Lag */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: lag */
int ti_lag_start(TI_REAL const *options);
int ti_lag(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Linear Regression */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: linreg */
int ti_linreg_start(TI_REAL const *options);
int ti_linreg(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Linear Regression Intercept */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: linregintercept */
int ti_linregintercept_start(TI_REAL const *options);
int ti_linregintercept(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Linear Regression Slope */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: linregslope */
int ti_linregslope_start(TI_REAL const *options);
int ti_linregslope(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Natural Log */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: ln */
int ti_ln_start(TI_REAL const *options);
int ti_ln(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Base-10 Log */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: log10 */
int ti_log10_start(TI_REAL const *options);
int ti_log10(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Moving Average Convergence/Divergence */
/* Type: indicator */
/* Input arrays: 1    Options: 3    Output arrays: 3 */
/* Inputs: real */
/* Options: short period, long period, signal period */
/* Outputs: macd, macd_signal, macd_histogram */
int ti_macd_start(TI_REAL const *options);
int ti_macd(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Market Facilitation Index */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, volume */
/* Options: none */
/* Outputs: marketfi */
int ti_marketfi_start(TI_REAL const *options);
int ti_marketfi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Mass Index */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: mass */
int ti_mass_start(TI_REAL const *options);
int ti_mass(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Maximum In Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: max */
int ti_max_start(TI_REAL const *options);
int ti_max(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Mean Deviation Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: md */
int ti_md_start(TI_REAL const *options);
int ti_md(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Median Price */
/* Type: overlay */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: high, low */
/* Options: none */
/* Outputs: medprice */
int ti_medprice_start(TI_REAL const *options);
int ti_medprice(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Money Flow Index */
/* Type: indicator */
/* Input arrays: 4    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: period */
/* Outputs: mfi */
int ti_mfi_start(TI_REAL const *options);
int ti_mfi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Minimum In Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: min */
int ti_min_start(TI_REAL const *options);
int ti_min(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Momentum */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: mom */
int ti_mom_start(TI_REAL const *options);
int ti_mom(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Mesa Sine Wave */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 2 */
/* Inputs: real */
/* Options: period */
/* Outputs: msw_sine, msw_lead */
int ti_msw_start(TI_REAL const *options);
int ti_msw(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Multiplication */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: real, real */
/* Options: none */
/* Outputs: mul */
int ti_mul_start(TI_REAL const *options);
int ti_mul(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Normalized Average True Range */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: natr */
int ti_natr_start(TI_REAL const *options);
int ti_natr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Negative Volume Index */
/* Type: indicator */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: close, volume */
/* Options: none */
/* Outputs: nvi */
int ti_nvi_start(TI_REAL const *options);
int ti_nvi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* On Balance Volume */
/* Type: indicator */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: close, volume */
/* Options: none */
/* Outputs: obv */
int ti_obv_start(TI_REAL const *options);
int ti_obv(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Percentage Price Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: real */
/* Options: short period, long period */
/* Outputs: ppo */
int ti_ppo_start(TI_REAL const *options);
int ti_ppo(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Parabolic SAR */
/* Type: overlay */
/* Input arrays: 2    Options: 2    Output arrays: 1 */
/* Inputs: high, low */
/* Options: acceleration factor step, acceleration factor maximum */
/* Outputs: psar */
int ti_psar_start(TI_REAL const *options);
int ti_psar(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Positive Volume Index */
/* Type: indicator */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: close, volume */
/* Options: none */
/* Outputs: pvi */
int ti_pvi_start(TI_REAL const *options);
int ti_pvi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Qstick */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: open, close */
/* Options: period */
/* Outputs: qstick */
int ti_qstick_start(TI_REAL const *options);
int ti_qstick(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Rate of Change */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: roc */
int ti_roc_start(TI_REAL const *options);
int ti_roc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Rate of Change Ratio */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: rocr */
int ti_rocr_start(TI_REAL const *options);
int ti_rocr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Round */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: round */
int ti_round_start(TI_REAL const *options);
int ti_round(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Relative Strength Index */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: rsi */
int ti_rsi_start(TI_REAL const *options);
int ti_rsi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Sine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: sin */
int ti_sin_start(TI_REAL const *options);
int ti_sin(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Hyperbolic Sine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: sinh */
int ti_sinh_start(TI_REAL const *options);
int ti_sinh(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Simple Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: sma */
int ti_sma_start(TI_REAL const *options);
int ti_sma(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Square Root */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: sqrt */
int ti_sqrt_start(TI_REAL const *options);
int ti_sqrt(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Standard Deviation Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: stddev */
int ti_stddev_start(TI_REAL const *options);
int ti_stddev(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Standard Error Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: stderr */
int ti_stderr_start(TI_REAL const *options);
int ti_stderr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Stochastic Oscillator */
/* Type: indicator */
/* Input arrays: 3    Options: 3    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: %k period, %k slowing period, %d period */
/* Outputs: stoch_k, stoch_d */
int ti_stoch_start(TI_REAL const *options);
int ti_stoch(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Stochastic RSI */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: stochrsi */
int ti_stochrsi_start(TI_REAL const *options);
int ti_stochrsi(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Subtraction */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: real, real */
/* Options: none */
/* Outputs: sub */
int ti_sub_start(TI_REAL const *options);
int ti_sub(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Sum Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: sum */
int ti_sum_start(TI_REAL const *options);
int ti_sum(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Tangent */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: tan */
int ti_tan_start(TI_REAL const *options);
int ti_tan(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Hyperbolic Tangent */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: tanh */
int ti_tanh_start(TI_REAL const *options);
int ti_tanh(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Triple Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: tema */
int ti_tema_start(TI_REAL const *options);
int ti_tema(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Degree Conversion */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: degrees */
int ti_todeg_start(TI_REAL const *options);
int ti_todeg(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Radian Conversion */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: radians */
int ti_torad_start(TI_REAL const *options);
int ti_torad(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* True Range */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: tr */
int ti_tr_start(TI_REAL const *options);
int ti_tr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Triangular Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: trima */
int ti_trima_start(TI_REAL const *options);
int ti_trima(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Trix */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: trix */
int ti_trix_start(TI_REAL const *options);
int ti_trix(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vector Truncate */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: trunc */
int ti_trunc_start(TI_REAL const *options);
int ti_trunc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Time Series Forecast */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: tsf */
int ti_tsf_start(TI_REAL const *options);
int ti_tsf(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Typical Price */
/* Type: overlay */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: typprice */
int ti_typprice_start(TI_REAL const *options);
int ti_typprice(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Ultimate Oscillator */
/* Type: indicator */
/* Input arrays: 3    Options: 3    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: short period, medium period, long period */
/* Outputs: ultosc */
int ti_ultosc_start(TI_REAL const *options);
int ti_ultosc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Variance Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: var */
int ti_var_start(TI_REAL const *options);
int ti_var(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Vertical Horizontal Filter */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: vhf */
int ti_vhf_start(TI_REAL const *options);
int ti_vhf(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Variable Index Dynamic Average */
/* Type: overlay */
/* Input arrays: 1    Options: 3    Output arrays: 1 */
/* Inputs: real */
/* Options: short period, long period, alpha */
/* Outputs: vidya */
int ti_vidya_start(TI_REAL const *options);
int ti_vidya(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Annualized Historical Volatility */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: volatility */
int ti_volatility_start(TI_REAL const *options);
int ti_volatility(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Volume Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: volume */
/* Options: short period, long period */
/* Outputs: vosc */
int ti_vosc_start(TI_REAL const *options);
int ti_vosc(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Volume Weighted Moving Average */
/* Type: overlay */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: close, volume */
/* Options: period */
/* Outputs: vwma */
int ti_vwma_start(TI_REAL const *options);
int ti_vwma(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Williams Accumulation/Distribution */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: wad */
int ti_wad_start(TI_REAL const *options);
int ti_wad(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Weighted Close Price */
/* Type: overlay */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: wcprice */
int ti_wcprice_start(TI_REAL const *options);
int ti_wcprice(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Wilders Smoothing */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: wilders */
int ti_wilders_start(TI_REAL const *options);
int ti_wilders(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Williams %R */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: willr */
int ti_willr_start(TI_REAL const *options);
int ti_willr(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Weighted Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: wma */
int ti_wma_start(TI_REAL const *options);
int ti_wma(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);





/* Zero-Lag Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: zlema */
int ti_zlema_start(TI_REAL const *options);
int ti_zlema(int size,
      TI_REAL const *const *inputs,
      TI_REAL const *options,
      TI_REAL *const *outputs);



#ifdef __cplusplus
}
#endif

#endif /*__TI_INDICATORS_H__*/
/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2017 Tulip Charts LLC
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

#ifndef __BUFFER_H__
#define __BUFFER_H__


typedef struct {
    int size, pushes, index;
    TI_REAL sum;
    TI_REAL vals[1];
} ti_buffer;


ti_buffer *ti_buffer_new(int size);
void ti_buffer_free(ti_buffer *buffer);

/* Pushes a new value, plus updates sum. */
#define ti_buffer_push(BUFFER, VAL) \
do { \
    if ((BUFFER)->pushes >= (BUFFER)->size) { \
        (BUFFER)->sum -= (BUFFER)->vals[(BUFFER)->index]; \
    } \
\
    (BUFFER)->sum += (VAL); \
    (BUFFER)->vals[(BUFFER)->index] = (VAL); \
    (BUFFER)->pushes += 1; \
    (BUFFER)->index = ((BUFFER)->index + 1); \
    if ((BUFFER)->index >= (BUFFER)->size) (BUFFER)->index = 0; \
} while (0)


/* Pushes a new value, skips updating sum. */
#define ti_buffer_qpush(BUFFER, VAL) \
do { \
    (BUFFER)->vals[(BUFFER)->index] = (VAL); \
    (BUFFER)->index = ((BUFFER)->index + 1); \
    if ((BUFFER)->index >= (BUFFER)->size) (BUFFER)->index = 0; \
} while (0)


/* With get, 0 = last value pushed, -1 = value before last, etc. */
#define ti_buffer_get(BUFFER, VAL) ((BUFFER)->vals[((BUFFER)->index + (BUFFER)->size - 1 + (VAL)) % (BUFFER)->size])


#endif /*__BUFFER_H__*/
/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2017 Tulip Charts LLC
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


#ifndef __MINMAX_H__
#define __MINMAX_H__


#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


#endif /*__MINMAX_H__*/
int ti_abs_start(TI_REAL const *options) { (void)options; return 0; } int ti_abs(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (fabs(in1[i])); } return TI_OKAY; }
int ti_acos_start(TI_REAL const *options) { (void)options; return 0; } int ti_acos(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (acos(in1[i])); } return TI_OKAY; }
int ti_ad_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_ad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    (void)options;
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < size; ++i) {
        const TI_REAL hl = (high[i] - low[i]);
        if (hl != 0.0) {
            sum += (close[i] - low[i] - high[i] + close[i]) / hl * volume[i];
        }
        output[i] = sum;
    }
    return TI_OKAY;
}
int ti_add_start(TI_REAL const *options) { (void)options; return 0; } int ti_add(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] + in2[i]); } return TI_OKAY; }
int ti_adosc_start(TI_REAL const *options) {
    return (int)(options[1])-1;
}
int ti_adosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const int start = long_period - 1;
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_adosc_start(options)) return TI_OKAY;
    const TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    const TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0, short_ema = 0, long_ema = 0;
    int i;
    for (i = 0; i < size; ++i) {
        const TI_REAL hl = (high[i] - low[i]);
        if (hl != 0.0) {
            sum += (close[i] - low[i] - high[i] + close[i]) / hl * volume[i];
        }
        if (i == 0) {
            short_ema = sum;
            long_ema = sum;
        } else {
            short_ema = (sum-short_ema) * short_per + short_ema;
            long_ema = (sum-long_ema) * long_per + long_ema;
        }
        if (i >= start) {
            *output++ = short_ema - long_ema;
        }
    }
    assert(output - outputs[0] == size - ti_adosc_start(options));
    return TI_OKAY;
}
int ti_adx_start(TI_REAL const *options) {
    return ((int)options[0]-1) * 2;
}
int ti_adx(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 2) return TI_INVALID_OPTION;
    if (size <= ti_adx_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    const TI_REAL invper = 1.0 / ((TI_REAL)period);
    TI_REAL atr = 0;
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr += truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    TI_REAL adx = 0.0;
    {
        TI_REAL di_up = dmup / atr;
        TI_REAL di_down = dmdown / atr;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        adx += dx;
    }
    for (i = period; i < size; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr = atr * per + truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        TI_REAL di_up = dmup / atr;
        TI_REAL di_down = dmdown / atr;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        if (i-period < period-2) {
            adx += dx;
        } else if (i-period == period-2) {
            adx += dx;
            *output++ = adx * invper;
        } else {
            adx = adx * per + dx;
            *output++ = adx * invper;
        }
    }
    assert(output - outputs[0] == size - ti_adx_start(options));
    return TI_OKAY;
}
int ti_adxr_start(TI_REAL const *options) {
    return ((int)options[0]-1) * 3;
}
int ti_adxr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 2) return TI_INVALID_OPTION;
    if (size <= ti_adxr_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    const TI_REAL invper = 1.0 / ((TI_REAL)period);
    TI_REAL atr = 0;
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr += truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    TI_REAL adx = 0.0;
    {
        TI_REAL di_up = dmup / atr;
        TI_REAL di_down = dmdown / atr;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        adx += dx;
    }
    ti_buffer *adxr = ti_buffer_new(period-1);
    const int first_adxr = ti_adxr_start(options);
    for (i = period; i < size; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr = atr * per + truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        TI_REAL di_up = dmup / atr;
        TI_REAL di_down = dmdown / atr;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        if (i-period < period-2) {
            adx += dx;
        } else if (i-period == period-2) {
            adx += dx;
            ti_buffer_qpush(adxr, adx * invper);
        } else {
            adx = adx * per + dx;
            if (i >= first_adxr) {
                *output++ = 0.5 * (adx * invper + ti_buffer_get(adxr, 1));
            }
            ti_buffer_qpush(adxr, adx * invper);
        }
    }
    ti_buffer_free(adxr);
    assert(output - outputs[0] == size - ti_adxr_start(options));
    return TI_OKAY;
}
int ti_ao_start(TI_REAL const *options) {
    (void)options;
    return 33;
}
int ti_ao(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = 34;
    TI_REAL *output = outputs[0];
    if (size <= ti_ao_start(options)) return TI_OKAY;
    TI_REAL sum34 = 0;
    TI_REAL sum5 = 0;
    const TI_REAL per34 = 1.0 / 34.0;
    const TI_REAL per5 = 1.0 / 5.0;
    int i;
    for (i = 0; i < 34; ++i) {
        TI_REAL hl = 0.5 * (high[i] + low[i]);
        sum34 += hl;
        if (i >= 29) sum5 += hl;
    }
    *output++ = (per5 * sum5 - per34 * sum34);
    for (i = period; i < size; ++i) {
        TI_REAL hl = 0.5 * (high[i] + low[i]);
        sum34 += hl;
        sum5 += hl;
        sum34 -= 0.5 * (high[i-34] + low[i-34]);
        sum5 -= 0.5 * (high[i-5] + low[i-5]);
        *output++ = (per5 * sum5 - per34 * sum34);
    }
    assert(output - outputs[0] == size - ti_ao_start(options));
    return TI_OKAY;
}
int ti_apo_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_apo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *apo = outputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_apo_start(options)) return TI_OKAY;
    TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL short_ema = input[0];
    TI_REAL long_ema = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        short_ema = (input[i]-short_ema) * short_per + short_ema;
        long_ema = (input[i]-long_ema) * long_per + long_ema;
        const TI_REAL out = short_ema - long_ema;
        *apo++ = out;
    }
    assert(apo - outputs[0] == size - ti_apo_start(options));
    return TI_OKAY;
}
int ti_aroon_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_aroon(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    TI_REAL *adown = outputs[0];
    TI_REAL *aup = outputs[1];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_aroon_start(options)) return TI_OKAY;
    const TI_REAL scale = 100.0 / period;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    TI_REAL bar;
    int i, j;
    for (i = period; i < size; ++i, ++trail) {
        bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *adown++ = ((TI_REAL)period - (i-mini)) * scale;
        *aup++ = ((TI_REAL)period - (i-maxi)) * scale;
    }
    assert(adown - outputs[0] == size - ti_aroon_start(options));
    assert(aup - outputs[1] == size - ti_aroon_start(options));
    return TI_OKAY;
}
int ti_aroonosc_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_aroonosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_aroon_start(options)) return TI_OKAY;
    const TI_REAL scale = 100.0 / period;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    int i, j;
    for (i = period; i < size; ++i, ++trail) {
        TI_REAL bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *output++ = (maxi-mini) * scale;
    }
    assert(output - outputs[0] == size - ti_aroonosc_start(options));
    return TI_OKAY;
}
int ti_asin_start(TI_REAL const *options) { (void)options; return 0; } int ti_asin(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (asin(in1[i])); } return TI_OKAY; }
int ti_atan_start(TI_REAL const *options) { (void)options; return 0; } int ti_atan(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (atan(in1[i])); } return TI_OKAY; }
int ti_atr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_atr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_atr_start(options)) return TI_OKAY;
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    TI_REAL sum = 0;
    TI_REAL truerange;
    sum += high[0] - low[0];
    int i;
    for (i = 1; i < period; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        sum += truerange;
    }
    TI_REAL val = sum / period;
    *output++ = val;
    for (i = period; i < size; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        val = (truerange-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_atr_start(options));
    return TI_OKAY;
}
int ti_avgprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_avgprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *open = inputs[0];
    const TI_REAL *high = inputs[1];
    const TI_REAL *low = inputs[2];
    const TI_REAL *close = inputs[3];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (open[i] + high[i] + low[i] + close[i]) * 0.25;
    }
    return TI_OKAY;
}
int ti_bbands_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_bbands(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *lower = outputs[0];
    TI_REAL *middle = outputs[1];
    TI_REAL *upper = outputs[2];
    const int period = (int)options[0];
    const TI_REAL stddev = options[1];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_bbands_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    TI_REAL sd = sqrt(sum2 * scale - (sum * scale) * (sum * scale));
    *middle = sum * scale;
    *lower++ = *middle - stddev * sd;
    *upper++ = *middle + stddev * sd;
    ++middle;
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        sd = sqrt(sum2 * scale - (sum * scale) * (sum * scale));
        *middle = sum * scale;
        *upper++ = *middle + stddev * sd;
        *lower++ = *middle - stddev * sd;
        ++middle;
    }
    assert(lower - outputs[0] == size - ti_bbands_start(options));
    assert(middle - outputs[1] == size - ti_bbands_start(options));
    assert(upper - outputs[2] == size - ti_bbands_start(options));
    return TI_OKAY;
}
int ti_bop_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_bop(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *open = inputs[0];
    const TI_REAL *high = inputs[1];
    const TI_REAL *low = inputs[2];
    const TI_REAL *close = inputs[3];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        TI_REAL hl = high[i] - low[i];
        if (hl <= 0.0) {
            output[i] = 0;
        } else {
            output[i] = (close[i] - open[i]) / hl;
        }
    }
    return TI_OKAY;
}
int ti_cci_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return (period-1) * 2;
}
int ti_cci(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_cci_start(options)) return TI_OKAY;
    TI_REAL *output = outputs[0];
    ti_buffer *sum = ti_buffer_new(period);
    int i, j;
    for (i = 0; i < size; ++i) {
        const TI_REAL today = ((high[(i)] + low[(i)] + close[(i)]) * (1.0/3.0));
        ti_buffer_push(sum, today);
        const TI_REAL avg = sum->sum * scale;
        if (i >= period * 2 - 2) {
            TI_REAL acc = 0;
            for (j = 0; j < period; ++j) {
                acc += fabs(avg - sum->vals[j]);
            }
            TI_REAL cci = acc * scale;
            cci *= .015;
            cci = (today-avg)/cci;
            *output++ = cci;
        }
    }
    ti_buffer_free(sum);
    assert(output - outputs[0] == size - ti_cci_start(options));
    return TI_OKAY;
}
int ti_ceil_start(TI_REAL const *options) { (void)options; return 0; } int ti_ceil(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (ceil(in1[i])); } return TI_OKAY; }
int ti_cmo_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_cmo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_cmo_start(options)) return TI_OKAY;
    TI_REAL up_sum = 0, down_sum = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        up_sum += (input[(i)] > input[(i)-1] ? input[(i)] - input[(i)-1] : 0);
        down_sum += (input[(i)] < input[(i)-1] ? input[(i)-1] - input[(i)] : 0);
    }
    *output++ = 100 * (up_sum - down_sum) / (up_sum + down_sum);
    for (i = period+1; i < size; ++i) {
        up_sum -= (input[(i-period)] > input[(i-period)-1] ? input[(i-period)] - input[(i-period)-1] : 0);
        down_sum -= (input[(i-period)] < input[(i-period)-1] ? input[(i-period)-1] - input[(i-period)] : 0);
        up_sum += (input[(i)] > input[(i)-1] ? input[(i)] - input[(i)-1] : 0);
        down_sum += (input[(i)] < input[(i)-1] ? input[(i)-1] - input[(i)] : 0);
        *output++ = 100 * (up_sum - down_sum) / (up_sum + down_sum);
    }
    assert(output - outputs[0] == size - ti_cmo_start(options));
    return TI_OKAY;
}
int ti_cos_start(TI_REAL const *options) { (void)options; return 0; } int ti_cos(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (cos(in1[i])); } return TI_OKAY; }
int ti_cosh_start(TI_REAL const *options) { (void)options; return 0; } int ti_cosh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (cosh(in1[i])); } return TI_OKAY; }
int ti_crossany_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_crossany(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *a = inputs[0];
    const TI_REAL *b = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 1; i < size; ++i) {
        *output++ = (a[i] > b[i] && a[i-1] <= b[i-1])
                 || (a[i] < b[i] && a[i-1] >= b[i-1]);
    }
    return TI_OKAY;
}
int ti_crossover_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_crossover(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *a = inputs[0];
    const TI_REAL *b = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 1; i < size; ++i) {
        *output++ = a[i] > b[i] && a[i-1] <= b[i-1];
    }
    return TI_OKAY;
}
int ti_cvi_start(TI_REAL const *options) {
    const int n = (int)options[0];
    return n*2-1;
}
int ti_cvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_cvi_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    ti_buffer *lag = ti_buffer_new(period);
    TI_REAL val = high[0]-low[0];
    int i;
    for (i = 1; i < period*2-1; ++i) {
        val = ((high[i]-low[i])-val) * per + val;
        ti_buffer_qpush(lag, val);
    }
    for (i = period*2-1; i < size; ++i) {
        val = ((high[i]-low[i])-val) * per + val;
        const TI_REAL old = lag->vals[lag->index];
        *output++ = 100.0 * (val - old) / old;
        ti_buffer_qpush(lag, val);
    }
    ti_buffer_free(lag);
    assert(output - outputs[0] == size - ti_cvi_start(options));
    return TI_OKAY;
}
int ti_decay_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_decay(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    *output++ = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        TI_REAL d = output[-1] - scale;
        *output++ = input[i] > d ? input[i] : d;
    }
    return TI_OKAY;
}
int ti_dema_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return (period-1) * 2;
}
int ti_dema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    const TI_REAL per1 = 1.0 - per;
    TI_REAL ema = input[0];
    TI_REAL ema2 = ema;
    int i;
    for (i = 0; i < size; ++i) {
        ema = ema * per1 + input[i] * per;
        if (i == period-1) {
            ema2 = ema;
        }
        if (i >= period-1) {
            ema2 = ema2 * per1 + ema * per;
            if (i >= (period-1) * 2) {
                *output = ema * 2 - ema2;
                ++output;
            }
        }
    }
    assert(output - outputs[0] == size - ti_dema_start(options));
    return TI_OKAY;
}
int ti_di_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_di(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *plus_di = outputs[0];
    TI_REAL *minus_di = outputs[1];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_di_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    TI_REAL atr = 0;
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr += truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    *plus_di++ = 100.0 * dmup / atr;
    *minus_di++ = 100.0 * dmdown / atr;
    for (i = period; i < size; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr = atr * per + truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        *plus_di++ = 100.0 * dmup / atr;
        *minus_di++ = 100.0 * dmdown / atr;
    }
    assert(plus_di - outputs[0] == size - ti_di_start(options));
    assert(minus_di - outputs[1] == size - ti_di_start(options));
    return TI_OKAY;
}
int ti_div_start(TI_REAL const *options) { (void)options; return 0; } int ti_div(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] / in2[i]); } return TI_OKAY; }
int ti_dm_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_dm(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *plus_dm = outputs[0];
    TI_REAL *minus_dm = outputs[1];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dm_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    *plus_dm++ = dmup;
    *minus_dm++ = dmdown;
    for (i = period; i < size; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        *plus_dm++ = dmup;
        *minus_dm++ = dmdown;
    }
    assert(plus_dm - outputs[0] == size - ti_dm_start(options));
    assert(minus_dm - outputs[1] == size - ti_dm_start(options));
    return TI_OKAY;
}
int ti_dpo_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_dpo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    const int back = period / 2 + 1;
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dpo_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    *output++ = input[period-1-back] - (sum * scale);
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum -= input[i-period];
        *output++ = input[i-back] - (sum * scale);
    }
    assert(output - outputs[0] == size - ti_dpo_start(options));
    return TI_OKAY;
}
int ti_dx_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_dx(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dx_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    TI_REAL atr = 0;
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr += truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    {
        TI_REAL di_up = dmup / atr;
        TI_REAL di_down = dmdown / atr;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        *output++ = dx;
    }
    for (i = period; i < size; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr = atr * per + truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        TI_REAL di_up = dmup / atr;
        TI_REAL di_down = dmdown / atr;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        *output++ = dx;
    }
    assert(output - outputs[0] == size - ti_dx_start(options));
    return TI_OKAY;
}
int ti_edecay_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_edecay(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 - 1.0 / period;
    *output++ = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        TI_REAL d = output[-1] * scale;
        *output++ = input[i] > d ? input[i] : d;
    }
    return TI_OKAY;
}
int ti_ema_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_ema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_ema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    TI_REAL val = input[0];
    *output++ = val;
    int i;
    for (i = 1; i < size; ++i) {
        val = (input[i]-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_ema_start(options));
    return TI_OKAY;
}
int ti_emv_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_emv(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *volume = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_emv_start(options)) return TI_OKAY;
    TI_REAL last = (high[0] + low[0]) * 0.5;
    int i;
    for (i = 1; i < size; ++i) {
        TI_REAL hl = (high[i] + low[i]) * 0.5;
        TI_REAL br = volume[i] / 10000.0 / (high[i] - low[i]);
        *output++ = (hl - last) / br;
        last = hl;
    }
    assert(output - outputs[0] == size - ti_emv_start(options));
    return TI_OKAY;
}
int ti_exp_start(TI_REAL const *options) { (void)options; return 0; } int ti_exp(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (exp(in1[i])); } return TI_OKAY; }
int ti_fisher_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_fisher(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    TI_REAL *fisher = outputs[0];
    TI_REAL *signal = outputs[1];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_fisher_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = (0.5 * (high[(0)] + low[(0)]));
    TI_REAL min = (0.5 * (high[(0)] + low[(0)]));
    TI_REAL val1 = 0.0;
    TI_REAL bar;
    TI_REAL fish = 0.0;
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        bar = (0.5 * (high[(i)] + low[(i)]));
        if (maxi < trail) {
            maxi = trail;
            max = (0.5 * (high[(maxi)] + low[(maxi)]));
            j = trail;
            while(++j <= i) {
                bar = (0.5 * (high[(j)] + low[(j)]));
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = (0.5 * (high[(i)] + low[(i)]));
        if (mini < trail) {
            mini = trail;
            min = (0.5 * (high[(mini)] + low[(mini)]));
            j = trail;
            while(++j <= i) {
                bar = (0.5 * (high[(j)] + low[(j)]));
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        TI_REAL mm = max - min;
        if (mm == 0.0) mm = 0.001;
        val1 = 0.33 * 2.0 * ( ((0.5 * (high[(i)] + low[(i)]))-min) / (mm) - 0.5) + 0.67 * val1;
        if (val1 > 0.99) val1 = .999;
        if (val1 < -0.99) val1 = -.999;
        *signal++ = fish;
        fish = 0.5 * log((1.0+val1)/(1.0-val1)) + 0.5 * fish;
        *fisher++ = fish;
    }
    assert(fisher - outputs[0] == size - ti_fisher_start(options));
    assert(signal - outputs[1] == size - ti_fisher_start(options));
    return TI_OKAY;
}
int ti_floor_start(TI_REAL const *options) { (void)options; return 0; } int ti_floor(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (floor(in1[i])); } return TI_OKAY; }
int ti_fosc_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_fosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_fosc_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); TI_REAL tsf = 0;; int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; if (i >= (period)) {*output++ = 100 * (input[i] - tsf) / input[i];} tsf = (a + b * ((period+1))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_fosc_start(options));
    return TI_OKAY;
}
int ti_hma_start(TI_REAL const *options) {
    const int period = (int)options[0];
    const int periodsqrt = (int)(sqrt(period));
    return period + periodsqrt - 2;
}
int ti_hma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_hma_start(options)) return TI_OKAY;
    const int period2 = (int)(period / 2);
    const int periodsqrt = (int)(sqrt(period));
    const TI_REAL weights = period * (period+1) / 2;
    const TI_REAL weights2 = period2 * (period2+1) / 2;
    const TI_REAL weightssqrt = periodsqrt * (periodsqrt+1) / 2;
    TI_REAL sum = 0;
    TI_REAL weight_sum = 0;
    TI_REAL sum2 = 0;
    TI_REAL weight_sum2 = 0;
    TI_REAL sumsqrt = 0;
    TI_REAL weight_sumsqrt = 0;
    int i;
    for (i = 0; i < period-1; ++i) {
        weight_sum += input[i] * (i+1);
        sum += input[i];
        if (i >= period - period2) {
            weight_sum2 += input[i] * (i+1-(period-period2));
            sum2 += input[i];
        }
    }
    ti_buffer *buff = ti_buffer_new(periodsqrt);
    for (i = period-1; i < size; ++i) {
        weight_sum += input[i] * period;
        sum += input[i];
        weight_sum2 += input[i] * period2;
        sum2 += input[i];
        const TI_REAL wma = weight_sum / weights;
        const TI_REAL wma2 = weight_sum2 / weights2;
        const TI_REAL diff = 2 * wma2 - wma;
        weight_sumsqrt += diff * periodsqrt;
        sumsqrt += diff;
        ti_buffer_qpush(buff, diff);
        if (i >= (period-1) + (periodsqrt-1)) {
            *output++ = weight_sumsqrt / weightssqrt;
            weight_sumsqrt -= sumsqrt;
            sumsqrt -= ti_buffer_get(buff, 1);
        } else {
            weight_sumsqrt -= sumsqrt;
        }
        weight_sum -= sum;
        sum -= input[i-period+1];
        weight_sum2 -= sum2;
        sum2 -= input[i-period2+1];
    }
    ti_buffer_free(buff);
    assert(output - outputs[0] == size - ti_hma_start(options));
    return TI_OKAY;
}
int ti_kama_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_kama(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_kama_start(options)) return TI_OKAY;
    const TI_REAL short_per = 2 / (2.0 + 1);
    const TI_REAL long_per = 2 / (30.0 + 1);
    TI_REAL sum = 0;
    int i;
    for (i = 1; i < period; ++i) {
        sum += fabs(input[i] - input[i-1]);
    }
    TI_REAL kama = input[period-1];
    *output++ = kama;
    TI_REAL er, sc;
    for (i = period; i < size; ++i) {
        sum += fabs(input[i] - input[i-1]);
        if (i > period) {
            sum -= fabs(input[i-period] - input[i-period-1]);
        }
        if (sum != 0.0) {
            er = fabs(input[i] - input[i-period]) / sum;
        } else {
            er = 1.0;
        }
        sc = pow(er * (short_per - long_per) + long_per, 2);
        kama = kama + sc * (input[i] - kama);
        *output++ = kama;
    }
    assert(output - outputs[0] == size - ti_kama_start(options));
    return TI_OKAY;
}
int ti_kvo_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_kvo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_kvo_start(options)) return TI_OKAY;
    const TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    const TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL *output = outputs[0];
    TI_REAL cm = 0;
    TI_REAL prev_hlc = high[0] + low[0] + close[0];
    int trend = -1;
    TI_REAL short_ema = 0, long_ema = 0;
    int i;
    for (i = 1; i < size; ++i) {
        const TI_REAL hlc = high[i] + low[i] + close[i];
        const TI_REAL dm = high[i] - low[i];
        if (hlc > prev_hlc && trend != 1) {
            trend = 1;
            cm = high[i-1] - low[i-1];
        } else if (hlc < prev_hlc && trend != 0) {
            trend = 0;
            cm = high[i-1] - low[i-1];
        }
        cm += dm;
        const TI_REAL vf = volume[i] * fabs(dm / cm * 2 - 1) * 100 * (trend ? 1.0 : -1.0);
        if (i == 1) {
            short_ema = vf;
            long_ema = vf;
        } else {
            short_ema = (vf-short_ema) * short_per + short_ema;
            long_ema = (vf-long_ema) * long_per + long_ema;
        }
        *output++ = short_ema - long_ema;
        prev_hlc = hlc;
    }
    assert(output - outputs[0] == size - ti_kvo_start(options));
    return TI_OKAY;
}
int ti_lag_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_lag(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 0) return TI_INVALID_OPTION;
    if (size <= ti_lag_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = input[i-period];
    }
    assert(output - outputs[0] == size - ti_lag_start(options));
    return TI_OKAY;
}
int ti_linreg_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_linreg(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_linreg_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; *output++ = (a + b * ((period))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_linreg_start(options));
    return TI_OKAY;
}
int ti_linregintercept_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_linregintercept(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_linregintercept_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; *output++ = (a + b * ((1))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_linregintercept_start(options));
    return TI_OKAY;
}
int ti_linregslope_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_linregslope(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_linregslope_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; do{}while(0); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { *output++ = b; } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_linregslope_start(options));
    return TI_OKAY;
}
int ti_ln_start(TI_REAL const *options) { (void)options; return 0; } int ti_ln(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (log(in1[i])); } return TI_OKAY; }
int ti_log10_start(TI_REAL const *options) { (void)options; return 0; } int ti_log10(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (log10(in1[i])); } return TI_OKAY; }
int ti_macd_start(TI_REAL const *options) {
    const int long_period = (int)options[1];
    return (long_period-1);
}
int ti_macd(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *macd = outputs[0];
    TI_REAL *signal = outputs[1];
    TI_REAL *hist = outputs[2];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const int signal_period = (int)options[2];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (signal_period < 1) return TI_INVALID_OPTION;
    if (size <= ti_macd_start(options)) return TI_OKAY;
    TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL signal_per = 2 / ((TI_REAL)signal_period + 1);
    if (short_period == 12 && long_period == 26) {
        short_per = 0.15;
        long_per = 0.075;
    }
    TI_REAL short_ema = input[0];
    TI_REAL long_ema = input[0];
    TI_REAL signal_ema = 0;
    int i;
    for (i = 1; i < size; ++i) {
        short_ema = (input[i]-short_ema) * short_per + short_ema;
        long_ema = (input[i]-long_ema) * long_per + long_ema;
        const TI_REAL out = short_ema - long_ema;
        if (i == long_period-1) {
            signal_ema = out;
        }
        if (i >= long_period-1) {
            signal_ema = (out-signal_ema) * signal_per + signal_ema;
            *macd++ = out;
            *signal++ = signal_ema;
            *hist++ = out - signal_ema;
        }
    }
    assert(macd - outputs[0] == size - ti_macd_start(options));
    assert(signal - outputs[1] == size - ti_macd_start(options));
    assert(hist - outputs[2] == size - ti_macd_start(options));
    return TI_OKAY;
}
int ti_marketfi_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_marketfi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *volume = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_marketfi_start(options)) return TI_OKAY;
    int i;
    for (i = 0; i < size; ++i) {
        *output++ = (high[i] - low[i]) / volume[i];
    }
    assert(output - outputs[0] == size - ti_marketfi_start(options));
    return TI_OKAY;
}
int ti_mass_start(TI_REAL const *options) {
    int sum_p = (int)options[0]-1;
    return 16 + sum_p;
}
int ti_mass(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_mass_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / (9.0 + 1);
    const TI_REAL per1 = 1.0 - per;
    TI_REAL ema = high[0] - low[0];
    TI_REAL ema2 = ema;
    ti_buffer *sum = ti_buffer_new(period);
    int i;
    for (i = 0; i < size; ++i) {
        TI_REAL hl = high[i] - low[i];
        ema = ema * per1 + hl * per;
        if (i == 8) {
            ema2 = ema;
        }
        if (i >= 8) {
            ema2 = ema2 * per1 + ema * per;
            if (i >= 16) {
                ti_buffer_push(sum, ema/ema2);
                if (i >= 16 + period - 1) {
                    *output++ = sum->sum;
                }
            }
        }
    }
    ti_buffer_free(sum);
    assert(output - outputs[0] == size - ti_mass_start(options));
    return TI_OKAY;
}
int ti_max_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_max(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_max_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1;
    TI_REAL max = input[0];
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        TI_REAL bar = input[i];
        if (maxi < trail) {
            maxi = trail;
            max = input[maxi];
            j = trail;
            while(++j <= i) {
                bar = input[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        *output++ = max;
    }
    assert(output - outputs[0] == size - ti_max_start(options));
    return TI_OKAY;
}
int ti_md_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_md(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_md_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i, j;
    for (i = 0; i < size; ++i) {
        const TI_REAL today = input[i];
        sum += today;
        if (i >= period) sum -= input[i-period];
        const TI_REAL avg = sum * scale;
        if (i >= period - 1) {
            TI_REAL acc = 0;
            for (j = 0; j < period; ++j) {
                acc += fabs(avg - input[i-j]);
            }
            *output++ = acc * scale;
        }
    }
    assert(output - outputs[0] == size - ti_md_start(options));
    return TI_OKAY;
}
int ti_medprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_medprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (high[i] + low[i]) * 0.5;
    }
    return TI_OKAY;
}
int ti_mfi_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_mfi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_mfi_start(options)) return TI_OKAY;
    TI_REAL *output = outputs[0];
    TI_REAL ytyp = ((high[(0)] + low[(0)] + close[(0)]) * (1.0/3.0));
    int i;
    ti_buffer *up = ti_buffer_new(period);
    ti_buffer *down = ti_buffer_new(period);
    for (i = 1; i < size; ++i) {
        const TI_REAL typ = ((high[(i)] + low[(i)] + close[(i)]) * (1.0/3.0));
        const TI_REAL bar = typ * volume[i];
        if (typ > ytyp) {
            ti_buffer_push(up, bar);
            ti_buffer_push(down, 0.0);
        } else if (typ < ytyp) {
            ti_buffer_push(down, bar);
            ti_buffer_push(up, 0.0);
        } else {
            ti_buffer_push(up, 0.0);
            ti_buffer_push(down, 0.0);
        }
        ytyp = typ;
        if (i >= period) {
            *output++ = up->sum / (up->sum + down->sum) * 100.0;
        }
    }
    ti_buffer_free(up);
    ti_buffer_free(down);
    assert(output - outputs[0] == size - ti_mfi_start(options));
    return TI_OKAY;
}
int ti_min_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_min(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_min_start(options)) return TI_OKAY;
    int trail = 0, mini = -1;
    TI_REAL min = input[0];
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        TI_REAL bar = input[i];
        if (mini < trail) {
            mini = trail;
            min = input[mini];
            j = trail;
            while(++j <= i) {
                bar = input[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *output++ = min;
    }
    assert(output - outputs[0] == size - ti_min_start(options));
    return TI_OKAY;
}
int ti_mom_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_mom(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_mom_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = input[i] - input[i-period];
    }
    assert(output - outputs[0] == size - ti_mom_start(options));
    return TI_OKAY;
}
int ti_msw_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_msw(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *sine = outputs[0];
    TI_REAL *lead = outputs[1];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_msw_start(options)) return TI_OKAY;
    const TI_REAL pi = 3.1415926;
    const TI_REAL tpi = 2 * pi;
    TI_REAL weight = 0, phase;
    TI_REAL rp, ip;
    int i, j;
    for (i = period; i < size; ++i) {
        rp = 0;
        ip = 0;
        for (j = 0; j < period; ++j) {
            weight = input[i-j];
            rp = rp + cos(tpi * j / period) * weight;
            ip = ip + sin(tpi * j / period) * weight;
        }
        if (fabs(rp) > .001) {
            phase = atan(ip/rp);
        } else {
            phase = tpi / 2.0 * (ip < 0 ? -1.0 : 1.0);
        }
        if (rp < 0.0) phase += pi;
        phase += pi/2.0;
        if (phase < 0.0) phase += tpi;
        if (phase > tpi) phase -= tpi;
        *sine++ = sin(phase);
        *lead++ = sin(phase + pi/4.0);
    }
    assert(sine - outputs[0] == size - ti_msw_start(options));
    assert(lead - outputs[1] == size - ti_msw_start(options));
    return TI_OKAY;
}
int ti_mul_start(TI_REAL const *options) { (void)options; return 0; } int ti_mul(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] * in2[i]); } return TI_OKAY; }
int ti_natr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_natr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_natr_start(options)) return TI_OKAY;
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    TI_REAL sum = 0;
    TI_REAL truerange;
    sum += high[0] - low[0];
    int i;
    for (i = 1; i < period; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        sum += truerange;
    }
    TI_REAL val = sum / period;
    *output++ = 100 * (val) / close[period-1];
    for (i = period; i < size; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        val = (truerange-val) * per + val;
        *output++ = 100 * (val) / close[i];
    }
    assert(output - outputs[0] == size - ti_natr_start(options));
    return TI_OKAY;
}
int ti_nvi_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_nvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *close = inputs[0];
    const TI_REAL *volume = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_nvi_start(options)) return TI_OKAY;
    TI_REAL nvi = 1000;
    *output++ = nvi;
    int i;
    for (i = 1; i < size; ++i) {
        if (volume[i] < volume[i-1]) {
            nvi += ((close[i] - close[i-1])/close[i-1]) * nvi;
        }
        *output++ = nvi;
    }
    assert(output - outputs[0] == size - ti_nvi_start(options));
    return TI_OKAY;
}
int ti_obv_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_obv(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *close = inputs[0];
    const TI_REAL *volume = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0;
    *output++ = sum;
    TI_REAL prev = close[0];
    int i;
    for (i = 1; i < size; ++i) {
        if (close[i] > prev) {
            sum += volume[i];
        } else if (close[i] < prev) {
            sum -= volume[i];
        } else {
        }
        prev = close[i];
        *output++ = sum;
    }
    return TI_OKAY;
}
int ti_ppo_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_ppo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *ppo = outputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_ppo_start(options)) return TI_OKAY;
    TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL short_ema = input[0];
    TI_REAL long_ema = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        short_ema = (input[i]-short_ema) * short_per + short_ema;
        long_ema = (input[i]-long_ema) * long_per + long_ema;
        const TI_REAL out = 100.0 * (short_ema - long_ema) / long_ema;
        *ppo++ = out;
    }
    assert(ppo - outputs[0] == size - ti_ppo_start(options));
    return TI_OKAY;
}
int ti_psar_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_psar(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL accel_step = options[0];
    const TI_REAL accel_max = options[1];
    TI_REAL *output = outputs[0];
    if (accel_step <= 0) return TI_INVALID_OPTION;
    if (accel_max <= accel_step) return TI_INVALID_OPTION;
    if (size < 2) return TI_OKAY;
    int lng;
    if (high[0] + low[0] <= high[1] + low[1])
        lng = 1;
    else
        lng = 0;
    TI_REAL sar, extreme;
    if (lng) {
        extreme = high[0];
        sar = low[0];
    } else {
        extreme = low[0];
        sar = high[0];
    }
    TI_REAL accel = accel_step;
    int i;
    for (i = 1; i < size; ++i) {
        sar = (extreme - sar) * accel + sar;
        if (lng) {
            if (i >= 2 && (sar > low[i-2])) sar = low[i-2];
            if ((sar > low[i-1])) sar = low[i-1];
            if (accel < accel_max && high[i] > extreme) {
                accel += accel_step;
                if (accel > accel_max) accel = accel_max;
            }
            if (high[i] > extreme) extreme = high[i];
        } else {
            if (i >= 2 && (sar < high[i-2])) sar = high[i-2];
            if ((sar < high[i-1])) sar = high[i-1];
            if (accel < accel_max && low[i] < extreme) {
                accel += accel_step;
                if (accel > accel_max) accel = accel_max;
            }
            if (low[i] < extreme) extreme = low[i];
        }
        if ((lng && low[i] < sar) || (!lng && high[i] > sar)) {
            accel = accel_step;
            sar = extreme;
            lng = !lng;
            if (!lng) extreme = low[i];
            else extreme = high[i];
        }
        *output++ = sar;
    }
    assert(output - outputs[0] == size - ti_psar_start(options));
    return TI_OKAY;
}
int ti_pvi_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_pvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *close = inputs[0];
    const TI_REAL *volume = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_pvi_start(options)) return TI_OKAY;
    TI_REAL pvi = 1000;
    *output++ = pvi;
    int i;
    for (i = 1; i < size; ++i) {
        if (volume[i] > volume[i-1]) {
            pvi += ((close[i] - close[i-1])/close[i-1]) * pvi;
        }
        *output++ = pvi;
    }
    assert(output - outputs[0] == size - ti_pvi_start(options));
    return TI_OKAY;
}
int ti_qstick_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_qstick(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *open = inputs[0];
    const TI_REAL *close = inputs[1];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_qstick_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += close[i] - open[i];
    }
    *output++ = sum * scale;
    for (i = period; i < size; ++i) {
        sum += close[i] - open[i];
        sum -= close[i-period] - open[i-period];
        *output++ = sum * scale;
    }
    assert(output - outputs[0] == size - ti_qstick_start(options));
    return TI_OKAY;
}
int ti_roc_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_roc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_roc_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = (input[i] - input[i-period]) / input[i-period];
    }
    assert(output - outputs[0] == size - ti_roc_start(options));
    return TI_OKAY;
}
int ti_rocr_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_rocr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_rocr_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = input[i] / input[i-period];
    }
    assert(output - outputs[0] == size - ti_rocr_start(options));
    return TI_OKAY;
}
int ti_round_start(TI_REAL const *options) { (void)options; return 0; } int ti_round(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (floor(in1[i] + 0.5)); } return TI_OKAY; }
int ti_rsi_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_rsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_rsi_start(options)) return TI_OKAY;
    TI_REAL smooth_up = 0, smooth_down = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up += upward;
        smooth_down += downward;
    }
    smooth_up /= period;
    smooth_down /= period;
    *output++ = 100.0 * (smooth_up / (smooth_up + smooth_down));
    for (i = period+1; i < size; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up = (upward-smooth_up) * per + smooth_up;
        smooth_down = (downward-smooth_down) * per + smooth_down;
        *output++ = 100.0 * (smooth_up / (smooth_up + smooth_down));
    }
    assert(output - outputs[0] == size - ti_rsi_start(options));
    return TI_OKAY;
}
int ti_sin_start(TI_REAL const *options) { (void)options; return 0; } int ti_sin(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (sin(in1[i])); } return TI_OKAY; }
int ti_sinh_start(TI_REAL const *options) { (void)options; return 0; } int ti_sinh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (sinh(in1[i])); } return TI_OKAY; }
int ti_sma_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_sma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_sma_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    *output++ = sum * scale;
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum -= input[i-period];
        *output++ = sum * scale;
    }
    assert(output - outputs[0] == size - ti_sma_start(options));
    return TI_OKAY;
}
int ti_sqrt_start(TI_REAL const *options) { (void)options; return 0; } int ti_sqrt(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (sqrt(in1[i])); } return TI_OKAY; }
int ti_stddev_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_stddev(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_stddev_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    {
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = s2s2;
    }
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = s2s2;
    }
    assert(output - outputs[0] == size - ti_stddev_start(options));
    return TI_OKAY;
}
int ti_stderr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_stderr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_stderr_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    const TI_REAL mul = 1.0 / sqrt(period);
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    {
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = mul * s2s2;
    }
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = mul * s2s2;
    }
    assert(output - outputs[0] == size - ti_stderr_start(options));
    return TI_OKAY;
}
int ti_stoch_start(TI_REAL const *options) {
    const int kperiod = (int)options[0];
    const int kslow = (int)options[1];
    const int dperiod = (int)options[2];
    return kperiod + kslow + dperiod - 3;
}
int ti_stoch(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int kperiod = (int)options[0];
    const int kslow = (int)options[1];
    const int dperiod = (int)options[2];
    const TI_REAL kper = 1.0 / kslow;
    const TI_REAL dper = 1.0 / dperiod;
    TI_REAL *stoch = outputs[0];
    TI_REAL *stoch_ma = outputs[1];
    if (kperiod < 1) return TI_INVALID_OPTION;
    if (kslow < 1) return TI_INVALID_OPTION;
    if (dperiod < 1) return TI_INVALID_OPTION;
    if (size <= ti_stoch_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    TI_REAL bar;
    ti_buffer *k_sum = ti_buffer_new(kslow);
    ti_buffer *d_sum = ti_buffer_new(dperiod);
    int i, j;
    for (i = 0; i < size; ++i) {
        if (i >= kperiod) ++trail;
        bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        const TI_REAL kdiff = (max - min);
        const TI_REAL kfast = kdiff == 0.0 ? 0.0 : 100 * ((close[i] - min) / kdiff);
        ti_buffer_push(k_sum, kfast);
        if (i >= kperiod-1 + kslow-1) {
            const TI_REAL k = k_sum->sum * kper;
            ti_buffer_push(d_sum, k);
            if (i >= kperiod-1 + kslow-1 + dperiod-1) {
                *stoch++ = k;
                *stoch_ma++ = d_sum->sum * dper;
            }
        }
    }
    ti_buffer_free(k_sum);
    ti_buffer_free(d_sum);
    assert(stoch - outputs[0] == size - ti_stoch_start(options));
    assert(stoch_ma - outputs[1] == size - ti_stoch_start(options));
    return TI_OKAY;
}
int ti_stochrsi_start(TI_REAL const *options) {
    return ((int)options[0]) * 2 - 1;
}
int ti_stochrsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    if (period < 2) return TI_INVALID_OPTION;
    if (size <= ti_stochrsi_start(options)) return TI_OKAY;
    ti_buffer *rsi = ti_buffer_new(period);
    TI_REAL smooth_up = 0, smooth_down = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up += upward;
        smooth_down += downward;
    }
    smooth_up /= period;
    smooth_down /= period;
    TI_REAL r = 100.0 * (smooth_up / (smooth_up + smooth_down));
    ti_buffer_push(rsi, r);
    TI_REAL min = r;
    TI_REAL max = r;
    int mini = 0;
    int maxi = 0;
    for (i = period+1; i < size; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up = (upward-smooth_up) * per + smooth_up;
        smooth_down = (downward-smooth_down) * per + smooth_down;
        r = 100.0 * (smooth_up / (smooth_up + smooth_down));
        if (r > max) {
            max = r;
            maxi = rsi->index;
        } else if (maxi == rsi->index) {
            max = r;
            int j;
            for (j = 0; j < rsi->size; ++j) {
                if (j == rsi->index) continue;
                if (rsi->vals[j] > max) {
                    max = rsi->vals[j];
                    maxi = j;
                }
            }
        }
        if (r < min) {
            min = r;
            mini = rsi->index;
        } else if (mini == rsi->index) {
            min = r;
            int j;
            for (j = 0; j < rsi->size; ++j) {
                if (j == rsi->index) continue;
                if (rsi->vals[j] < min) {
                    min = rsi->vals[j];
                    mini = j;
                }
            }
        }
        ti_buffer_qpush(rsi, r);
        if (i > period*2 - 2) {
            const TI_REAL diff = max - min;
            if (diff == 0.0) {
                *output++ = 0.0;
            } else {
                *output++ = (r - min) / (diff);
            }
        }
    }
    ti_buffer_free(rsi);
    assert(output - outputs[0] == size - ti_stochrsi_start(options));
    return TI_OKAY;
}
int ti_sub_start(TI_REAL const *options) { (void)options; return 0; } int ti_sub(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] - in2[i]); } return TI_OKAY; }
int ti_sum_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_sum(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_sum_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    *output++ = sum;
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum -= input[i-period];
        *output++ = sum;
    }
    assert(output - outputs[0] == size - ti_sum_start(options));
    return TI_OKAY;
}
int ti_tan_start(TI_REAL const *options) { (void)options; return 0; } int ti_tan(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (tan(in1[i])); } return TI_OKAY; }
int ti_tanh_start(TI_REAL const *options) { (void)options; return 0; } int ti_tanh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (tanh(in1[i])); } return TI_OKAY; }
int ti_tema_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return (period-1) * 3;
}
int ti_tema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_tema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    const TI_REAL per1 = 1.0 - per;
    TI_REAL ema = input[0];
    TI_REAL ema2 = 0;
    TI_REAL ema3 = 0;
    int i;
    for (i = 0; i < size; ++i) {
        ema = ema * per1 + input[i] * per;
        if (i == period-1) {
            ema2 = ema;
        }
        if (i >= period-1) {
            ema2 = ema2 * per1 + ema * per;
            if (i == (period-1) * 2) {
                ema3 = ema2;
            }
            if (i >= (period-1) * 2) {
                ema3 = ema3 * per1 + ema2 * per;
                if (i >= (period-1) * 3) {
                    *output = 3 * ema - 3 * ema2 + ema3;
                    ++output;
                }
            }
        }
    }
    assert(output - outputs[0] == size - ti_tema_start(options));
    return TI_OKAY;
}
int ti_todeg_start(TI_REAL const *options) { (void)options; return 0; } int ti_todeg(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = ((in1[i] * (180.0 / 3.14159265358979323846))); } return TI_OKAY; }
int ti_torad_start(TI_REAL const *options) { (void)options; return 0; } int ti_torad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = ((in1[i] * (3.14159265358979323846 / 180.0))); } return TI_OKAY; }
int ti_tr_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_tr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    TI_REAL truerange;
    output[0] = high[0] - low[0];
    int i;
    for (i = 1; i < size; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        output[i] = truerange;
    }
    return TI_OKAY;
}
int ti_trima_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_trima(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_trima_start(options)) return TI_OKAY;
    if (period <= 2) return ti_sma(size, inputs, options, outputs);
    TI_REAL weights = 1 / (TI_REAL) ((period%2) ?
        ((period/2+1) * (period/2+1)):
        ((period/2+1) * (period/2)));
    TI_REAL weight_sum = 0;
    TI_REAL lead_sum = 0;
    TI_REAL trail_sum = 0;
    const int lead_period = period%2 ? period/2 : period/2-1;
    const int trail_period = lead_period + 1;
    int i, w = 1;
    for (i = 0; i < period-1; ++i) {
        weight_sum += input[i] * w;
        if (i+1 > period-lead_period) lead_sum += input[i];
        if (i+1 <= trail_period) trail_sum += input[i];
        if (i+1 < trail_period) ++w;
        if (i+1 >= period-lead_period) --w;
    }
    int lsi = (period-1)-lead_period+1;
    int tsi1 = (period-1)-period+1+trail_period;
    int tsi2 = (period-1)-period+1;
    for (i = period-1; i < size; ++i) {
        weight_sum += input[i];
        *output++ = weight_sum * weights;
        lead_sum += input[i];
        weight_sum += lead_sum;
        weight_sum -= trail_sum;
        lead_sum -= input[lsi++];
        trail_sum += input[tsi1++];
        trail_sum -= input[tsi2++];
    }
    assert(output - outputs[0] == size - ti_trima_start(options));
    return TI_OKAY;
}
int ti_trix_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return ((period-1)*3)+1;
}
int ti_trix(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_trix_start(options)) return TI_OKAY;
    const int start = (period*3)-2;
    assert(start == ti_trix_start(options));
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    TI_REAL ema1 = input[0];
    TI_REAL ema2 = 0, ema3 = 0;
    int i;
    for (i = 1; i < start; ++i) {
        ema1 = (input[i]-ema1) * per + ema1;
        if (i == period-1) {
            ema2 = ema1;
        } else if (i > period-1) {
            ema2 = (ema1-ema2) * per + ema2;
            if (i == period * 2 - 2) {
                ema3 = ema2;
            } else if (i > period * 2 - 2) {
                ema3 = (ema2-ema3) * per + ema3;
            }
        }
    }
    for (i = start; i < size; ++i) {
        ema1 = (input[i]-ema1) * per + ema1;
        ema2 = (ema1-ema2) * per + ema2;
        const TI_REAL last = ema3;
        ema3 = (ema2-ema3) * per + ema3;
        *output++ = (ema3-last)/ema3 * 100.0;
    }
    assert(output - outputs[0] == size - ti_trix_start(options));
    return TI_OKAY;
}
int ti_trunc_start(TI_REAL const *options) { (void)options; return 0; } int ti_trunc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = ((int)(in1[i])); } return TI_OKAY; }
int ti_tsf_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_tsf(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_tsf_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; *output++ = (a + b * ((period+1))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_tsf_start(options));
    return TI_OKAY;
}
int ti_typprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_typprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (high[i] + low[i] + close[i]) * (1.0/3.0);
    }
    return TI_OKAY;
}
int ti_ultosc_start(TI_REAL const *options) {
    return (int)options[2];
}
int ti_ultosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int short_period = (int)options[0];
    const int medium_period = (int)options[1];
    const int long_period = (int)options[2];
    TI_REAL *output = outputs[0];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (medium_period < short_period) return TI_INVALID_OPTION;
    if (long_period < medium_period) return TI_INVALID_OPTION;
    if (size <= ti_ultosc_start(options)) return TI_OKAY;
    ti_buffer *bp_buf = ti_buffer_new(long_period);
    ti_buffer *r_buf = ti_buffer_new(long_period);
    TI_REAL bp_short_sum = 0, bp_medium_sum = 0;
    TI_REAL r_short_sum = 0, r_medium_sum = 0;
    int i;
    for (i = 1; i < size; ++i) {
        const TI_REAL true_low = MIN(low[i], close[i-1]);
        const TI_REAL true_high = MAX(high[i], close[i-1]);
        const TI_REAL bp = close[i] - true_low;
        const TI_REAL r = true_high - true_low;
        bp_short_sum += bp;
        bp_medium_sum += bp;
        r_short_sum += r;
        r_medium_sum += r;
        ti_buffer_push(bp_buf, bp);
        ti_buffer_push(r_buf, r);
        if (i > short_period) {
            int short_index = bp_buf->index - short_period - 1;
            if (short_index < 0) short_index += long_period;
            bp_short_sum -= bp_buf->vals[short_index];
            r_short_sum -= r_buf->vals[short_index];
            if (i > medium_period) {
                int medium_index = bp_buf->index - medium_period - 1;
                if (medium_index < 0) medium_index += long_period;
                bp_medium_sum -= bp_buf->vals[medium_index];
                r_medium_sum -= r_buf->vals[medium_index];
            }
        }
        if (i >= long_period) {
            const TI_REAL first = 4 * bp_short_sum / r_short_sum;
            const TI_REAL second = 2 * bp_medium_sum / r_medium_sum;
            const TI_REAL third = 1 * bp_buf->sum / r_buf->sum;
            const TI_REAL ult = (first + second + third) * 100.0 / 7.0;
            *output++ = ult;
        }
    }
    ti_buffer_free(bp_buf);
    ti_buffer_free(r_buf);
    assert(output - outputs[0] == size - ti_ultosc_start(options));
    return TI_OKAY;
}
int ti_var_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_var(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_var_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    *output++ = sum2 * scale - (sum * scale) * (sum * scale);
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        *output++ = sum2 * scale - (sum * scale) * (sum * scale);
    }
    assert(output - outputs[0] == size - ti_var_start(options));
    return TI_OKAY;
}
int ti_vhf_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_vhf(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *in = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_vhf_start(options)) return TI_OKAY;
    int trail = 1, maxi = -1, mini = -1;
    TI_REAL max = in[0], min = in[0];
    TI_REAL bar;
    TI_REAL sum = 0;
    int i, j;
    TI_REAL yc = in[0];
    TI_REAL c;
    for (i = 1; i < period; ++i) {
        c = in[i];
        sum += fabs(c - yc);
        yc = c;
    }
    for (i = period; i < size; ++i, ++trail) {
        c = in[i];
        sum += fabs(c - yc);
        yc = c;
        if (i > period) {
            sum -= fabs(in[i-period] - in[i-period-1]);
        }
        bar = c;
        if (maxi < trail) {
            maxi = trail;
            max = in[maxi];
            j = trail;
            while(++j <= i) {
                bar = in[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = c;
        if (mini < trail) {
            mini = trail;
            min = in[mini];
            j = trail;
            while(++j <= i) {
                bar = in[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *output++ = fabs(max - min) / sum;
    }
    assert(output - outputs[0] == size - ti_vhf_start(options));
    return TI_OKAY;
}
int ti_vidya_start(TI_REAL const *options) {
    return ((int)(options[1])) - 2;
}
int ti_vidya(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const TI_REAL alpha = options[2];
    TI_REAL *output = outputs[0];
    const TI_REAL short_div = 1.0 / short_period;
    const TI_REAL long_div = 1.0 / long_period;
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (alpha < 0.0 || alpha > 1.0) return TI_INVALID_OPTION;
    if (size <= ti_vidya_start(options)) return TI_OKAY;
    TI_REAL short_sum = 0;
    TI_REAL short_sum2 = 0;
    TI_REAL long_sum = 0;
    TI_REAL long_sum2 = 0;
    int i;
    for (i = 0; i < long_period; ++i) {
        long_sum += input[i];
        long_sum2 += input[i] * input[i];
        if (i >= long_period - short_period) {
            short_sum += input[i];
            short_sum2 += input[i] * input[i];
        }
    }
    TI_REAL val = input[long_period-2];
    *output++ = val;
    if (long_period - 1 < size) {
        TI_REAL short_stddev = sqrt(short_sum2 * short_div - (short_sum * short_div) * (short_sum * short_div));
        TI_REAL long_stddev = sqrt(long_sum2 * long_div - (long_sum * long_div) * (long_sum * long_div));
        TI_REAL k = short_stddev / long_stddev;
        if (k != k) k = 0;
        k *= alpha;
        val = (input[long_period-1]-val) * k + val;
        *output++ = val;
    }
    for (i = long_period; i < size; ++i) {
        long_sum += input[i];
        long_sum2 += input[i] * input[i];
        short_sum += input[i];
        short_sum2 += input[i] * input[i];
        long_sum -= input[i-long_period];
        long_sum2 -= input[i-long_period] * input[i-long_period];
        short_sum -= input[i-short_period];
        short_sum2 -= input[i-short_period] * input[i-short_period];
        {
            TI_REAL short_stddev = sqrt(short_sum2 * short_div - (short_sum * short_div) * (short_sum * short_div));
            TI_REAL long_stddev = sqrt(long_sum2 * long_div - (long_sum * long_div) * (long_sum * long_div));
            TI_REAL k = short_stddev / long_stddev;
            if (k != k) k = 0;
            k *= alpha;
            val = (input[i]-val) * k + val;
            *output++ = val;
        }
    }
    assert(output - outputs[0] == size - ti_vidya_start(options));
    return TI_OKAY;
}
int ti_volatility_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_volatility(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    const TI_REAL annual = sqrt(252);
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_volatility_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        const TI_REAL c = (input[i]/input[i-1]-1.0);
        sum += c;
        sum2 += c * c;
    }
    *output++ = sqrt(sum2 * scale - (sum * scale) * (sum * scale)) * annual;
    for (i = period+1; i < size; ++i) {
        const TI_REAL c = (input[i]/input[i-1]-1.0);
        sum += c;
        sum2 += c * c;
        const TI_REAL cp = (input[i-period]/input[i-period-1]-1.0);
        sum -= cp;
        sum2 -= cp * cp;
        *output++ = sqrt(sum2 * scale - (sum * scale) * (sum * scale)) * annual;
    }
    assert(output - outputs[0] == size - ti_volatility_start(options));
    return TI_OKAY;
}
int ti_vosc_start(TI_REAL const *options) {
    return (int)options[1]-1;
}
int ti_vosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const TI_REAL short_div = 1.0 / short_period;
    const TI_REAL long_div = 1.0 / long_period;
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_vosc_start(options)) return TI_OKAY;
    TI_REAL short_sum = 0;
    TI_REAL long_sum = 0;
    int i;
    for (i = 0; i < long_period; ++i) {
        if (i >= (long_period - short_period)) {
            short_sum += input[i];
        }
        long_sum += input[i];
    }
    {
        const TI_REAL savg = short_sum * short_div;
        const TI_REAL lavg = long_sum * long_div;
        *output++ = 100.0 * (savg - lavg) / lavg;
    }
    for (i = long_period; i < size; ++i) {
        short_sum += input[i];
        short_sum -= input[i-short_period];
        long_sum += input[i];
        long_sum -= input[i-long_period];
        const TI_REAL savg = short_sum * short_div;
        const TI_REAL lavg = long_sum * long_div;
        *output++ = 100.0 * (savg - lavg) / lavg;
    }
    assert(output - outputs[0] == size - ti_vosc_start(options));
    return TI_OKAY;
}
int ti_vwma_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_vwma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const TI_REAL *volume = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_vwma_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL vsum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i] * volume[i];
        vsum += volume[i];
    }
    *output++ = sum / vsum;
    for (i = period; i < size; ++i) {
        sum += input[i] * volume[i];
        sum -= input[i-period] * volume[i-period];
        vsum += volume[i];
        vsum -= volume[i-period];
        *output++ = sum / vsum;
    }
    assert(output - outputs[0] == size - ti_vwma_start(options));
    return TI_OKAY;
}
int ti_wad_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_wad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    if (size <= ti_wad_start(options)) return TI_OKAY;
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0;
    TI_REAL yc = close[0];
    int i;
    for (i = 1; i < size; ++i) {
        const TI_REAL c = close[i];
        if (c > yc) {
            sum += c - MIN(yc, low[i]);
        } else if (c < yc) {
            sum += c - MAX(yc, high[i]);
        } else {
        }
        *output++ = sum;
        yc = close[i];
    }
    assert(output - outputs[0] == size - ti_wad_start(options));
    return TI_OKAY;
}
int ti_wcprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_wcprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (high[i] + low[i] + close[i] + close[i]) * 0.25;
    }
    return TI_OKAY;
}
int ti_wilders_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_wilders(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_wilders_start(options)) return TI_OKAY;
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    TI_REAL val = sum / period;
    *output++ = val;
    for (i = period; i < size; ++i) {
        val = (input[i]-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_wilders_start(options));
    return TI_OKAY;
}
int ti_willr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_willr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_willr_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    TI_REAL bar;
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        const TI_REAL highlow = (max - min);
        const TI_REAL r = highlow == 0.0 ? 0.0 : -100 * ((max - close[i]) / highlow);
        *output++ = r;
    }
    assert(output - outputs[0] == size - ti_willr_start(options));
    return TI_OKAY;
}
int ti_wma_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_wma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_wma_start(options)) return TI_OKAY;
    const TI_REAL weights = period * (period+1) / 2;
    TI_REAL sum = 0;
    TI_REAL weight_sum = 0;
    int i;
    for (i = 0; i < period-1; ++i) {
        weight_sum += input[i] * (i+1);
        sum += input[i];
    }
    for (i = period-1; i < size; ++i) {
        weight_sum += input[i] * period;
        sum += input[i];
        *output++ = weight_sum / weights;
        weight_sum -= sum;
        sum -= input[i-period+1];
    }
    assert(output - outputs[0] == size - ti_wma_start(options));
    return TI_OKAY;
}
int ti_zlema_start(TI_REAL const *options) {
    return ((int)options[0] - 1) / 2 - 1;
}
int ti_zlema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    const int lag = (period - 1) / 2;
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_zlema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    TI_REAL val = input[lag-1];
    *output++ = val;
    int i;
    for (i = lag; i < size; ++i) {
        TI_REAL c = input[i];
        TI_REAL l = input[i-lag];
        val = ((c + (c-l))-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_zlema_start(options));
    return TI_OKAY;
}
ti_buffer *ti_buffer_new(int size) {
    const int s = (int)sizeof(ti_buffer) + (size-1) * (int)sizeof(TI_REAL);
    ti_buffer *ret = (ti_buffer*)malloc((unsigned int)s);
    ret->size = size;
    ret->pushes = 0;
    ret->index = 0;
    ret->sum = 0;
    return ret;
}
void ti_buffer_free(ti_buffer *buffer) {
    free(buffer);
}
const char* ti_version() {return TI_VERSION;}
long int ti_build() {return TI_BUILD;}
struct ti_indicator_info ti_indicators[] = {
    {"abs", "Vector Absolute Value", ti_abs_start, ti_abs, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"abs",0}},
    {"acos", "Vector Arccosine", ti_acos_start, ti_acos, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"acos",0}},
    {"ad", "Accumulation/Distribution Line", ti_ad_start, ti_ad, TI_TYPE_INDICATOR, 4, 0, 1, {"high","low","close","volume",0}, {"",0}, {"ad",0}},
    {"add", "Vector Addition", ti_add_start, ti_add, TI_TYPE_SIMPLE, 2, 0, 1, {"real","real",0}, {"",0}, {"add",0}},
    {"adosc", "Accumulation/Distribution Oscillator", ti_adosc_start, ti_adosc, TI_TYPE_INDICATOR, 4, 2, 1, {"high","low","close","volume",0}, {"short period","long period",0}, {"adosc",0}},
    {"adx", "Average Directional Movement Index", ti_adx_start, ti_adx, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"dx",0}},
    {"adxr", "Average Directional Movement Rating", ti_adxr_start, ti_adxr, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"dx",0}},
    {"ao", "Awesome Oscillator", ti_ao_start, ti_ao, TI_TYPE_INDICATOR, 2, 0, 1, {"high","low",0}, {"",0}, {"ao",0}},
    {"apo", "Absolute Price Oscillator", ti_apo_start, ti_apo, TI_TYPE_INDICATOR, 1, 2, 1, {"real",0}, {"short period","long period",0}, {"apo",0}},
    {"aroon", "Aroon", ti_aroon_start, ti_aroon, TI_TYPE_INDICATOR, 2, 1, 2, {"high","low",0}, {"period",0}, {"aroon_down","aroon_up",0}},
    {"aroonosc", "Aroon Oscillator", ti_aroonosc_start, ti_aroonosc, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"aroonosc",0}},
    {"asin", "Vector Arcsine", ti_asin_start, ti_asin, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"asin",0}},
    {"atan", "Vector Arctangent", ti_atan_start, ti_atan, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"atan",0}},
    {"atr", "Average True Range", ti_atr_start, ti_atr, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"atr",0}},
    {"avgprice", "Average Price", ti_avgprice_start, ti_avgprice, TI_TYPE_OVERLAY, 4, 0, 1, {"open","high","low","close",0}, {"",0}, {"avgprice",0}},
    {"bbands", "Bollinger Bands", ti_bbands_start, ti_bbands, TI_TYPE_OVERLAY, 1, 2, 3, {"real",0}, {"period","stddev",0}, {"bbands_lower","bbands_middle","bbands_upper",0}},
    {"bop", "Balance of Power", ti_bop_start, ti_bop, TI_TYPE_INDICATOR, 4, 0, 1, {"open","high","low","close",0}, {"",0}, {"bop",0}},
    {"cci", "Commodity Channel Index", ti_cci_start, ti_cci, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"cci",0}},
    {"ceil", "Vector Ceiling", ti_ceil_start, ti_ceil, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"ceil",0}},
    {"cmo", "Chande Momentum Oscillator", ti_cmo_start, ti_cmo, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"cmo",0}},
    {"cos", "Vector Cosine", ti_cos_start, ti_cos, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"cos",0}},
    {"cosh", "Vector Hyperbolic Cosine", ti_cosh_start, ti_cosh, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"cosh",0}},
    {"crossany", "Crossany", ti_crossany_start, ti_crossany, TI_TYPE_MATH, 2, 0, 1, {"real","real",0}, {"",0}, {"crossany",0}},
    {"crossover", "Crossover", ti_crossover_start, ti_crossover, TI_TYPE_MATH, 2, 0, 1, {"real","real",0}, {"",0}, {"crossover",0}},
    {"cvi", "Chaikins Volatility", ti_cvi_start, ti_cvi, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"cvi",0}},
    {"decay", "Linear Decay", ti_decay_start, ti_decay, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"decay",0}},
    {"dema", "Double Exponential Moving Average", ti_dema_start, ti_dema, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"dema",0}},
    {"di", "Directional Indicator", ti_di_start, ti_di, TI_TYPE_INDICATOR, 3, 1, 2, {"high","low","close",0}, {"period",0}, {"plus_di","minus_di",0}},
    {"div", "Vector Division", ti_div_start, ti_div, TI_TYPE_SIMPLE, 2, 0, 1, {"real","real",0}, {"",0}, {"div",0}},
    {"dm", "Directional Movement", ti_dm_start, ti_dm, TI_TYPE_INDICATOR, 2, 1, 2, {"high","low",0}, {"period",0}, {"plus_dm","minus_dm",0}},
    {"dpo", "Detrended Price Oscillator", ti_dpo_start, ti_dpo, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"dpo",0}},
    {"dx", "Directional Movement Index", ti_dx_start, ti_dx, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"dx",0}},
    {"edecay", "Exponential Decay", ti_edecay_start, ti_edecay, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"edecay",0}},
    {"ema", "Exponential Moving Average", ti_ema_start, ti_ema, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"ema",0}},
    {"emv", "Ease of Movement", ti_emv_start, ti_emv, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","volume",0}, {"",0}, {"emv",0}},
    {"exp", "Vector Exponential", ti_exp_start, ti_exp, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"exp",0}},
    {"fisher", "Fisher Transform", ti_fisher_start, ti_fisher, TI_TYPE_INDICATOR, 2, 1, 2, {"high","low",0}, {"period",0}, {"fisher","fisher_signal",0}},
    {"floor", "Vector Floor", ti_floor_start, ti_floor, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"floor",0}},
    {"fosc", "Forecast Oscillator", ti_fosc_start, ti_fosc, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"fosc",0}},
    {"hma", "Hull Moving Average", ti_hma_start, ti_hma, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"hma",0}},
    {"kama", "Kaufman Adaptive Moving Average", ti_kama_start, ti_kama, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"kama",0}},
    {"kvo", "Klinger Volume Oscillator", ti_kvo_start, ti_kvo, TI_TYPE_INDICATOR, 4, 2, 1, {"high","low","close","volume",0}, {"short period","long period",0}, {"kvo",0}},
    {"lag", "Lag", ti_lag_start, ti_lag, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"lag",0}},
    {"linreg", "Linear Regression", ti_linreg_start, ti_linreg, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"linreg",0}},
    {"linregintercept", "Linear Regression Intercept", ti_linregintercept_start, ti_linregintercept, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"linregintercept",0}},
    {"linregslope", "Linear Regression Slope", ti_linregslope_start, ti_linregslope, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"linregslope",0}},
    {"ln", "Vector Natural Log", ti_ln_start, ti_ln, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"ln",0}},
    {"log10", "Vector Base-10 Log", ti_log10_start, ti_log10, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"log10",0}},
    {"macd", "Moving Average Convergence/Divergence", ti_macd_start, ti_macd, TI_TYPE_INDICATOR, 1, 3, 3, {"real",0}, {"short period","long period","signal period",0}, {"macd","macd_signal","macd_histogram",0}},
    {"marketfi", "Market Facilitation Index", ti_marketfi_start, ti_marketfi, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","volume",0}, {"",0}, {"marketfi",0}},
    {"mass", "Mass Index", ti_mass_start, ti_mass, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"mass",0}},
    {"max", "Maximum In Period", ti_max_start, ti_max, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"max",0}},
    {"md", "Mean Deviation Over Period", ti_md_start, ti_md, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"md",0}},
    {"medprice", "Median Price", ti_medprice_start, ti_medprice, TI_TYPE_OVERLAY, 2, 0, 1, {"high","low",0}, {"",0}, {"medprice",0}},
    {"mfi", "Money Flow Index", ti_mfi_start, ti_mfi, TI_TYPE_INDICATOR, 4, 1, 1, {"high","low","close","volume",0}, {"period",0}, {"mfi",0}},
    {"min", "Minimum In Period", ti_min_start, ti_min, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"min",0}},
    {"mom", "Momentum", ti_mom_start, ti_mom, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"mom",0}},
    {"msw", "Mesa Sine Wave", ti_msw_start, ti_msw, TI_TYPE_INDICATOR, 1, 1, 2, {"real",0}, {"period",0}, {"msw_sine","msw_lead",0}},
    {"mul", "Vector Multiplication", ti_mul_start, ti_mul, TI_TYPE_SIMPLE, 2, 0, 1, {"real","real",0}, {"",0}, {"mul",0}},
    {"natr", "Normalized Average True Range", ti_natr_start, ti_natr, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"natr",0}},
    {"nvi", "Negative Volume Index", ti_nvi_start, ti_nvi, TI_TYPE_INDICATOR, 2, 0, 1, {"close","volume",0}, {"",0}, {"nvi",0}},
    {"obv", "On Balance Volume", ti_obv_start, ti_obv, TI_TYPE_INDICATOR, 2, 0, 1, {"close","volume",0}, {"",0}, {"obv",0}},
    {"ppo", "Percentage Price Oscillator", ti_ppo_start, ti_ppo, TI_TYPE_INDICATOR, 1, 2, 1, {"real",0}, {"short period","long period",0}, {"ppo",0}},
    {"psar", "Parabolic SAR", ti_psar_start, ti_psar, TI_TYPE_OVERLAY, 2, 2, 1, {"high","low",0}, {"acceleration factor step","acceleration factor maximum",0}, {"psar",0}},
    {"pvi", "Positive Volume Index", ti_pvi_start, ti_pvi, TI_TYPE_INDICATOR, 2, 0, 1, {"close","volume",0}, {"",0}, {"pvi",0}},
    {"qstick", "Qstick", ti_qstick_start, ti_qstick, TI_TYPE_INDICATOR, 2, 1, 1, {"open","close",0}, {"period",0}, {"qstick",0}},
    {"roc", "Rate of Change", ti_roc_start, ti_roc, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"roc",0}},
    {"rocr", "Rate of Change Ratio", ti_rocr_start, ti_rocr, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"rocr",0}},
    {"round", "Vector Round", ti_round_start, ti_round, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"round",0}},
    {"rsi", "Relative Strength Index", ti_rsi_start, ti_rsi, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"rsi",0}},
    {"sin", "Vector Sine", ti_sin_start, ti_sin, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"sin",0}},
    {"sinh", "Vector Hyperbolic Sine", ti_sinh_start, ti_sinh, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"sinh",0}},
    {"sma", "Simple Moving Average", ti_sma_start, ti_sma, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"sma",0}},
    {"sqrt", "Vector Square Root", ti_sqrt_start, ti_sqrt, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"sqrt",0}},
    {"stddev", "Standard Deviation Over Period", ti_stddev_start, ti_stddev, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"stddev",0}},
    {"stderr", "Standard Error Over Period", ti_stderr_start, ti_stderr, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"stderr",0}},
    {"stoch", "Stochastic Oscillator", ti_stoch_start, ti_stoch, TI_TYPE_INDICATOR, 3, 3, 2, {"high","low","close",0}, {"%k period","%k slowing period","%d period",0}, {"stoch_k","stoch_d",0}},
    {"stochrsi", "Stochastic RSI", ti_stochrsi_start, ti_stochrsi, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"stochrsi",0}},
    {"sub", "Vector Subtraction", ti_sub_start, ti_sub, TI_TYPE_SIMPLE, 2, 0, 1, {"real","real",0}, {"",0}, {"sub",0}},
    {"sum", "Sum Over Period", ti_sum_start, ti_sum, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"sum",0}},
    {"tan", "Vector Tangent", ti_tan_start, ti_tan, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"tan",0}},
    {"tanh", "Vector Hyperbolic Tangent", ti_tanh_start, ti_tanh, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"tanh",0}},
    {"tema", "Triple Exponential Moving Average", ti_tema_start, ti_tema, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"tema",0}},
    {"todeg", "Vector Degree Conversion", ti_todeg_start, ti_todeg, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"degrees",0}},
    {"torad", "Vector Radian Conversion", ti_torad_start, ti_torad, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"radians",0}},
    {"tr", "True Range", ti_tr_start, ti_tr, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","close",0}, {"",0}, {"tr",0}},
    {"trima", "Triangular Moving Average", ti_trima_start, ti_trima, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"trima",0}},
    {"trix", "Trix", ti_trix_start, ti_trix, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"trix",0}},
    {"trunc", "Vector Truncate", ti_trunc_start, ti_trunc, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"trunc",0}},
    {"tsf", "Time Series Forecast", ti_tsf_start, ti_tsf, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"tsf",0}},
    {"typprice", "Typical Price", ti_typprice_start, ti_typprice, TI_TYPE_OVERLAY, 3, 0, 1, {"high","low","close",0}, {"",0}, {"typprice",0}},
    {"ultosc", "Ultimate Oscillator", ti_ultosc_start, ti_ultosc, TI_TYPE_INDICATOR, 3, 3, 1, {"high","low","close",0}, {"short period","medium period","long period",0}, {"ultosc",0}},
    {"var", "Variance Over Period", ti_var_start, ti_var, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"var",0}},
    {"vhf", "Vertical Horizontal Filter", ti_vhf_start, ti_vhf, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"vhf",0}},
    {"vidya", "Variable Index Dynamic Average", ti_vidya_start, ti_vidya, TI_TYPE_OVERLAY, 1, 3, 1, {"real",0}, {"short period","long period","alpha",0}, {"vidya",0}},
    {"volatility", "Annualized Historical Volatility", ti_volatility_start, ti_volatility, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"volatility",0}},
    {"vosc", "Volume Oscillator", ti_vosc_start, ti_vosc, TI_TYPE_INDICATOR, 1, 2, 1, {"volume",0}, {"short period","long period",0}, {"vosc",0}},
    {"vwma", "Volume Weighted Moving Average", ti_vwma_start, ti_vwma, TI_TYPE_OVERLAY, 2, 1, 1, {"close","volume",0}, {"period",0}, {"vwma",0}},
    {"wad", "Williams Accumulation/Distribution", ti_wad_start, ti_wad, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","close",0}, {"",0}, {"wad",0}},
    {"wcprice", "Weighted Close Price", ti_wcprice_start, ti_wcprice, TI_TYPE_OVERLAY, 3, 0, 1, {"high","low","close",0}, {"",0}, {"wcprice",0}},
    {"wilders", "Wilders Smoothing", ti_wilders_start, ti_wilders, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"wilders",0}},
    {"willr", "Williams %R", ti_willr_start, ti_willr, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"willr",0}},
    {"wma", "Weighted Moving Average", ti_wma_start, ti_wma, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"wma",0}},
    {"zlema", "Zero-Lag Exponential Moving Average", ti_zlema_start, ti_zlema, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"zlema",0}},
    {0,0,0,0,0,0,0,0,{0,0},{0,0},{0,0}}
};
const ti_indicator_info *ti_find_indicator(const char *name) {
    int imin = 0;
    int imax = sizeof(ti_indicators) / sizeof(ti_indicator_info) - 2;
    while (imax >= imin) {
        const int i = (imin + ((imax-imin)/2));
        const int c = strcmp(name, ti_indicators[i].name);
        if (c == 0) {
            return ti_indicators + i;
        } else if (c > 0) {
            imin = i + 1;
        } else {
            imax = i - 1;
        }
    }
    return 0;
}
