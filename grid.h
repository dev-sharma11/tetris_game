#pragma once
#include <vector>
#include <raylib.h>
#include <bits/stdc++.h>


class Grid{

public:
Grid();

int grid[20][10];

void initilize();
void print();
void Draw();
bool iscelloutside(int row,int col);
bool iscellempty(int row,int col);
int clearfullrows();

private:
bool isrowfull(int row);
void clearrow(int row);
void moverowdown(int row,int numofrows);
int numrows;
int numcols;
int cellsize;
std::vector<Color> colors;
};