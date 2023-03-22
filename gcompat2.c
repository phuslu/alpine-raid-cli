#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

/* The mbrlen function has an internal shift state which gets used if
   the PS parameter is NULL.  */
static mbstate_t internal;
size_t
__mbrlen (const char *s, size_t n, mbstate_t *ps)
{
  return mbrtowc (NULL, s, n, ps ?: &internal);
}

char *
__strdup (const char *s)
{
  return strdup(s);
}

int
pthread_mutexattr_setkind_np (pthread_mutexattr_t * attr, int kind)
{
  return pthread_mutexattr_settype (attr, kind);
}

double __strtod_internal(const char * nptr, char * * endptr, int __group)
{
	return strtod(nptr, endptr);
}

