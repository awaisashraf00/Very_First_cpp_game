#pragma once
#include "tetris.h"
#include "block.h"

class Game{
    private:
        vector<Block> next_block;
        Block current_block;
        Block next_one;
        int flag;
        Block Next_Blocks();
        void Lock_Block();
        void Move_left();
        void Move_right();
        bool Is_outside();
        bool box_fits();
    public:
        void Move_down();
        Game();
        void Drawing();
        void Get_Input();
        Area grid;
};