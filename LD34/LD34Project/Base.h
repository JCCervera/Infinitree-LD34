
#ifndef _BASE_H_
    #define _BASE_H_

#include <SDL/SDL.h>
#include <SDL_Image.h>
#include <SDL/SDL_mixer.h>
#include <ctime>
#include <math.h>
#include "Event.h"
#include "Surface.h"
#include "Entity.h"

class Base : public Event{
public:
        //Keeps track of all the different entities in order for the sake of collision
        static std::vector<SDL_Surface*>     numList;
private:
        bool Running;

        SDL_Surface*    Surf_Display;//Window display
        SDL_Surface*    Background;
        SDL_Surface*    skyBackground;
        SDL_Surface*    mMenu;
        SDL_Surface*    scoreText;
        SDL_Surface*    HealthBar;
        SDL_Surface*    treeTrunk;
        SDL_Surface*    treeRoot;
        SDL_Surface*    surf_sharpness;

        Mix_Music*      music;

        Mix_Chunk*      axe;
        Mix_Chunk*      sharpNoise;
        Mix_Chunk*      drink;

        Entity          MainGuy;

        int             stamina;
        int             sharpness, score;
        double          skyX;
        std::clock_t    growthTimer, drinkTimer, sharpTimer;
        int             growthPattern[16];

        int             gotDigit;
        bool            gameStart, soundEffects;

        Uint8           *keystate;


    public:
        Base();//Main program

        int OnExecute();//Checks if OnInit went off properly

    public:
        bool OnInit();//When program is first intiated

        void OnEvent(SDL_Event* Event);//When a player controlled Event goes off

        void OnExit();//When player exits the window

        void OnLoop();//What to keep looping in the game

        void OnRender();//Renders objects on the screen

        void OnCleanup();//Cleans up assests

        void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);//When a key is let go

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void updateTree();

        void Move();// moves the character

        void getDigit(int place);

};

#endif
