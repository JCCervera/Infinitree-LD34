#include "Base.h"
#include <iostream>
using namespace std;

void Base::OnRender() {

    Surface::OnDraw(Surf_Display, skyBackground, skyX, 0);
    Surface::OnDraw(Surf_Display, Background, 0, 0);
    if(Mix_PlayingMusic() == 0){
        Mix_PlayMusic(music, -1);
    }

if(gameStart){

    Surface::OnDraw(Surf_Display, HealthBar, 23, (403 + (100-stamina)), 0, (100 - stamina), 30, 100);
    for(int i = 0; i < 16; i++){
            if(growthPattern[i] == 1){
                Surface::OnDraw(Surf_Display, treeTrunk, 206, 480-(i*32));
            }
            if(growthPattern[i] == 2){
                Surface::OnDraw(Surf_Display, treeRoot, 206, 480);
            }
    }
    for(int i = 0; i < Entity::EntityList.size(); i++){
        Entity::EntityList[i]->OnRender(Surf_Display);
    }
    Surface::OnDraw(Surf_Display, surf_sharpness, 63, 412, 500-((sharpness/4)*100), 0, 100, 100);
    for(int i = 1; i < 9; i++){
        getDigit(i);
        Surface::OnDraw(Surf_Display, Base::numList[i], 270-((i+1)*30), 0, 0+(gotDigit*30), 0, 30, 30);

    }
}
else{
    Surface::OnDraw(Surf_Display, mMenu, 0,0);
}
    //Flip it for some reason? Doesn't come out the right way otherwise.
    SDL_Flip(Surf_Display);
}

void Base::getDigit(int place){
        int digit=0;
        int i = 10;
        while(i >= place){
            digit = score%(int)(pow(10.0, i));//Mod the number until it is at the right decimal place
            i--;
        }
        gotDigit = digit/(pow(10.0, (place-1.0)));//Divide the number, leaving the decimal point to be truncated
}

