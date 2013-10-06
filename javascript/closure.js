/**
 * @see JavaScript: The Good Parts
 */

// プロパティがpublic
var quo1 = {
	status: 1,
	set_status: function(s) {
		this.status = s;
	},
	get_status: function() {
		return this.status;
	}
};

// プロパティがpublic
var Quo = function() {
	this.status = 2;
};
Quo.prototype.set_status = function(s) {
	this.status = s;
};
Quo.prototype.get_status = function() {
	return this.status;
};
var quo2 = new Quo();

// プロパティがpublic
var QuoEx = function() {};
QuoEx.prototype.status = 3;
QuoEx.prototype.set_status = function(s) {
	this.status = s;
};
QuoEx.prototype.get_status = function() {
	return this.status;
};
var quo3 = new QuoEx();

// プロパティがprivate
var quo = function() {
	var that = {};
	var status = 4;
	that.get_status = function() {
		return status;
	};
	that.set_status = function(s) {
		status = s;
	};
	return that;
};
var quo4 = quo();



