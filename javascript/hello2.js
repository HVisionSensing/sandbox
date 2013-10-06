/**
 * @file hello2.js
 */

var str = "Global";

(function() {
	var str = "Local";

	var hello1 = function() {
		console.log("#1 Hello, " + str);
	};

	var hello2 = new Function("console.log(\"#2 Hello, \" + str);");

	hello1(); // #1 Hello, Local
	hello2(); // #2 Hello, Global
})();

