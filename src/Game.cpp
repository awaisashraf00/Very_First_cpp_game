#include "Game.h"
#include "Blocks.h"
#include<random>


Game::Game(){
    grid  = Area();
    next_block = {LBlock(),JBlock(),IBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
    current_block = Next_Blocks();
}


Block Game::Next_Blocks(){
    if(next_block.empty()){
        next_block = {LBlock(),JBlock(),IBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
    }
    int r = rand() %next_block.size();
    Block another_block = next_block[r];
    next_block.erase(next_block.begin()+r);
    return another_block;

}

void Game::Drawing(){
    grid.Draw_rects();
    current_block.Draw();    
}


void Game::Get_Input(){
    int key = GetKeyPressed();
    switch (key)
    {
    case KEY_LEFT:
        Move_left();
        break;
    case KEY_RIGHT:
        Move_right();
        break;
    case KEY_DOWN:
        Move_down();
        break;
    case KEY_ENTER:
        if(current_block.id!=4){
            int old_rotation = current_block.rotation;
            current_block.rotate();
            if(!current_block.Is_rotatable()){
                current_block.rotation = old_rotation;
            }
        }
        break;
    }
}


bool Game::Is_outside()
{
    vector<Position> box = current_block.New_coordinates();
    for(auto block:box){
        if (grid.Iscelloutside(block.x_pos,block.y_pos)){
            return true;
        }
    }
    return false;
}

bool Game::box_fits()
{
    vector<Position> pos = current_block.New_coordinates();
    for(auto p:pos){
        if(grid.Iscellempty(p.x_pos,p.y_pos)==false){
            return false;
        }
    }
    return true;    
            
}

void Game::Lock_Block(){
    vector<Position> box = current_block.New_coordinates();
    for(auto b:box){
        grid.area[b.y_pos][b.x_pos] = current_block.id;
    }
    next_one = Next_Blocks();
    current_block = next_one;
    

}

void Game::Move_left(){
    current_block.Move(0,-1);
    if (Is_outside()){
        current_block.Move(0,1);
    }
}


void Game::Move_right(){
    current_block.Move(0,1);
    if (Is_outside()){
        current_block.Move(0,-1);
    }
    
}

void Game::Move_down(){
    current_block.Move(1,0);
    if (Is_outside()||box_fits() != true){
        current_block.Move(-1,0);
        Lock_Block();
    }
}
