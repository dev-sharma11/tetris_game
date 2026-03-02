#include "grid.h"
#include <iostream>
#include"color.h"
Grid::Grid(){

numrows = 20;
numcols = 10;
cellsize = 30;

initilize();
colors = getcellcolor(); 
}

void Grid::initilize(){

for(int row = 0; row < numrows; row++){

for(int col = 0; col < numcols; col++){
    grid[row][col] = 0;
}

}
}

void Grid::print(){

for(int row = 0; row < numrows; row++){

for(int col = 0; col < numcols; col++){
   std::cout << grid[row][col] << " ";
}
std::cout << std::endl;
}
}


void Grid :: Draw(){

for(int row = 0; row < numrows; row++){

for(int col = 0; col < numcols; col++){
    int cellvalue = grid[row][col];

    DrawRectangle(col*cellsize+11,row*cellsize+11,cellsize-1,cellsize-1,colors[cellvalue]);


}

}


}

bool Grid::iscelloutside(int row,int col)
{
    if(row >= 0 && row < numrows && col >= 0 && col < numcols){
        return false;
    }
    return true;
}

bool Grid::iscellempty(int row, int col)
{
    if(grid[row][col] == 0){
        return true;
    }else{
        return false;
    }
    }

    int Grid::clearfullrows()
    {
        int completed =  0;
        for(int row = numrows - 1; row >= 0; row--){
        if(isrowfull(row)){
            clearrow(row);
            completed++;
        }else if(completed > 0){
          moverowdown(row,completed);  
        }
        }
        return completed;
    }

    bool Grid::isrowfull(int row)
    {   
        for(int col = 0; col < numcols ; col++){
            if(grid[row][col] == 0){
                return false;
            }
        }
        return true;
    }

    void Grid::clearrow(int row)
    {
        for(int col = 0; col < numcols ; col++){
            grid[row][col] = 0;
        }
    }

    void Grid::moverowdown(int row, int numofrows)
    {

    for(int col = 0; col < numcols ; col++){

    grid[row+numofrows][col] = grid[row][col];
    grid[row][col] = 0;

    }

    }
