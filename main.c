#define _POSIX_C_SOURCE 200809L

#include "editor.h"

int main()
{
    enableRawMode();
    initEditor();

    while (1) {
        editorRefreshScreen();
        processKeypress();
    }
    return 0;
}
