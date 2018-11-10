var value = 0;
// si on a au moins un argument
if(process.argv.length > 2) {
  process.argv.forEach((val, index) => {
    if( index >= 2) {
      try {
        let intVal = 0;
        intVal = parseInt(val);
        if(intVal) {
          value += intVal;
        }
      }
      catch(e) {console.error(e);}
    }
  });
}
console.log(value);
return value;
