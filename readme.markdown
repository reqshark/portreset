# linux kernel usb port reset
run from root, performs a hard reset on the usb port

may require `npm i --unsafe-perm`

```js
const reset = require('portreset')

/* reset( idVendor, idProduct ) */
reset(0x1ef1, 0x0001)
```
