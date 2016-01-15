#include "Base.h"

//Intialize
bool Base::OnInit() {

    //Initialize everything, I guess. Checking if SDL started fine
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    keystate = SDL_GetKeyState(NULL);

    //Sets the window display
    if((Surf_Display = SDL_SetVideoMode(480, 512, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
        return false;
    }
    SDL_WM_SetCaption("LD34Project", NULL);

    if((Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)) == -1){
        return false;
    }

    if((Background = Surface::OnLoad("background.png")) == NULL){
        return false;
    }
    if((skyBackground = Surface::OnLoad("skyBackground.png")) == NULL){
        return false;
    }
    if((mMenu = Surface::OnLoad("mMenu.png")) == NULL){
        return false;
    }
    if((MainGuy.OnLoad("MainGuy.png", 192, 150, 1, 40, 56)) == NULL){
        return false;
    }
    Entity::EntityList.push_back(&MainGuy);
    if((HealthBar = Surface::OnLoad("HealthBar.png")) == NULL){
        return false;
    }
    if((treeTrunk = Surface::OnLoad("treeTrunk.png")) == NULL){
        return false;
    }
    for(int i = 0; i < 16; i++){
        growthPattern[i] = 0;
    }
    growthPattern[0] = 2;
    growthPattern[1] = 1;
    if((surf_sharpness = Surface::OnLoad("sharpness.png")) == NULL){
        return false;
    }
    if((scoreText = Surface::OnLoad("MoneyNums.png")) == NULL){
        return false;
    }
    for(int i = 0; i < 9; i++){
        if((scoreText = Surface::OnLoad("MoneyNums.png")) == NULL){
            return false;
        }
        Base::numList.push_back(scoreText);
    }
    if((treeRoot = Surface::OnLoad("treeRoot.png")) == NULL){
        return false;
    }
    music = Mix_LoadMUS("music.wav");
    if(music == NULL){
        return false;
    }

    if((axe = Mix_LoadWAV("AXE.wav")) == NULL){
        return false;
    }
    if((drink = Mix_LoadWAV("Drink.wav")) == NULL){
        return false;
    }
    if((sharpNoise = Mix_LoadWAV("Sharpen.wav")) == NULL){
        return false;
    }
    //Allows you to hold down them keys
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL/3);


    return true;
}


