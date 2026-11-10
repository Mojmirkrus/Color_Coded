#include "common/used_functions.c"

int main(void) {

    const int Window_Length = 1920;
    const int Window_Width = 1080;

    InitWindow(Window_Length, Window_Width, "Main_Game_Window");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("TESTING DRAWING TEXT IN WINDOW", 190, 200, 20, LIGHTGRAY);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
