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

#include "libvtune.h"
#include "vtuneapi.h"

shared_ptr<VTuneDomain> domainptr;

std::map<string, int (*)(vector<string>&)> function_map = {
  {"start", startTask},
  {"end", endTask}
};

void split(const string& str, char delimiter, vector<string>& vparams) {
  string::size_type baseindex = 0;
  string::size_type offindex = str.find(delimiter);

  while (offindex != string::npos) {
    vparams.push_back(str.substr(baseindex, offindex-baseindex));
    baseindex = ++offindex;
    offindex = str.find(delimiter, offindex);

    if (offindex == string::npos)
      vparams.push_back(str.substr(baseindex, str.length()));
  }
}

int startTask(vector<string>& vparams) {
  int errcode = 0;

  if(const char* domain_name = vparams[1].c_str()) {
    
    if(const char* task_name = vparams[2].c_str()) {

      if(domainptr = VTuneDomain::createDomain(domain_name)) {

        if(!domainptr->beginTask(task_name)){
          errcode += TASK_BEGIN_FAILED;
        }
      } else {
        errcode += CREATE_DOMAIN_FAILED;
      }
    } else {
      errcode += NO_TASK_NAME;
    }
    
  } else {
    errcode = NO_DOMAIN_NAME;
  }



  return errcode;
}

int endTask(vector<string>& vparams) {
  int errcode = 0;

  if(const char* domain_name = vparams[1].c_str()) {
    
    if(domainptr = VTuneDomain::createDomain(domain_name)) {
        domainptr->endTask();
    } else {
        errcode += CREATE_DOMAIN_FAILED;
    }
  } else {
    errcode = NO_DOMAIN_NAME;
  }



  return errcode;
}

int invoke(const char* params) {

  int errcode = 0;
  vector<string> vparams;

  split(*(new string(params)), ' ', vparams);

  auto it = function_map.find(vparams[0]);
  if(it!= function_map.end()) {
    (it->second)(vparams);
  } else {
    errcode += UNKNOWN_PARAMS;
  }

  return errcode;
}