/* Public domain. */

extern void logwtmp(const char *, const char *, const char *);

void foo(void) {
    logwtmp("", "", "");
}

int main(void) {
    return 0;
}
