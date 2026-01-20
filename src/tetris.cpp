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

bool Area::Checker(int row)
{
    for(int i{0};i<columns;i++){
        if(area[row][i]==0){
            return false;
        }
    }

    for (size_t i {0}; i < 10; i++)
    {
        area[row][i] = 0;
    }
    MoveRowDown(row,1);
    return true;
}


void Area::MoveRowDown(int clearedRow, int numRows)
{
    // Shift all rows above the cleared row down by numRows positions
    for(int row = clearedRow - 1; row >= 0; row--){
        for(int col = 0; col < 10; col++){
            area[row + numRows][col] = area[row][col];
        }
    }
    // Clear the top numRows rows
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < 10; col++){
            area[row][col] = 0;
        }
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