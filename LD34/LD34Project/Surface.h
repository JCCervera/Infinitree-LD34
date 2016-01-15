#ifndef _SURFACE_H
    #define _SURFACE_H

#include <SDL/SDL.h>
#include <SDL_image.h>


class Surface {
    public:
        Surface();//Consturctor

    public:
        static SDL_Surface* OnLoad(char* file);//Load image file

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);//Draw entire image

        //Draw a piece of the image
        //X and Y are where to draw it, X2 and Y2 are where to section the piece off
        //Width and Height or the sizes of the pieces
        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);
};
#endif // _LPM_SURFACE_H

