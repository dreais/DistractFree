#include <stdio.h>
#include "raylib.h"

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
    for (int i = 0; i < monitorCount; i++) {
        if (i != mainMonitor) {
            InitWindow(0, 0, "Relax!");
            SetWindowMonitor(i);
            Vector2 pos = {.x = ((float) GetScreenWidth() - (float) MeasureText(monitorStr, 80)) / 2,
                    .y = ((float) GetScreenHeight() - 80) / 2};
            BeginDrawing();
            ClearBackground(bg);
            sprintf(monitorStr, "Relax!", GetCurrentMonitor());
            DrawText(monitorStr, (int) pos.x, (int) pos.y, 80, (Color ){0, 0, 0, 200});
            DrawText(monitorStr, (int) pos.x - 3, (int) pos.y - 3, 80, WHITE);
            EndDrawing();
        }
    }
    SetConfigFlags(flags & FLAG_WINDOW_UNDECORATED & FLAG_WINDOW_UNFOCUSED);
    InitWindow(600, 600, "Quit");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color) {34, 34, 34, 255});
        DrawText("Press ESC to", 0, 0, 80, WHITE);
        DrawText("quit", 0, 80, 80, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
