#include <string.h>
#include <ittnotify.h>

#include "libvtune.h"

int invoke(const char* params) {

  int errcode = 0;

  static __itt_domain* domain = NULL;

  if(strncmp(params, "init:", 5) == 0) {
    if(*(params+5)) {
      domain = __itt_domain_create(params + 5);
      if(!domain) {
        errcode += CREATE_DOMAIN_FAILED;
      }
    } else {
      errcode += NO_DOMAIN_NAME;
    }
  } else if (strncmp(params, "start:", 6) == 0) {
    if(*(params + 6)) {
      __itt_string_handle* handle_start = __itt_string_handle_create(params + 6);
      if(handle_start) {
        __itt_task_begin(domain, __itt_null, __itt_null, handle_start);
      } else {
        errcode += CREATE_HANDLE_FAILED;
      }
      
    } else {
      errcode += NO_HANDLE_NAME;
    }
  } else if (strncmp(params, "end", 3) == 0) {
	  __itt_task_end(domain);
  } else if (strncmp(params, "name:", 5) == 0) {
    if(*(params + 5)) {
      __itt_thread_set_name(params + 5);
    } else {
      errcode += SET_THREAD_NAME_FAILED;
    }
  } else if (strncmp(params, "ignore", 6) == 0) {
    __itt_thread_ignore();
  } else {
	  errcode += UNKNOWN_PARAMS;
  }

  return errcode;
}
