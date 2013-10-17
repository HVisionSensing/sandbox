/*
 @file timer.js
 @brief 簡易的なタイマークラス

var timer = new Timer();
timer.start(
	{ func : function () { console.log("hello"); },
	  delay : 1000,
	  repeat_p : true
	});
timer.cancel();

*/

var Timer = function () {
	var timer = null;
	var func, delay, repeat_p;

	this.start = function (prop) {
		func = prop.func;
		delay = prop.delay | 1000;
		repeat_p = prop.repeat_p | false;

		var helper = function () {
			func();
			if (repeat_p) {
				timer = setTimeout(helper, delay, true);
			}
		};
		timer = setTimeout(helper, delay, repeat_p);
	};

	this.cancel = function() {
		clearTimeout(timer);
		timer = null;
	};
};


