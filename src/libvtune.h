#ifndef _LIB_VTUNE_H_
#define _LIB_VTUNE_H_

#include <vector>
#include <string>

using namespace std;

int startTask(vector<string>& vparams);
int endTask(vector<string>& vparams);

#define UNKNOWN_PARAMS       1<<0
#define NO_DOMAIN_NAME       1<<1
#define CREATE_DOMAIN_FAILED 1<<2
#define NO_TASK_NAME       1<<3
#define CREATE_TASK_FAILED 1<<4
#define TASK_BEGIN_FAILED    1<<5
#define TASK_END_FAILED      1<<6

extern "C" {
  extern int invoke(const char* params);
}

#endif

