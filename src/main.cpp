#include "raylib.h"
#include "Game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(300, 600, "My First raylib Game");
    SetTargetFPS(60);
    Game game = Game();

    while(WindowShouldClose() == false) 
    {
        BeginDrawing();

        if(game.Game_over()){
            
            game.Get_Input();

            if(EventTriggered(0.2)){
                game.Move_down();
            }
            ClearBackground({255, 255, 255, 255});
            game.Drawing();
        }else{
            game.Drawing();
            ClearBackground({232, 18, 18, 255});
        }    
        EndDrawing();
    }

    CloseWindow();
    return 0;
}