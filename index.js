var binary = require('node-pre-gyp');
var path = require('path');
var binding_path = binary.find(path.resolve(path.join(__dirname,'./package.json')));
var tulind = require(binding_path);


var make_call = function(ind) {
  var index = ind.index;
  return function(inputs, options, callback) {
    if (arguments.length < 3) {
      return new Promise(function(resolve, reject) {
        tulind.callbyindex(index, inputs, options, function(err, result) {
          return err ? reject(err) : resolve(result);
        });
      });
    } else {
      return tulind.callbyindex(index, inputs, options, callback);
    }
  };
};

var make_start = function(ind) {
  var index = ind.index;
  return function(options) {
    return tulind.startbyindex(index, options);
  };
};


var indicators = tulind.indicators;
for (var key in indicators) {
  var ind = indicators[key];

  if (typeof ind.indicator == 'function') break;

  ind.indicator = make_call(ind);
  ind.start = make_start(ind);
  delete ind.index;
}



module.exports = {
  indicators: indicators,
  version: tulind.version
};
