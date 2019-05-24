#ifndef _LIB_VTUNE_H_
#define _LIB_VTUNE_H_

#define UNKNOWN_PARAMS       1<<0
#define NO_DOMAIN_NAME       1<<1
#define CREATE_DOMAIN_FAILED 1<<2
#define NO_HANDLE_NAME       1<<3
#define CREATE_HANDLE_FAILED 1<<4
#define TASK_BEGIN_FAILED    1<<5
#define TASK_END_FAILED      1<<6
#define SET_THREAD_NAME_FAILED 1<<7
#define IGNORE_THREAD_FAILED 1<<8

extern "C" {
  extern int invoke(const char* params);
}

#endif
