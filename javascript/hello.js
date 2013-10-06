/**
 * @file hello.js
 */

// function文
function main1 () {
	console.log("#1 Hello, World");
}

// Functionコンストラクタ
var main2 = new Function("console.log(\"#2 Hello, World\");");

// 関数リテラル
var main3 = function () {
	console.log("#3 Hello, World");
}

