//
// Created by Richard Chien on 16/5/5.
//

#include "clogger.h"

#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"

LogLevel log_level = LV_VERBOSE;

void set_log_level(LogLevel level) {
    if (level >= LV_VERBOSE && level <= LV_NOTHING) {
        log_level = level;
    }
}

void print_now_time();

void log_base(int level, const char *file, int line, const char *tag, const char *msg, va_list ap);

void log_v_real(const char *file, int line, const char *tag, const char *msg, ...) {
    va_list ap;
    va_start(ap, msg);
    log_base(LV_VERBOSE, file, line, tag, msg, ap);
    va_end(ap);
}

void log_d_real(const char *file, int line, const char *tag, const char *msg, ...) {
    va_list ap;
    va_start(ap, msg);
    log_base(LV_DEBUG, file, line, tag, msg, ap);
    va_end(ap);
}

void log_i_real(const char *file, int line, const char *tag, const char *msg, ...) {
    va_list ap;
    va_start(ap, msg);
    log_base(LV_INFO, file, line, tag, msg, ap);
    va_end(ap);
}

void log_w_real(const char *file, int line, const char *tag, const char *msg, ...) {
    va_list ap;
    va_start(ap, msg);
    log_base(LV_WARNING, file, line, tag, msg, ap);
    va_end(ap);
}

void log_e_real(const char *file, int line, const char *tag, const char *msg, ...) {
    va_list ap;
    va_start(ap, msg);
    log_base(LV_ERROR, file, line, tag, msg, ap);
    va_end(ap);
}

void print_now_time() {
    time_t t = time(NULL);
    struct tm time = *localtime(&t);
    printf("%02d-%02d %02d:%02d:%02d", time.tm_mon, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
}

void log_base(int level, const char *file, int line, const char *tag, const char *msg, va_list ap) {
    char log_level_ch = 0;
    char *color_prefix = "";
    switch (level) {
        case LV_VERBOSE:
            log_level_ch = 'V';
            color_prefix = KNRM;
            break;
        case LV_DEBUG:
            log_level_ch = 'D';
            color_prefix = KBLU;
            break;
        case LV_INFO:
            log_level_ch = 'I';
            color_prefix = KGRN;
            break;
        case LV_WARNING:
            log_level_ch = 'W';
            color_prefix = KYEL;
            break;
        case LV_ERROR:
            log_level_ch = 'W';
            color_prefix = KRED;
            break;
        default:
            break;
    }

    if (level >= log_level) {
        printf("%sLOG ", color_prefix);
        print_now_time();
        printf(" %s:%d %c/%s: ", strrchr(file, '/') ? strrchr(file, '/') + 1 : file, line, log_level_ch, tag);
        vprintf(msg, ap);
        printf(KNRM "\n");
    }
}
