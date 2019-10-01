/* Public domain. */
extern int login_tty(int);

void foo(void) {
    login_tty(0);
}

int main(void) {
    return 0;
}
