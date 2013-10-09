var pos;

pos = {
  x: 100,
  y: 200,
  dump: function() {
    return console.log("x => " + this.x + ", y => " + this.y);
  }
};

pos.dump();
