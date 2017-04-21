var tulind = require("./index");

console.log("Tulip Indicators version is:");
console.log(tulind.version);


//Examples assume you have some price data like this:
var open  = [4,5,5,5,4,4,4,6,6,6];
var high  = [9,7,8,7,8,8,7,7,8,7];
var low   = [1,2,3,3,2,1,2,2,2,3];
var close = [4,5,6,6,6,5,5,5,6,4];
var volume = [123,232,212,232,111,232,212,321,232,321];



//Do a simple moving average on close prices with period of 3.
tulind.indicators.sma.indicator([close], [3], function(err, results) {
  console.log("Result of sma is:");
  console.log(results[0]);
});



//Discover argument types at run-time:
console.log(tulind.indicators.stoch);


//Functions that take multiple inputs, options, or outputs use arrays.
//Call Stochastic Oscillator, taking 3 inputs, 3 options, and 2 outputs.
tulind.indicators.stoch.indicator([high, low, close], [5, 3, 3], function(err, results) {
  console.log("Result of stochastic oscillator is:");
  console.log(results[0]);
  console.log(results[1]);
});


console.log("Given these options, the output arrays will be this much shorter than the input arrays:");
console.log(tulind.indicators.stoch.start([5,3,3]));

//console.log(tulind.indicators);

