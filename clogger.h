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

void log_v_real(const char *file, int line, const char *tag, const char *msg, ...);

void log_d_real(const char *file, int line, const char *tag, const char *msg, ...);

void log_i_real(const char *file, int line, const char *tag, const char *msg, ...);

void log_w_real(const char *file, int line, const char *tag, const char *msg, ...);

void log_e_real(const char *file, int line, const char *tag, const char *msg, ...);

#define log_v(tag, msg, ...) log_v_real(__FILE__, __LINE__, tag, msg, ## __VA_ARGS__)
#define log_d(tag, msg, ...) log_d_real(__FILE__, __LINE__, tag, msg, ## __VA_ARGS__)
#define log_i(tag, msg, ...) log_i_real(__FILE__, __LINE__, tag, msg, ## __VA_ARGS__)
#define log_w(tag, msg, ...) log_w_real(__FILE__, __LINE__, tag, msg, ## __VA_ARGS__)
#define log_e(tag, msg, ...) log_e_real(__FILE__, __LINE__, tag, msg, ## __VA_ARGS__)

#endif //CLOGGER_H
