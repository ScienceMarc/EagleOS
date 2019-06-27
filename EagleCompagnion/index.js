const SerialPort = require('serialport');
const port = new SerialPort("COM11", {
    baudRate: 230400
});

setTimeout(() => {
    port.write((new Date()).getTime().toString().substr(0,(new Date()).getTime().toString().length-3) + "s");
    console.log((new Date()).getTime().toString().substr(0,(new Date()).getTime().toString().length-3));
},3000)