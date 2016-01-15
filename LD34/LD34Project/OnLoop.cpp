
#include "Base.h"



void Base::OnLoop() {
    skyX-=.03;
    if(skyX <= -960){
        skyX = 0;
    }

    if(gameStart){
        MainGuy.OnLoop();

        if((clock() - growthTimer)/(CLOCKS_PER_SEC/1000)>(1000-score)){
            for(int i = 0; i < 16; i++){
                if(growthPattern[i] == 0){
                    growthPattern[i] = 1;
                    break;
                }
            }
            growthTimer = clock();
        }
        if(stamina < 0 || growthPattern[15] == 1){
            score = 0;
            stamina = 100;
            sharpness = 20;
            for(int i = 0; i < 16; i++){
                growthPattern[i] = 0;
            }
            growthPattern[0] = 2;
            growthPattern[1] = 1;
            gameStart = false;

        }
    }
}

void Base::Move(){
    if(keystate[SDLK_w] && MainGuy.Y >= 1){
        MainGuy.AnimState = 5;
        MainGuy.Y-= 1;
    }
    if(keystate[SDLK_a] && MainGuy.X >= 1){
        MainGuy.AnimState = 6;
        MainGuy.X-= 1;
    }
    //Right
    if(keystate[SDLK_d] && MainGuy.X <= 350){
        MainGuy.AnimState = 7;
        MainGuy.X+= 1;
    }
    //Down
    if(keystate[SDLK_s] && MainGuy.Y <= 456){
        MainGuy.AnimState = 4;
        MainGuy.Y+= 1;

    }
}





