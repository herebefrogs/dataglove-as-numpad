const { SerialPort } = require('serialport');


const port = new SerialPort({ path: '/dev/cu.usbmodem1422201', baudRate: 9600 }, function (err) {
  if (err) {
    return console.log('Serial port to Arduino Uno R3 failed to open: ', err.message);
  }
  console.log('Serial port to Arduino Uno R3 opened');
});

line = '';

port.on('data', function (data) {
  // handle backspace ASCII code
  if (data[0] === 8) {
    line = line.slice(0, -1);
  }
  // turn other ASCII code into human-readable characters
  else {
    line += data.toString();
  }
  console.log(line);
});
