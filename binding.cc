#include "nan.h"

using v8::FunctionTemplate;
using v8::Number;
using v8::String;
using Nan::HandleScope;
using Nan::Set;
using Nan::New;
using Nan::To;

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>

NAN_METHOD(reset){
  String::Utf8Value str(info[0]);

  int fd = open(*str, O_WRONLY);
  if (fd < 0) {
    perror("Error opening output file");
    return;
  }

  printf("Resetting USB device %s\n", *str);
  if (ioctl(fd, USBDEVFS_RESET, 0) < 0) {
    perror("Error in ioctl");
    return;
  }

  printf("Reset successful\n");
  close(fd);

  return;
}

#define EXPORT_METHOD(C, S)                                                    \
  Set(C, New(#S).ToLocalChecked(),                                             \
    Nan::GetFunction(New<FunctionTemplate>(S)).ToLocalChecked());

NAN_MODULE_INIT(Init) {
  HandleScope scope;
  /* reset operation */
  EXPORT_METHOD(target, reset);

}

NODE_MODULE(portreset, Init)
