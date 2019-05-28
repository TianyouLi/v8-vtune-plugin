#include "vtuneapi.h"

std::map<std::string, std::shared_ptr<VTuneDomain>> VTuneDomain::domains_;
std::map<std::string, __itt_string_handle*> VTuneDomain::string_handlers_;


std::shared_ptr<VTuneDomain> VTuneDomain::createDomain(const char* domain_name)
{
  auto domain = getDomain(domain_name);
  
  if (domain == nullptr) {
    __itt_domain* itt_domain = __itt_domain_create(domain_name); // call api
    if (itt_domain != NULL) {
      std::string key(domain_name);
      std::shared_ptr<VTuneDomain> value(new VTuneDomain(itt_domain));
      domain = value;
      domains_.insert(std::make_pair(key, value));
    }
  }

  return domain;
}

void VTuneDomain::destroyDomain(const char* domain_name)
{
  auto it = domains_.find(domain_name);
  if (it != domains_.end()) {
    domains_.erase(it);
  }
}

std::shared_ptr<VTuneDomain> VTuneDomain::getDomain(const char* domain_name)
{
  std::shared_ptr<VTuneDomain> result(nullptr) ;
  
  auto it = domains_.find(domain_name);
  if (it!= domains_.end()) {
    result = it->second;
  }

  return result;
}

__itt_string_handle* VTuneDomain::getString(const char* str)
{
  __itt_string_handle* result = NULL;
  
  auto it = string_handlers_.find(str);
  if (it != string_handlers_.end()) {
    result = it->second;
  } else {
    result = __itt_string_handle_create(str); // call api
    std::string key(str);
    string_handlers_.insert(std::make_pair(key, result));
  }

  return result;
}

bool VTuneDomain::beginTask(const char* task_name)
{
  bool result = false;
  
  __itt_string_handle* name = getString(task_name);
  if (name != NULL) {
    __itt_task_begin(domain_, __itt_null, __itt_null, name);
    result = true;
  }
  
  return result;
}

void VTuneDomain::endTask()
{
  __itt_task_end(domain_);
}
