#include "libvtune.h"
#include "vtuneapi.h"

using namespace std;

int startTask(const std::vector<std::string>& vparams);
int endTask(const std::vector<std::string>& vparams);

map<string, int (*)(const vector<string>&)> function_map = {
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

int startTask(const vector<string>& vparams) {
  int errcode = 0;

  if (const char* domain_name = vparams[1].c_str()) {
    
    if (const char* task_name = vparams[2].c_str()) {

      if (shared_ptr<VTuneDomain> domainptr = VTuneDomain::createDomain(domain_name)) {

        if (!domainptr->beginTask(task_name)){
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

int endTask(const vector<string>& vparams) {
  int errcode = 0;

  if (const char* domain_name = vparams[1].c_str()) {
    
    if (shared_ptr<VTuneDomain> domainptr = VTuneDomain::createDomain(domain_name)) {
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
  if (it!= function_map.end()) {
    (it->second)(vparams);
  } else {
    errcode += UNKNOWN_PARAMS;
  }

  return errcode;
}