/**
 * @file server_parse_querystring.js
 * @brief Node Cookbook section 1.1.2
 */

var http = require('http');
var url = require('url');

var pages = [
	{id: '1', route: '/', output: 'Hello, Node.js'},
	{id: '2', route: '/another page', output: function() {return 'route -> '+this.route;}},
	{id: '3', route: '/about', output: 'シンプルなサンプルコードです'},
];

http.createServer(function (request, response) {
	var id = url.parse(decodeURI(request.url), true).query.id;
	if (id) {
		pages.forEach(function (page) {
			if (page.id == id) {
				response.writeHead(200,
								   {'Content-Type': 'text/html; charset=utf-8'});
				response.end(typeof page.output == 'function' ?
							 page.output() : page.output);

			}
		});
	}
	if (!response.finished) {
		response.writeHead(404);
		response.end('ページが見つかりません');
	}
}).listen(8080);





