const net = require("net");

const port = 8080;
const server = net.createServer((req) => {
  console.log("toto");
  req.end(new Date() + "\n");
});
server.listen(port);
