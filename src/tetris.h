#pragma once
#include<vector>
#include "raylib.h"
using namespace std;

class Area{
    public:
        Area();
        int area[20][10];
        void Print();
        void Draw_rects();
        void filler();
    private:
        int rows = 20;
        int columns = 10;
        int cellSize = 45;
        vector<Color> colors;
};