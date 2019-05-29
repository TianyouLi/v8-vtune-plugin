////////////////////////////////////////////////////////////////////////////////////////////////////
// This dynamic library is the wrapper of interface of the intel VTune Amplifier which enable your 
// application to generate and control the collection of trace data during its execution. 
// Create a task instance/trace the end of the current task:
//    function name:  invoke
//    parameters   :  const char* 
//                    (Its format should be "operation_keyword domain_name task_name". 
//                     And the operation keywords are "start" and "end").
//    return value :  int
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _LIB_VTUNE_H_
#define _LIB_VTUNE_H_

#include <vector>
#include <string>

#define UNKNOWN_PARAMS       1<<0
#define NO_DOMAIN_NAME       1<<1
#define CREATE_DOMAIN_FAILED 1<<2
#define NO_TASK_NAME         1<<3
#define CREATE_TASK_FAILED   1<<4
#define TASK_BEGIN_FAILED    1<<5
#define TASK_END_FAILED      1<<6

extern "C" {
  extern int invoke(const char* params);
}

#endif
