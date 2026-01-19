#include "tetris.h"
#include "color.h"
#include<iostream>
using namespace std;
Area::Area(){
    filler();
    colors = get_colors();
    Draw_rects();
};

void Area::filler(){
    for(int i{0};i<rows;i++){
        for(int j{0};j<columns;j++){
            area[i][j] = 0;
        }
    }
}

bool Area::Iscelloutside(int col,int row)
{
    if (row>=0 && row<rows && col<columns && col>=  0){
        return false;
    }
    return true;
}

bool Area::Iscellempty(int x, int y)
{
    if (area[y][x]==0){
        return true;
    }else{
        return false;
    }

}

void Area::Draw_rects(){
    for (size_t i = 0; i < rows ; i++)   
    {
        for (size_t j = 0; j < columns; j++)
        {
            int rang = area[i][j];
            DrawRectangle(j*  cellSize+1 ,i*  cellSize+1  ,  cellSize-1 ,  cellSize-1 ,colors[rang]);
        }   
    } 
}