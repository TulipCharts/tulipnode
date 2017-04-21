//The Tulip Indicators C code has a lot of tests.
//This test is really only to prove that the code
//compiled properly and is interfacing with node.


var tulind = require("./index");
var assert = require("assert");

console.log("Test -- Tulip Indicators version:");
console.log(tulind.version);


var data  = [5,5,5,20];

//Do a simple moving average on close prices with period of 3.
tulind.indicators.sma.indicator([data], [3], function(err, results) {
  assert(results[0][0] == 5);
  assert(results[0][1] == 10);

  console.log("Congratulations, Tulip Node is working!");
});


