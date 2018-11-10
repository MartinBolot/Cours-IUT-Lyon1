const fs = require("fs");
const path = require("path");

const argvs = process.argv;

if(argvs.length > 2) {
  const args = argvs.filter((el, index) => index >= 2);
  if(args.length >= 2) {
    const dirPath = args[0];
    const extName = args[1];

    fs.readdir(dirPath, (err, files) => {
      if(err) {
        console.log(err);
      }
      if(files) {
        console.log(files.filter((el, index) => path.parse(el).ext == "."+extName));
      }
    });
  }
}
