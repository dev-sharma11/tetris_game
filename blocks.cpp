#include "block.h"
#include "position.h"

class lblock : public Block{
public:
lblock(){
id = 1;
cells[0] = {Position{0,2},Position{1,0},Position{1,1},Position{1,2}};
cells[1] = {Position{0,1},Position{1,1},Position{2,1},Position{2,2}};
cells[2] = {Position{2,0},Position{1,0},Position{1,1},Position{1,2}};
cells[3] = {Position{0,0},Position{0,1},Position{1,1},Position{2,1}};
move(0,3);
}
};

class jblock : public Block{
public:
jblock(){
id = 2;
cells[0] = {Position{0,0},Position{1,0},Position{1,1},Position{1,2}};
cells[1] = {Position{0,1},Position{0,2},Position{1,1},Position{2,1}};
cells[2] = {Position{1,0},Position{1,1},Position{1,2},Position{2,2}};
cells[3] = {Position{0,1},Position{1,1},Position{2,0},Position{2,1}};
move(0,3);
}
};

class iblock : public Block{
public:
iblock(){
id = 3;
cells[0] = {Position{1,0},Position{1,1},Position{1,2},Position{1,3}};
cells[1] = {Position{0,2},Position{1,2},Position{2,2},Position{3,2}};
cells[2] = {Position{2,0},Position{2,1},Position{2,2},Position{2,3}};
cells[3] = {Position{0,1},Position{1,1},Position{2,1},Position{3,1}};
move(-1,3);
}
};

class oblock : public Block{
public:
oblock(){
id = 4;
cells[0] = {Position{0,0},Position{0,1},Position{1,0},Position{1,1}};
cells[1] = {Position{0,0},Position{0,1},Position{1,0},Position{1,1}};
cells[2] = {Position{0,0},Position{0,1},Position{1,0},Position{1,1}};
cells[3] = {Position{0,0},Position{0,1},Position{1,0},Position{1,1}};
move(0,4);
}
};

class sblock : public Block{
public:
sblock(){
id = 5;
cells[0] = {Position{0,1},Position{0,2},Position{1,0},Position{1,1}};
cells[1] = {Position{0,1},Position{1,1},Position{1,2},Position{2,2}};
cells[2] = {Position{1,1},Position{1,2},Position{2,0},Position{2,1}};
cells[3] = {Position{0,0},Position{1,0},Position{1,1},Position{2,1}};
move(0,3);
}
};

class tblock : public Block{
public:
tblock(){
id = 6;
cells[0] = {Position{0,1},Position{1,0},Position{1,1},Position{1,2}};
cells[1] = {Position{0,1},Position{1,1},Position{1,2},Position{2,1}};
cells[2] = {Position{1,0},Position{1,1},Position{1,2},Position{2,1}};
cells[3] = {Position{0,1},Position{1,0},Position{1,1},Position{2,1}};
move(0,3);
}
};

class zblock : public Block{
public:
zblock(){
id = 7;
cells[0] = {Position{0,0},Position{0,1},Position{1,1},Position{1,2}};
cells[1] = {Position{0,2},Position{1,1},Position{1,2},Position{2,1}};
cells[2] = {Position{1,0},Position{1,1},Position{2,1},Position{2,2}};
cells[3] = {Position{0,1},Position{1,0},Position{1,1},Position{2,0}};
move(0,3);
}
};