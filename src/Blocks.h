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
        void Move(int x , int y);
        vector<Position> New_coordinates();
        void Draw();
        void rotate();
        bool Is_rotatable();
        int rotation{0};
    private:
        vector<Color> colors;
        int cellSize = 30;
        int rows_away;
        int columns_away;
};