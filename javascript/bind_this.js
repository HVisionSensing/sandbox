/**
 * @see JavaScript: The Good Parts
 */

var Quo = function() {
	this.status = 1;

	this.get_this = function() {
		var helper = function() {
			return this; // 関数呼び出しパターンなので、グローバルオブジェクトが返される！
		};
		return helper();
	};

	this.get_that = function() {
		var that = this; // メソッド呼び出しパターンなので、ここでのthisはそのオブジェクト
		var helper = function() {
			return that; // 関数スコープにより、ここでのthatはthis(=そのオブジェクト)
		};
		return helper();
	};

	this.get_bind_this = function() {
		var helper = function() {
			return this;
		}.bind(this); // 関数内のthisをここでのthis(=そのオブジェクト)にする
		return helper();
	};
};

