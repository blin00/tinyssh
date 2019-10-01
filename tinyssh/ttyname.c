#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "ttyname.h"

char *_ttyname(int fd) {
    static char buf[128];
    char tmp[32];

    if (!isatty (fd)) {
        return NULL;
    }

    if (snprintf (tmp, 32, "/proc/self/fd/%d", fd) >= sizeof (tmp)) {
        errno = ERANGE;
        return NULL;
    }

    ssize_t ret = readlink (tmp, buf, sizeof (buf));
    if (ret < 0) {
        return NULL;
    }
    if (ret >= sizeof (buf)) {
        errno = ERANGE;
        return NULL;
    }

    buf[ret] = '\0';
    return buf;
}
