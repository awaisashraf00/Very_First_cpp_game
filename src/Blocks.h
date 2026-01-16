#pragma once
#include<map>
#include<vector>
#include "Position.h"
#include "color.h"

class Block{
    public:
        Block();
        int id;
        map<int,vector<Position>> cell_address;
        void Draw();
    private:
        vector<Color> colors;
        int cellSize = 45;
        int rotation{0};
    
};