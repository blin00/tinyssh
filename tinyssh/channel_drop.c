/*
20140129
Jan Mojzis
Public domain.
*/

#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include "dropuidgid.h"
#include "newenv.h"
#include "channel.h"
#include "ttyname.h"

const char *default_shell = "/system/xbin/bash";

int channel_droppriv(char *user, char **shell) {

    char *name;

    if (isatty(0)) {
        name = _ttyname(0);
        if (!name) return 0;
        if (!newenv_env("SSH_TTY", name)) return 0;
        /* setowner */
        if (chown(name, 0, 0) == -1) return 0;
        if (chmod(name, 0600) == -1) return 0;
    }

    /* drop privileges */
    if (!dropuidgid("root", 0, 0)) return 0;

    if (chdir("/data/local/root") == -1) return 0;
    if (!newenv_env("HOME", "/data/local/root")) return 0;
    if (!newenv_env("USER", "root")) return 0;
    if (!newenv_env("LOGNAME", "root")) return 0;
    if (!newenv_env("LOGIN", "root")) return 0;
    if (!newenv_env("SHELL", default_shell)) return 0;

    *shell = default_shell;
    return 1;
}
