/* Public domain. */
#include <utmpx.h>

void foo(void) {
    struct utmpx ut = {0};
    updwtmpx("/nonexistent", &ut);
}

int main(void) {
    return 0;
}
