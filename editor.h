#ifndef EDITOR_H
#define EDITOR_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// ctrl macro
#define CTRL_KEY(k) ((k) & 0x1f)

// config
struct editorConfig {
    int cx, cy; // Cursor x-y position
    int screenrows; // Terminal screen rows
    int screencols; // screen column
    struct termios orig_termios; // Original terminal state
}

extern struct editorConfig E;

void enableRawMode();
void disableRawMode();
void initEditor();
void editorRefreshScreen();
void processKeypress();

#endif
