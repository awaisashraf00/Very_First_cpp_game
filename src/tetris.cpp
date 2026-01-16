#include "tetris.h"
#include "color.h"
#include<iostream>

Area::Area(){
    filler();
    colors = get_colors();
    Draw_rects();
};

void Area::filler(){
    for(int i{0};i<rows-1;i++){
        for(int j{0};j<columns-1;j++){
            area[i][j] = 0;
        }
    }
}

void Area::Print(){
    for(int i{0};i<rows-1;i++){
        for(int j{0};j<columns-1;j++){
            cout << area[i][j]<<" ";
        }
        cout << ""<<endl;;

    }
}

void Area::Draw_rects(){
    for (size_t i = 0; i < rows -1 ; i++)
    {
        for (size_t j = 0; j < columns -1; j++)
        {
            int rang = area[i][j];
            DrawRectangle(j*  cellSize+1 ,i*  cellSize+1  ,  cellSize-1 ,  cellSize-1 ,colors[rang]);
        }   
    } 
}