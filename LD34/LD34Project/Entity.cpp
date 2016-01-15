#include "Entity.h"

//List of entities
std::vector<Entity*> Entity::EntityList;

//Entity constructor
Entity::Entity() {
    //Intialize that surface
    Surf_Entity = NULL;

    //Intialize where it goes in life
    X = 270.0f;
    //This makes it start out on the ground
    Y = 360.0f;

    //The sizes of the image
    Width = Height = 0;

    //The size of the entities hitbox
    HitBoxHeight = HitBoxWidth = 0;

    //The state of animation, right now its just whether its facing forward or back
    AnimState = 0;

}

//Evil entity constructor
Entity::~Entity(){
}

//Load some surfaces
bool Entity::OnLoad(char* File, int Width, int Height, int MaxFrames, int HitBoxWidth, int HitBoxHeight) {
    //Load it and check it
    if((Surf_Entity = Surface::OnLoad(File)) == NULL) {
        return false;
    }
    //Set them parameters not that we got em.
    this->Width = Width;
    this->Height = Height;

    this->HitBoxWidth = HitBoxWidth;
    this->HitBoxHeight = HitBoxHeight;

    //Give the animation control for this dude some info concerning how many frames he has
    Anim_Control.MaxFrames = MaxFrames;

    return true;
}
bool Entity::OnLoad(char* File, char* File2, int Width, int Height, int MaxFrames, int HitBoxWidth, int HitBoxHeight) {
    //Load it and check it
    if((Surf_Entity = Surface::OnLoad(File)) == NULL) {
        return false;
    }
    //Set them parameters not that we got em.
    this->Width = Width;
    this->Height = Height;

    this->HitBoxWidth = HitBoxWidth;
    this->HitBoxHeight = HitBoxHeight;


    //Give the animation control for this dude some info concerning how many frames he has
    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

//Animate him
void Entity::OnLoop() {

    Anim_Control.OnAnimate();

    if(Anim_Control.CurrentFrame >= Anim_Control.MaxFrames) {
            Anim_Control.CurrentFrame = 0;
    }

}

//Draw him
void Entity::OnRender(SDL_Surface* Surf_Display){
    //First check if they exist
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    //Draw them using special better draw for animation purposes.
    //Sections off each frame, and AnimState traverse the rows of animations
    //Use the current frame to make sure you are drawing the correct frame
    Surface::OnDraw(Surf_Display, Surf_Entity, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame()*Height, Width, Height);
}

//Free the surfaces!
void Entity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;

}
bool Entity::CollisionCheck(int left1, int top1, int w1, int h1, int left2, int top2, int w2, int h2){
    int right1 = left1+w1;
    int bottom1 = top1+h1;
    int right2 = left2+w2;
    int bottom2 = top2+h2;

    if(bottom1 <= top2){
        return false;
    }
    if(top1 >= bottom2){
        return false;
    }
    if(right1 <= left2){
        return false;
    }
    if(left1 >= right2){
        return false;
    }
    return true;
}



