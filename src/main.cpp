#include "raylib.h"
#include "tetris.h"
#include "block.h"

int main() 
{
    InitWindow(600, 700, "My First raylib Game");
    

    Area surface = Area();
    LBlock peice = LBlock();
    peice.Draw();
    while(WindowShouldClose() == false) 
    {
        BeginDrawing();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}