/**
 * @see also JavaScript: The Good Parts
 */

/**
 * オブジェクトリテラルで生成する
 */
var quo1 = {
	status: 1,
	set_status: function(status) {
		this.status = status;
	},
	get_status: function() {
		return this.status;
	}
};

/**
 * オブジェクトリテラルで生成する
 * クロージャを使う
 */ 
var Quo5 = function() {
	var status = 5;
	return {
		set_status: function(s) {
			status = s;
		},
		get_status: function() {
			return status;
		}
	};
};

var quo5 = Quo5();


/**
 * コンストラクタで生成する
 * プロパティのデータ値をprototypeで実装しない
 * プロパティのメソッドをprototypeで実装しない
 */
var Quo2 = function(spec) {
	this.status = spec.status;
	this.set_status = function(status) {
		this.status = status;
	};
	this.get_status = function() {
		return this.status;
	};
};

var quo2 = new Quo2({status: 2});

/**
 * コンストラクタ関数で生成する
 * プロパティのデータ値をprototypeで実装しない
 * プロパティのメソッドをprototypeで実装する
 */ 
var Quo3 = function(spec) {
	this.status = spec.status;
};
Quo3.prototype = {
	set_status: function(status) {
		this.status = status;
	},
	get_status: function() {
		return this.status;
	}
};

var quo3 = new Quo3();


/**
 * コンストラクタ関数で生成する
 * プロパティのデータ値をprototypeで実装する
 * プロパティのメソッドをprototypeで実装する
 */ 
var Quo4 = function() {};
Quo4.prototype = {
	status: 4,
	set_status: function(s) {
		Quo4.prototype.status = s;
	},
	get_status: function() {
		return Quo4.prototype.status;
	}
};

var quo4 = new Quo4();


