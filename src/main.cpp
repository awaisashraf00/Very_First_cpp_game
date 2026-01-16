#include "raylib.h"
#include "tetris.h"

int main() 
{
    InitWindow(600, 700, "My First raylib Game");
    SetTargetFPS(60);

    Area surface = Area();
    surface.Print();

    while(WindowShouldClose() == false) 
    {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}