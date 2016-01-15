#include "Base.h"

void Base::OnEvent(SDL_Event* Event) {
    Event::OnEvent(Event);
}

void Base::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode){
    if(gameStart){
        switch(sym){
            case SDLK_a:if(growthPattern[1] > 0)stamina-=10;
                        if(growthPattern[1] > 0 && sharpness > 1){
                            growthPattern[1] = 0;
                            sharpness -= 1;
                            score += 1;
                            if(soundEffects) Mix_PlayChannel(-1, axe, 0);
                            updateTree();
                        }
                        MainGuy.AnimState = 0;

                        break;
            case SDLK_SPACE:
                    if(stamina+1<100)stamina+=1;
                    MainGuy.AnimState = 0;
            default:;
        }
    }
    else{
        switch(sym){
            case SDLK_a:
                    if(soundEffects){
                        soundEffects = false;
                    }
                    else{
                        soundEffects = true;
                        Mix_PlayChannel(-1, drink, 0);
                    }
                    break;
            case SDLK_SPACE:
                    gameStart = true;
                    break;
            default:;
        }
    }
}

void Base::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
    if(gameStart){
        if(keystate[SDLK_a] && keystate[SDLK_SPACE] && ((clock()-sharpTimer)/(CLOCKS_PER_SEC/1000)) > 500){
                if(sharpness+4 <= 20)
                    {sharpness += 4;
                     stamina-=5;}
                else
                    {sharpness = 20;}
                MainGuy.AnimState = 2;
                if(soundEffects) Mix_PlayChannel(-1, sharpNoise, 0);
                sharpTimer = clock();

        }
        if(keystate[SDLK_SPACE] && ((clock()-drinkTimer)/(CLOCKS_PER_SEC/1000)) > 500 && !keystate[SDLK_a]){
            if(stamina+5<100)stamina+=5;
            MainGuy.AnimState = 3;
            drinkTimer = clock();
            if(soundEffects) Mix_PlayChannel(-1, drink, 0);
        }
        if(keystate[SDLK_a] && !keystate[SDLK_SPACE]){
            MainGuy.AnimState = 1;
        }
    }
}
void Base::updateTree(){
    for(int i = 0; i < 15; i++){
        if(growthPattern[i] == 0){
            if(growthPattern[i+1] > 0){
                growthPattern[i] = growthPattern[i+1];
                growthPattern[i+1] = 0;
            }
        }
    }
}
//Close the window, I'm out.
void Base::OnExit(){
    Running = false;
}

