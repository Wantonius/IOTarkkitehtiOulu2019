const net = require("net");


let server = net.createServer(function(socket) {

	socket.on('data',function(data) {
		console.log(""+data);
	})

})

server.listen("/tmp/socket");
