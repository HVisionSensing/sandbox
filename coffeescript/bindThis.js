var pos1, pos2;

pos1 = {
  x: 100,
  y: 200,
  dump: function() {
    var func;
    func = function() {
      return console.log("x => " + this.x + " y => " + this.y);
    };
    return func();
  }
};

pos2 = {
  x: 100,
  y: 200,
  dump: function() {
    var func,
      _this = this;
    func = function() {
      return console.log("x => " + _this.x + " y => " + _this.y);
    };
    return func();
  }
};

pos1.dump();

pos2.dump();
