/**
 * @see JavaScript: The Good Parts
 */

var counter = function(value) {
	var count = value;
	var step = function() {
		console.log("count -> " + count);
		if (count > 0) {
			count --;
			setTimeout(step, 1000);
		}
	};
	setTimeout(step, 1000);
};




