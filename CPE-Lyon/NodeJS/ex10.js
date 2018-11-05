const http = require("http");
const fs = require("fs");

// get conf file
const args = process.argv.length >= 2 ? (
  process.argv.filter((el, index) => index >= 2)
) : null;
const confFile = args.length > 0 ? args[0] : "./web/conf.json";
const config = require(confFile);
const port = 8080;
const server = http.createServer((req, res) => {
  const page = req.url;
  let displayFile = "";
  if(page == "/") {
    displayFile = "index";
  }
  else {
    displayFile = page;
  }
  fs.readFile("./web/" + displayFile + ".html", (err, data) => {
    if(err) {
      res.writeHead(404, {"content-type" : "text/plain"});
      res.end("erreur 404 - page non trouvée");
    }
    else {
      res.writeHead(200, {"content-type" : "text/html"});
      res.end(data.toString());
    }
  });
});
server.listen(port);
