#include "Base.h"

std::vector<SDL_Surface*> Base::numList;

Base::Base() {
    //Intiate the surfaces
    Surf_Display = NULL;
    Background = NULL;
    skyBackground = NULL;
    mMenu = NULL;
    HealthBar = NULL;
    treeTrunk = NULL;
    treeRoot = NULL;
    surf_sharpness = NULL;
    scoreText = NULL;

    music = NULL;
    axe = NULL;
    sharpNoise = NULL;
    drink = NULL;

    stamina = 100;
    sharpness = 20;
    skyX = 0.0;
    score = 0;
    gotDigit = 0;
    growthTimer = clock();
    drinkTimer = clock();
    sharpTimer = clock();
     //Set running to true
    Running = true;
    gameStart = false;
    soundEffects = true;
}

//Execute program
int Base::OnExecute() {
    //If fails to intialize, get out
    if(OnInit() == false){
        return -1;
    }

    //Constructor the event reader
    SDL_Event Event;

    //While its running, do the stuffs
    while(Running) {
        //While we are looking for some events
        while(SDL_PollEvent(&Event)) {
            //Get those events rolling
            OnEvent(&Event);

        }
        //Loop what needs to be looped during gameplay
        OnLoop();
        //Render what needs to be rendered during gameplay
        OnRender();

    }

    //Clean up the assets
    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    //Constructor app
    Base Game;

    return Game.OnExecute();
}

