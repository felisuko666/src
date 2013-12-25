#ifndef _CAPP_H_
#define _CAPP_H_

#include <cstdlib>
#include "SDL.h"
#include "SDL_image.h"
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
// screen dimensions
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
class CApp 
{
	
    private:
        bool			Running;
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		SDL_Surface     *screenSurface;
		

		
    public:
         
		CApp();
 
        int OnExecute();
 
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
	
 
};
 
#endif