#include <string.h>
#include "ittnotifycall.h"
#include "libvtune.h"

int invoke(const char* params) {

  int errcode = 0;

  static ITT_DOMAIN* domain = NULL;

  if(strncmp(params, "init:", 5) == 0) {
    if(*(params+5)) {
      domain = call__itt_domain_create(params + 5);
      if(!domain) {
        errcode += CREATE_DOMAIN_FAILED;
      }
    } else {
      errcode += NO_DOMAIN_NAME;
    }
  } else if (strncmp(params, "start:", 6) == 0) {
    if(*(params + 6)) {
      ITT_STRING_HANDLE* handle_start = call__itt_string_handle_create(params + 6);
      if(handle_start) {
        call__itt_task_begin(domain, __itt_null, __itt_null, handle_start);
      } else {
        errcode += CREATE_HANDLE_FAILED;
      }
      
    } else {
      errcode += NO_HANDLE_NAME;
    }
  } else if (strncmp(params, "end", 3) == 0) {
	  call__itt_task_end(domain);
  } else if (strncmp(params, "name:", 5) == 0) {
    if(*(params + 5)) {
      call__itt_thread_set_name(params + 5);
    } else {
      errcode += SET_THREAD_NAME_FAILED;
    }
  } else if (strncmp(params, "ignore", 6) == 0) {
    call__itt_thread_ignore();
  } else {
	  errcode += UNKNOWN_PARAMS;
  }

  return errcode;
}
