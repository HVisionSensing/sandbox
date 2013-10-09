/**
 * @file server.js
 * @brief Node Cookbook section 1.1
 */

var http = require('http');
var path = require('path');

var pages = [
	{route: '/', output: 'Hello, Node.js'},
	{route: '/another page', output: function() {return 'route -> '+this.route;}},
	{route: '/about', output: 'シンプルなサンプルコードです'},
	{route: '/about/this', output: '複数階層ルーティングの例'},
	{route: '/about/node', output: 'Evented I/O for V8 Javascript'},
	{route: '/about/page', output: function() {return 'route -> '+this.route;}},
//	{route: '/about', childRoutes: [
//		{route: '/this', output: '複数階層ルーティングの例'},
//		{route: '/node', output: 'Evented I/O for V8 Javascript'}
//		{route: 'page', output: function() {return 'route -> '+this.route;}},
//	]},
];

http.createServer(function (request, response) {
	var lookup = decodeURI(request.url);
//	var lookup = path.basename(decodeURI(request.url));
	console.log(lookup);
	pages.forEach(function(page) {
		if (page.route == lookup) {
			response.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
			response.end(typeof page.output == 'function' ?
						 page.output() : page.output);
		}
	});
	if (!response.finished) {
		response.writeHead(404);
		response.end('ページが見つかりません');
	}
}).listen(8080);

