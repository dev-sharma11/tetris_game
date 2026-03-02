#include"block.h"

Block::Block(){

cellsize = 30;
rotationstate = 0;
colors = getcellcolor();
rowoffset = 0;
coloffset = 0;
}
void Block :: Draw(int offsetx,int offsety){

vector<Position> tiles = getcellpositions();
for(Position item: tiles){
    DrawRectangle(item.col*cellsize+offsetx,item.row*cellsize+offsety,cellsize-1,cellsize-1,colors[id]);
}

}

void Block :: move(int rows,int coloums){
    rowoffset += rows;
    coloffset += coloums;
}

vector<Position> Block :: getcellpositions(){
vector<Position> tiles = cells[rotationstate];
vector<Position> movetiles;  
for(Position item: tiles){
    Position newpos = Position(item.row+rowoffset,item.col+coloffset);
    movetiles.push_back(newpos);
}
return movetiles;
}

void Block::rotate()
{
    rotationstate = (rotationstate+1)%4;
}

void Block::undorotate()
{   
    rotationstate = (rotationstate+3)%4;
}
