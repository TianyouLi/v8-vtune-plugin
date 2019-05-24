#include <string.h>
#include <ittnotify.h>

#include "libvtune.h"

int invoke(const char* params) {

  int result = 0;

  static __itt_domain* domain = NULL;

  if(strncmp(params, "init:", 5) == 0) {
	  domain = __itt_domain_create(params + 5);
  } else if (strncmp(params, "start:", 6) == 0) {
    __itt_string_handle* handle_start = __itt_string_handle_create(params + 6);
	  __itt_task_begin(domain, __itt_null, __itt_null, handle_start);
  } else if (strncmp(params, "end", 3) == 0) {
	  __itt_task_end(domain);
  } else if (strncmp(params, "name:", 5) == 0) {
    __itt_thread_set_name(params + 5);
  } else if (strncmp(params, "ignore", 6) == 0) {
	  __itt_thread_ignore();
  } else {
	  result = 1;
  }

  return result;
}
