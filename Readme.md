[![Build Status](https://travis-ci.org/TulipCharts/tulipnode.svg?branch=master)](https://travis-ci.org/TulipCharts/tulipnode)
[![Build Status](https://ci.appveyor.com/api/projects/status/ps9l8w7fxi81v2q5/branch/master?svg=true)](https://ci.appveyor.com/project/codeplea/tulipnode)
[![npm](https://img.shields.io/npm/dw/tulind.svg)](https://www.npmjs.com/package/tulind)

# Tulip Node

Tulip Node is the official node.js wrapper for [Tulip
Indicators](https://tulipindicators.org). It provides 100+
technical analysis indicator functions, such as:
simple moving average, Bollinger Bands, MACD, Parabolic SAR, Stochastic
Oscillator, and many more.


## Installation

Installation should just be:

``` js
npm install tulind
```

It should work on Windows, Os X, and Linux. Node versions 4, 5, 6, 7, 8, and 9
are tested and supported on each platform.

Note that pre-compiled binaries are available for Windows. For other platforms
you will need a C++ build environment installed. On Linux based distributions
this can be achieved by installing `build-essential` package.

You can force building from source with:

```js
npm install tulind --build-from-source
```

If you run into problems, let me know. I want this to be easy for everyone to
use.


## Usage

Tulip Node is very easy to use.

``` js
var tulind = require('tulind');
console.log("Tulip Indicators version is:");
console.log(tulind.version);
```

In these examples, we assume you already have price data loaded such as:
``` js
//Examples assume you have some price data like this:
//Data order is from oldest to newset (index 0 is the oldest)
var open  = [4,5,5,5,4,4,4,6,6,6];
var high  = [9,7,8,7,8,8,7,7,8,7];
var low   = [1,2,3,3,2,1,2,2,2,3];
var close = [4,5,6,6,6,5,5,5,6,4];
var volume = [123,232,212,232,111,232,212,321,232,321];
```

Calculating a simple moving average is as easy as:

``` js
//Do a simple moving average on close prices with period of 3.
tulind.indicators.sma.indicator([close], [3], function(err, results) {
  console.log("Result of sma is:");
  console.log(results[0]);
});
```



Example of calculating the Stochastic Oscillator:

``` js
//Functions that take multiple inputs, options, or outputs use arrays.
//Call Stochastic Oscillator, taking 3 inputs, 3 options, and 2 outputs.
tulind.indicators.stoch.indicator([high, low, close], [5, 3, 3], function(err, results) {
  console.log("Result of stochastic oscillator is:");
  console.log(results[0]);
  console.log(results[1]);
});
```


It's also easy to discover argument types at run-time:

``` js
//Discover argument types at run-time:
console.log(tulind.indicators.stoch);

//Produces:
{ name: 'stoch',
  full_name: 'Stochastic Oscillator',
  type: 'indicator',
  inputs: 3,
  options: 3,
  outputs: 2,
  input_names: [ 'high', 'low', 'close' ],
  option_names: [ '%k period', '%k slowing period', '%d period' ],
  output_names: [ 'stoch_k', 'stoch_d' ],
  indicator: [Function],
  start: [Function] }
```


Many (most) indicators return an output array length smaller than the input length.
You can get the difference like this:

``` js
console.log("Given these options, the output arrays will be this much shorter than the input arrays:");
console.log(tulind.indicators.stoch.start([5,3,3]));
```


Hopefully it's obvious, but you can see all the available indicators by doing:
``` js
console.log(tulind.indicators);
```

You can also see a full list of the available indicators on the [Tulip
Indicators website here](https://tulipindicators.org/list).

