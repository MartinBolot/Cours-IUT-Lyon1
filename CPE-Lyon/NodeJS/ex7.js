const https = require("https");

if(process.argv.length >= 2) {
  const url = process.argv[2];
  https.get(url, (res) => {
    if(res.statusCode != 200) {
      console.log(`error ${res.statusCode}`);
      return;
    }
    let fullData = "";
    res.on("data", (data) => {
      fullData += data.toString();
    });
    res.on("end", () => { console.log(fullData); });
  });
}
