#include "Blocks.h"
#include "block.h"


Block::Block(){
    colors = get_colors();
};

void Block::Draw(){
    vector<Position> boxes = cell_address[rotation];
    for(Position box: boxes){
        DrawRectangle(box.x_pos*cellSize+1  ,box.y_pos*cellSize+1   , cellSize-1  , cellSize-1  ,colors[id]);
    }
}