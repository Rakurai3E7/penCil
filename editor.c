#include "editor.h"

struct editorConfig E;

void die(const char *s) {
    perror(s);
    exit(1);
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios);
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcgetattr");
    atexit(disableRawMode);

    struct termios raw = E.orig_termios;
    
}
