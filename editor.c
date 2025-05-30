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
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    raw.c_cflag |= ~(CS8);
    raw.c_oflag &= ~(OPOST);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

int getWindowSize(int *rows, int *cols) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) return -1;
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
}

void initEditor() {
    E.cx = 0;
    E.cy = 0;

    if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
}

void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J]", 4);
    write(STDOUT_FILENO, "\x1b[H]", 3);

    for (int y = 0; y < E.screenrows; y++) {
        write(STDOUT_FILENO, "~\r\n", 3);
    }
}

// super mininmal key input
void processKeypress() {
    char c;
    if (read(STDIN_FILENO, &c, 1) == -1) return;

    if (c == CTRL_KEY('q')) {
        write(STDOUT_FILENO, "\x1b[2J]", 4); // clear screen
        write(STDOUT_FILENO, "\x1b[H]", 3); // move home
        exit(0);
    }
}
