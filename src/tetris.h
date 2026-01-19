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
        bool Iscelloutside(int x,int y);
        bool Iscellempty(int x,int y);
    private:
        int rows = 20;
        int columns = 10;
        int cellSize = 30;
        vector<Color> colors;
};