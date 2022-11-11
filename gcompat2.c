#include <wchar.h>
#include <string.h>
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

