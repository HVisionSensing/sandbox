(function() {
  var data, name, value;

  data = {
    x: 100,
    y: 200
  };

  for (name in data) {
    value = data[name];
    console.log("" + name + " => " + value);
  }

}).call(this);
