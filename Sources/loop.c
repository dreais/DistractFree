//
// Created by Valentin on 12/03/2023.
//

#include <stdio.h>
#include "distractfree.h"

void mainLoop(int monitorCount, int mainMonitor, char *monitorStr, int flags)
{
    Color bg = (Color) {0, 0, 0, 255};

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
    InitWindow(740, 80, "Quit");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color) {34, 34, 34, 255});
        DrawText("Press ESC to quit", 0, 0, 80, WHITE);
        EndDrawing();
    }
    CloseWindow();
}