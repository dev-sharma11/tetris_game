#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = getallblocks();
    currentblock = getrandomblock();
    nextblock = getrandomblock();
    gameover = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotatesound = LoadSound("Sounds/rotate.mp3");
    clearsound  = LoadSound("Sounds/clear.mp3"); 
}
Game::~Game(){
    UnloadSound(rotatesound);
    UnloadSound(clearsound);
    UnloadMusicStream(music);
    CloseAudioDevice();   
}

Block Game::getrandomblock(){
if(blocks.empty()){
blocks = getallblocks();
}  
srand(time(0)); 
int randomindex = rand()%blocks.size();
Block block = blocks[randomindex];
blocks.erase(blocks.begin()+randomindex);
return block;
}

vector<Block> Game :: getallblocks(){
    return {iblock(),jblock(),lblock(),oblock(),sblock(),tblock(),zblock()};
}

void Game :: Draw(){

grid.Draw();
currentblock.Draw(11,11);
switch (nextblock.id)
{
case 3:
    nextblock.Draw(255,290);
    break;
case 4:
    nextblock.Draw(255,280);
    break;
default:
    nextblock.Draw(270,270);
    break;

}


}

void Game::handleinput() {

    int keypressed = GetKeyPressed();

    if(gameover && keypressed == KEY_ENTER){
        gameover = false;
        reset();
    }

    switch(keypressed){

    case KEY_LEFT:
    moveblockleft();
    break;
    case KEY_RIGHT:
    moveblockright();
    break;
    case KEY_DOWN:
    moveblockdown();
    if(!gameover){
    updatescore(0,1);
    }
    break;
    case KEY_SPACE:
    rotateblock();
    break;

    }
}

void Game::moveblockleft() {
    if(!gameover){
    currentblock.move(0,-1);
    if(isblockoutside() || blockfits() == false){
    currentblock.move(0,1);
    }
}
}


void Game::moveblockright() {
    if(!gameover){
    currentblock.move(0,1);
    if(isblockoutside() || blockfits() == false){
    currentblock.move(0,-1);
    }
}
}



void Game::moveblockdown() {
    if(!gameover){
    currentblock.move(1,0);
    if(isblockoutside() || blockfits() == false){
    currentblock.move(-1,0);
    lockblock();
    }
}
}

bool Game::isblockoutside()
{
    vector<Position> tiles = currentblock.getcellpositions();
    for(auto it:tiles){
        
        if(grid.iscelloutside(it.row,it.col)){
            return true;
        }

    }
    return false;
}
void Game::rotateblock() {
    if(!gameover){
    currentblock.rotate();
    if(isblockoutside() || blockfits() == false){
        currentblock.undorotate();
    }else{
        PlaySound(rotatesound);
    }
}
}

void Game::reset()
{
    grid.initilize();
    blocks = getallblocks();
    currentblock = getrandomblock();
    nextblock = getrandomblock();
    score = 0;
}

void Game::lockblock() {

vector<Position> tiles = currentblock.getcellpositions();
for(Position item: tiles){
    grid.grid[item.row][item.col] = currentblock.id;
}
 currentblock = nextblock;
 if(!blockfits()){
    gameover = true;
 }
 nextblock = getrandomblock();
 int rowscleared = grid.clearfullrows();
 if(rowscleared > 0){
    PlaySound(clearsound);
    updatescore(rowscleared,0);
 }

}
bool Game::blockfits() {

    vector<Position> tiles = currentblock.getcellpositions();
    for(Position it : tiles){
        if(grid.iscellempty(it.row,it.col) == false){
            return false;
        }
    }
    return true;
}
void Game::updatescore(int linescleared , int movedownpoints) {

    switch(linescleared){
    
    case 0:
    break;
    case 1:
    score += 100;
    break;
    case 2:
    score += 300;
    break;
    case  3:
    score += 500;
    default:
    score += 500;
    break;

    }
    
    score += movedownpoints; 
};