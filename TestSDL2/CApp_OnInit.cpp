#include "CApp.h"
#include "SDLImage.h"
#include <iostream>
//#define DBOUT( s )            
//{                             
//   std::ostringstream os_;    
//   os_ << s;                  
//   OutputDebugString( os_.str().c_str() );  
//}

bool CApp::OnInit() 
{
	cout << "OnInit......." << endl;
    //initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING)==-1) 
	{
		cerr << "Could not initialize SDL!" << SDL_GetError() << endl;
		return false;
		
	} 
	else 
	{
		cout << "SDL initialized properly!" << endl;
		
	}
	//create windowed environment

	window = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          SCREEN_WIDTH, SCREEN_HEIGHT,
                          SDL_WINDOW_FULLSCREEN|SDL_WINDOW_RESIZABLE);
	////error check
	if (window == nullptr) 
	{
		//report error
		cerr << "Could not set up display surface!" << SDL_GetError()<< endl;
		return false;
	}

	screenSurface = SDL_GetWindowSurface( window );

	//Fill the surface white
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
	//Update the surface
	SDL_UpdateWindowSurface( window );

	SDL_Delay( 2000 );
	
	
	//CSDLImage myImage("K:\\src\\TestSDL2\\TestSDL2\\Debug\\hello_world.bmp",window);
	
	CSDLImage myKoala("K:\\src\\TestSDL2\\TestSDL2\\Debug\\Koala.jpg");
	
	std::cerr << "antes show....................................." << std::endl;
	myKoala.Show(window);
	std::cerr << "despues show....................................." << std::endl;
	return true;
}