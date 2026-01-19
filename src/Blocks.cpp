#include "Blocks.h"
#include "block.h"


Block::Block(){
    colors = get_colors();
    rows_away = 0;
    columns_away = 0;
};

void Block::Draw(){
    vector<Position> boxes = New_coordinates();
    for(Position box: boxes){
        DrawRectangle(box.x_pos*cellSize+1  ,box.y_pos*cellSize+1   , cellSize-1  , cellSize-1  ,colors[id]);
    }
}

void Block::rotate()
{
    if(rotation<3){
        rotation++;
    }else{
        rotation = 0;
    }
}

bool Block::Is_rotatable()
{
    vector<Position> pos = New_coordinates();
    for(auto p:pos){
        if(p.x_pos<0||p.x_pos>9){
            return false;
        }
    }
    return true;
}


void Block::Move(int column,int row){
    if(rows_away+column<=20){
        rows_away += column;
    }
    if(columns_away+row<=10){
        columns_away += row;
    }
}

vector<Position> Block::New_coordinates(){
    vector<Position> new_pos = cell_address[rotation]; 
    vector<Position> new_coordinates; 
    
    for(Position box : new_pos){
        Position n = Position(box.x_pos + columns_away,box.y_pos + rows_away);
        new_coordinates.push_back(n);
    }
    return new_coordinates;
}
