#include <stdio.h>
#include "distractfree.h"

int main(void)
{
    int mainMonitor;
    int monitorCount;
    char monitorStr[1024];
    Color bg = (Color) {0, 0, 0, 255};
    int flags = 0;

    SetConfigFlags(flags);
    InitWindow(1, 1, "Settings");
    mainMonitor = GetCurrentMonitor();
    monitorCount = GetMonitorCount();
    CloseWindow();

    mainLoop(monitorCount, mainMonitor, monitorStr, flags);

    return 0;
}
