# CLogger

[![License](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)](LICENSE)

在 C 里面 log 信息到控制台的小工具。

## 用法

```c
#include "clogger/clogger.h"

int main() {
    char *tag = "main";
    set_log_level(LV_VERBOSE); // Set log level, LV_VERBOSE is the default
    log_v(tag, "This is a verbose log.");
    log_d(tag, "This is a debug log, arg: %d.", 42);
    log_i(tag, "This is an info log.");
    log_w(tag, "This is a warning log.");
    log_e(tag, "This is an error log.");
    return 0;
}
```
