# pragma once
#include <bits/stdc++.h>
#include "position.h"
#include "color.h"
using namespace std;

class Block{
public:
Block();  
int id;
map<int,vector<Position>> cells;
void Draw(int offsetx , int offsety);
void move(int rows,int coloums);
vector<Position> getcellpositions();
void rotate();
void undorotate();


private:
int cellsize;
int rotationstate;
vector<Color> colors;
int rowoffset;
int coloffset;

};