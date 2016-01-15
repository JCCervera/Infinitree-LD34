#include "Base.h"

void Base::OnCleanup() {
    //Free the background!
    //Free the window!
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Background);
    SDL_FreeSurface(skyBackground);
    SDL_FreeSurface(mMenu);
    SDL_FreeSurface(treeTrunk);
    SDL_FreeSurface(treeRoot);
    SDL_FreeSurface(HealthBar);
    SDL_FreeSurface(surf_sharpness);
    SDL_FreeSurface(scoreText);
    for(int i = 0; i < 9; i++){
        SDL_FreeSurface(Base::numList[i]);
    }

    Mix_FreeMusic(music);
    Mix_FreeChunk(axe);
    Mix_FreeChunk(drink);
    Mix_FreeChunk(sharpNoise);
    Mix_CloseAudio();


    MainGuy.OnCleanup();

    //Free SDL!
    SDL_Quit();
}

