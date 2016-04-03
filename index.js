const devices   = require('usb').getDeviceList
const reset     = require('./build/Release/portreset.node').reset

module.exports  = process.platform === 'darwin' ? noop : main

function main (idVendor, idProduct) {
  pqFile(idVendor, idProduct, (f) => reset(f))
}

function pqFile (idVendor, idProduct, fn) {
  devices().map( (u) => {
    if (  u.deviceDescriptor.idVendor === idVendor
      && u.deviceDescriptor.idProduct === idProduct ) {
      fn( '/dev/bus/usb/00' + u.busNumber + '/00' + u.deviceAddress )
    }
  })
}

function noop(){}
