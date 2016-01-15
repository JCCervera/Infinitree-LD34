#include "Animation.h"

//Construct the animation dude
Animation::Animation() {
    //current frame displayed
    CurrentFrame    = 0;
    //Max amount of frames
    MaxFrames       = 0;
    //By how many frames we are incrementing
    FrameInc        = 1;

    StartFrame      = 0;


    //Rate of frame change in milliseconds
    FrameRate       = 60;
    OldTime         = 0;

    //Allows to oscillate between frames
    Oscillate       = false;
}

//Animate that stuff!
void Animation::OnAnimate() {

    //Get our current frame rate and make sure its kosher.
    if(OldTime + FrameRate > SDL_GetTicks()){
        return;
    }

    //If kosher, save the amount so we can check it later
    OldTime = SDL_GetTicks();

    //Increment the current frame
    CurrentFrame += FrameInc;

    //if you want to oscillate it
    if(Oscillate) {
        //and you are animating forward
        if(FrameInc > 0) {
            //and you are at the last frame
            if(CurrentFrame >= MaxFrames) {
                //Start heading back
                FrameInc = -FrameInc;
            }
        }
        //If you reached the beginning, head forward
        else{
            //and you chose a frame to start from
            if(StartFrame > 0){
                //and you reached that frame
                if(CurrentFrame <= StartFrame){
                    //head forward
                    FrameInc = -FrameInc;
                }
            }
            //if you didnt choose a starting frame
            else{
                //get to the beginning
                if(CurrentFrame <= 0){
                    //head forward
                    FrameInc = -FrameInc;
                }
            }
        }
    }
    //If you are just looping, head back to the first frame
  /*else{
        if(CurrentFrame >= MaxFrames) {
            CurrentFrame = 0;
        }
    }*/
}
//Set your framerate
void Animation::SetFrameRate(int Rate) {
    FrameRate = Rate;
}
//Set your current frame
void Animation::SetCurrentFrame(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return;

    CurrentFrame = Frame;
}
//Find out which frame you're currently on
int Animation::GetCurrentFrame() {
    return CurrentFrame;
}

