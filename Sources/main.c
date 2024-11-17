#include <stdio.h>
#include "distractfree.h"

int main(void)
{
    int mainMonitor;
    int monitorCount;
    char monitorStr[1024];
    Color bg = (Color) {0, 0, 0, 255};
    int flags = FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNFOCUSED;

    SetConfigFlags(flags);
    flags |= FLAG_WINDOW_UNDECORATED;
    InitWindow(1, 1, "Settings");
    mainMonitor = GetCurrentMonitor();
    monitorCount = GetMonitorCount();
    CloseWindow();

    mainLoop(monitorCount, mainMonitor, monitorStr, flags);

    return 0;
}
