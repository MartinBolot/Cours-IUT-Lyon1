const fs = require("fs");

const textFile = "./test.txt";
const encodingValue = "utf8";
fs.readFile(textFile, encodingValue, (err, data) => {
  console.log(data.split(/\r?\n/).length);
});
