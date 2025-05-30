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
