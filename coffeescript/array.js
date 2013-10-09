var func1, func2;

func1 = function() {
  var a, b, i, _i, _j, _len, _len2;
  a = [1, 2, 3, 4, 5];
  b = [];
  for (_i = 0, _len = a.length; _i < _len; _i++) {
    i = a[_i];
    b.push(i);
  }
  for (_j = 0, _len2 = a.length; _j < _len2; _j++) {
    i = a[_j];
    console.log("=> " + (b.pop()));
  }
};

func2 = function() {
  var i;
  for (i = 1; i <= 10; i++) {
    console.log("=> " + i);
  }
};

console.log("func1");

func1();

console.log("func2");

func2();
