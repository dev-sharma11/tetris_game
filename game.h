#pragma once
#include"grid.h"
#include"blocks.cpp"
#include <bits/stdc++.h>


class Game{
public:
Game();

~Game();

void Draw();
void handleinput();
void moveblockdown();
bool gameover;
int score;
Music music;


private:
Block getrandomblock();
vector<Block> getallblocks();
bool isblockoutside();
void rotateblock();
void moveblockleft();
void moveblockright();
void reset();
void lockblock();
bool blockfits();
void updatescore(int linescleared , int movedownpoints);
vector<Block> blocks;
Block currentblock;
Block nextblock;
Grid grid;
Sound rotatesound;
Sound clearsound;

};