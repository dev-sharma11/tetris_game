#include <bits/stdc++.h>
#include "raylib.h"
using namespace std;
#include"game.h"
#include"color.h"

double lastupdatetime = 0;

bool eventtriggred(double interval){

double currenttime = GetTime();
if(currenttime - lastupdatetime >= interval){
    lastupdatetime = currenttime;
    return true;
}
return false;
}


int main(){
Color darkblue = {44,44,200,225};

InitWindow(500,620,"Trtris Window");
SetTargetFPS(60);

Font font  = LoadFontEx("font/Monogram.otf",64,0,0);

Game game = Game(); 

while(WindowShouldClose() == false){
UpdateMusicStream(game.music);
game.handleinput();
if(eventtriggred(0.4)){
game.moveblockdown();
}
BeginDrawing();
ClearBackground(darkblue);
DrawTextEx(font,"Score",{365,15},38,2,WHITE);
DrawTextEx(font,"Next",{370,175},38,2,WHITE);
if(game.gameover){
DrawTextEx(font,"GAME OVER",{320,450},38,2,WHITE);
} 
DrawRectangleRounded({320,55,170,60},0.3,6,lightblue);

char scoretexe[10];
sprintf(scoretexe,"%d",game.score);
Vector2 textsize = MeasureTextEx(font,scoretexe,38,2);
DrawTextEx(font,scoretexe,{320+(170 - textsize.x)/2,65},38,2,WHITE);

DrawRectangleRounded({320,215,170,180},0.3,6,lightblue);
game.Draw();
EndDrawing();
}


CloseWindow();

}