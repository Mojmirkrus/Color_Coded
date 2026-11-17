#include "common/used_functions.c"
//!!DON'T!!//gcc main.c -o Color_Coded.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
//Use CLion's own compiler or ensure you have a compatible compiler installed, the above command runs an older compiler(at least on some pc's).

int main(void) {

    const int Window_Width = 1200;
    const int Window_Height = 675;

    InitWindow(Window_Width, Window_Height, "Color_Coded Main_Window");

    int Current_FPS = 60;

    Vector2 CircleOne = { 0, (float)Window_Height/3.0f };
    Vector2 CircleTwo = { 0, (float)Window_Height*(2.0f/3.0f) };

    const float Default_Speed = 10.0f;
    const float Circle_Speed = Default_Speed;

    const float Default_Radius = 32.0f;
    const float Circle_Radius = Default_Radius;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        float MouseWheel_Move = GetMouseWheelMove();
        if (MouseWheel_Move != 0) {
            Current_FPS += (int)MouseWheel_Move;
            if (Current_FPS < 0) Current_FPS = 0;
            SetTargetFPS(Current_FPS);
        }

        CircleOne.x += GetFrameTime()*6.0f*Circle_Speed;
        CircleTwo.x += GetFrameTime()*12.0f*Circle_Speed;

        if (CircleOne.x > Window_Width) CircleOne.x = 0;
        if (CircleTwo.x > Window_Width) CircleTwo.x = 0;
        if (CircleOne.x < 0) CircleOne.x = Window_Width;
        if (CircleTwo.x < 0) CircleTwo.x = Window_Width;

        if (IsKeyPressed(KEY_R)) {
            CircleOne.x = 0;
            CircleTwo.x = 0;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleV(CircleOne, Circle_Radius, RED);
            DrawCircleV(CircleTwo, Circle_Radius, BLUE);

            const char *FPS_Text = 0;
            if (Current_FPS <= 0) FPS_Text = TextFormat("FPS: unlimited (%i)", GetFPS());
            else FPS_Text = TextFormat("FPS: %i (target: %i)", GetFPS(), Current_FPS);
            DrawText(FPS_Text, 10, 10, 20, DARKGRAY);
            DrawText(TextFormat("Frame time: %02.02f ms", GetFrameTime()*1000.0f), 10, 30, 20, DARKGRAY);
            DrawText("Use the scroll wheel to change the fps limit, r to reset", 10, 50, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
