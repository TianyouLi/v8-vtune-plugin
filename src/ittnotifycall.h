#ifndef _ITT_NOTIFY_CALL_H_
#define _ITT_NOTIFY_CALL_H_

#include <ittnotify.h>

#define ITT_DOMAIN __itt_domain
#define ITT_STRING_HANDLE __itt_string_handle
#define ITT_ID __itt_id

ITT_DOMAIN *call__itt_domain_create( const char *name);
ITT_STRING_HANDLE *call__itt_string_handle_create( const char *name);
void call__itt_task_begin(const ITT_DOMAIN *domain,__itt_id taskid, __itt_id parentid, ITT_STRING_HANDLE *name);
void call__itt_task_end(const ITT_DOMAIN *domain);
void call__itt_thread_set_name(const char *name);
void call__itt_thread_ignore(void);

#endif    // _ITT_NOTIFY_CALL_H_