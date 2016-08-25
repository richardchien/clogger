//
// Created by Richard Chien on 16/5/5.
//

#ifndef CLOGGER_H
#define CLOGGER_H

typedef enum {
    LV_VERBOSE = 0,
    LV_DEBUG,
    LV_INFO,
    LV_WARNING,
    LV_ERROR,
    LV_NOTHING
} LogLevel;

void set_log_level(LogLevel level);

void log_v(const char *tag, const char *msg, ...);

void log_d(const char *tag, const char *msg, ...);

void log_i(const char *tag, const char *msg, ...);

void log_w(const char *tag, const char *msg, ...);

void log_e(const char *tag, const char *msg, ...);

#endif //CLOGGER_H
