
#include <vector>

#include "Animation.h"
#include "Surface.h"

class Entity {
    public:
        //Keeps track of all the different entities in order for the sake of collision
        static std::vector<Entity*>     EntityList;

    protected:

        SDL_Surface*    Surf_Entity; //Sets the information for the entities surface

    public:
        float           X; //Entities X position
        float           Y; //Entities Y position

        int             Width; //Entities width
        int             Height; //Entities height

        int             HitBoxWidth;
        int             HitBoxHeight;

        int             AnimState;

        Animation   Anim_Control; //Sets the information for the animations of the entity

    public:
        Entity(); //Constructor

        virtual ~Entity();//Unused, probably has purpose

    public:
        virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames, int HitBoxWidth, int HitBoxHeight);//Loads file and parameters for entity

        virtual bool OnLoad(char* File, char* File2, int Width, int Height, int MaxFrames, int HitBoxWidth, int HitBoxHeight);//Loads file and parameters for entity

        virtual void OnLoop();//Loops animation

        virtual void OnRender(SDL_Surface* Surf_Display);//Renders entity

        virtual void OnCleanup();//Frees entity surfaces

        virtual bool CollisionCheck(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

};

