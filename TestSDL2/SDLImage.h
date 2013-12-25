
#pragma once
#include <cstdlib>
#include "SDL.h"
#include "SDL_image.h"
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class CSDLImage
{

private:
	SDL_Texture	 *m_tex;
	SDL_Surface  *m_surface;
	SDL_Renderer *m_renderer;
	string		 m_imagefilename;


public:
	CSDLImage(void);
	~CSDLImage(void);
	CSDLImage(std::string file);

	bool LoadImage(std::string file);
	bool LoadBMP(std::string file);
	SDL_Surface* LoadSurface( std::string path );
	bool Show(SDL_Window *window);
};

