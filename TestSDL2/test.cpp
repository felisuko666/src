#include <cstdlib>
#include <iostream>
#include "SDL.h"
using namespace std;
// screen dimensions
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

SDL_Window *screen=NULL;
SDL_Texture* LoadImage(std::string file);
//event structure
SDL_Event event;
SDL_Renderer *renderer = nullptr;


int main(int argc, char *argv[])
{
	//initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO)==-1) 
	{
		cerr << "Could not initialize SDL!" << SDL_GetError() << endl;
		exit(1);
	} 
	else 
	{
		cout << "SDL initialized properly!" << endl;
	}
	//create windowed environment

	screen = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          SCREEN_WIDTH, SCREEN_HEIGHT,
                          SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	////error check
	if (screen == NULL) 
	{
		//report error
		cerr << "Could not set up display surface!" << SDL_GetError()
		<< endl;
		exit(1);
	}

	////repeat forever game loop
	//for(;;) 
	//{
	//		//wait for an event
	//	if(SDL_PollEvent(&event)==0) 
	//	{
	//		// DO OUR THING . . .
	//		//update the screen
	//	//	SDL_UpdateRect(screen,0,0,0,0);
	//	} 
	//	else 
	//	{
	//		//event occurred, check for quit
	//		if(event.type==SDL_QUIT) break;
	//	}
	//}
	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
	SDL_DestroyWindow(screen); 
	SDL_Quit();
	//normal termination
	cout << "Terminating normally." << endl;
	return EXIT_SUCCESS;
}


SDL_Texture* LoadImage(std::string file)
{
    SDL_Surface *loadedImage = nullptr;
    SDL_Texture *texture = nullptr;
  
    loadedImage = SDL_LoadBMP(file.c_str());
    
	if (loadedImage != nullptr)
	{
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
    {
		std::cout << SDL_GetError() << std::endl;
	}
    return texture;
}