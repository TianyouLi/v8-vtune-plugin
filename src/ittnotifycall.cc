#include "ittnotifycall.h"

ITT_DOMAIN *call__itt_domain_create( const char *name) {
    return __itt_domain_create(name);
}

ITT_STRING_HANDLE *call__itt_string_handle_create( const char *name) {
    return __itt_string_handle_create(name);
}

void call__itt_task_begin(const ITT_DOMAIN *domain,ITT_ID taskid, ITT_ID parentid, ITT_STRING_HANDLE *name) {
    return __itt_task_begin(domain, taskid, parentid, name);
}

void call__itt_task_end(const ITT_DOMAIN *domain) {
    return __itt_task_end(domain);
}

void call__itt_thread_set_name(const char *name) {
    return __itt_thread_set_name(name);
}

void call__itt_thread_ignore(void) {
    return __itt_thread_ignore();
}
