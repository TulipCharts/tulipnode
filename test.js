//The Tulip Indicators C code already has extensive tests.  This test is really
//only to prove that the code compiled properly and is interfacing with node.

var tulind = require("./index");
var l = require("minctest");

console.log("Tulip Node Test Suite\nTulip Indicators version:" + tulind.version);

var equal = function(a, b) {
  //Check if two arrays are equal.

  if (a.length != b.length) {
    console.log("Array length mismatch.");
    return false;
  }

  for (var i = 0; i < a.length; ++i) {
    l.fequal(a[i], b[i]);
  }

  return true;
};


l.run("array dema", function() {
  //atoz page 123
  var a = [122.906,126.500,140.406,174.000,159.812,170.000,176.750,175.531,166.562,163.750,170.500,175.000,184.750,202.781];
  var b = [172.0780,168.5718,170.2278,173.4940,180.5297,194.1428];

  tulind.indicators.dema.indicator([a], [5], function(err, results) {
    l.ok(equal(results[0], b));
  });
});

l.run("array sma", function() {
    var a = [1,2,3,4,5,6,7,8,9,10];

    tulind.indicators.sma.indicator([a], [2], function(err, results) {
      l.ok(equal(results[0], [1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5]));
    });

    tulind.indicators.sma.indicator([a], [3], function(err, results) {
      l.ok(equal(results[0], [2,3,4,5,6,7,8,9]));
    });

    tulind.indicators.sma.indicator([a], [4], function(err, results) {
      l.ok(equal(results[0], [2.5,3.5,4.5,5.5,6.5,7.5,8.5]));
    });

    tulind.indicators.sma.indicator([a], [4]).then(function(results) {
      l.ok(equal(results[0], [2.5,3.5,4.5,5.5,6.5,7.5,8.5]));
    });

    tulind.indicators.sma.indicator([a], [10], function(err, results) {
      l.ok(equal(results[0], [5.5]));
    });

    tulind.indicators.sma.indicator([a], [10]).then(function(results) {
      l.ok(equal(results[0], [5.5]));
    });

    tulind.indicators.sma.indicator([a], [11], function(err, results) {
      l.ok(equal(results[0], []));
    });

    //atoz page 207
    var c = [25,24.875,24.781,24.594,24.5,24.625,25.219,27.25];
    var b = [24.75,24.675,24.744,25.238];
    tulind.indicators.sma.indicator([c], [5], function(err, results) {
      l.ok(equal(results[0], b));
    });
});


l.run("array ema", function() {
    //atoz page 209
    var a = [25,24.875,24.781,24.594,24.5,24.625,25.219,27.25];
    var b = [25,24.958,24.899,24.797,24.698,24.674,24.856,25.654];
    tulind.indicators.ema.indicator([a], [5], function(err, results) {
      l.ok(equal(results[0], b));
    });
});


l.run("array tema", function() {
    //atoz page 123
    var a = [122.906,126.500,140.406,174.000,159.812,170.000,176.750,175.531,166.562,163.750,170.500,175.000,184.750,202.781,209.656,201.312];
    var b = [182.8312,198.5565,209.4760,207.2200];
    tulind.indicators.tema.indicator([a], [5], function(err, results) {
      l.ok(equal(results[0], b));
    });
});

l.run("array wilders", function() {
    //atoz page 366
    var a = [62.125,61.125,62.3438,65.3125,63.9688,63.4375,63,63.7812,63.4062,63.4062,62.4375,61.8438];
    var b = [62.975,63.0675,63.054,63.1995,63.2408,63.2739,63.1066,62.8540];
    tulind.indicators.wilders.indicator([a], [5], function(err, results) {
      l.ok(equal(results[0], b));
    });
});



process.exit(l.results());
