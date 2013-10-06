/**
 * @see JavaScript: The Good Parts
 */

/* 関数の呼び出しパターンとthisの振る舞い */

// 1. 関数呼び出しパターン
var quo1 = function() {
	return this; // グローバルオブジェクトを返す
};
var quo1_this = quo1();

// 2. メソッド呼び出しパターン
var quo2 = {
	status: 2,
	get_this: function() {
		return this; // そのオブジェクトを返す
	}
};
var quo2_this = quo2.get_this();

// 3. コンストラクタ呼び出しパターン
var Quo = function() {
	this.status = 3;
};
Quo.prototype.get_this = function() {
	return this; // newで作成されたオブジェクトを返す
};
var quo3_this = (new Quo()).get_this();

// 4. apply呼び出しパターン
var quo4 = {
	status: 4
};
// applyの引数に渡されたオブジェクトを返す
var quo4_this = Quo.prototype.get_this.apply(quo4);




