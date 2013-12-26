#include "SDLImage.h"
//hola don pepito
//default constructor
CSDLImage::CSDLImage(void)
{
	m_tex=nullptr;
	m_surface=nullptr;
	m_renderer=nullptr;
	m_imagefilename=nullptr;
}


CSDLImage::~CSDLImage(void)
{

}

CSDLImage::CSDLImage(std::string file)
{
	m_tex=nullptr;
	m_surface=nullptr;
	m_renderer=nullptr;
	m_imagefilename=file;
	
}


//Load arbitray image file into a CSDL_Texture
bool CSDLImage::LoadImage(std::string file)
{
   bool success=true;

    m_surface = LoadSurface(file.c_str());
    
	if (m_surface== nullptr)
	{
       // throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
	     success=false;
	}
	return success;



}

bool CSDLImage::LoadBMP(std::string file)
{
	bool success=true;

	m_surface= SDL_LoadBMP( file.c_str() );
	if( m_surface== nullptr )
	{
		
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
		success = false;
	}
	return success;
}

//Gets the SDL_Surface corrsponant to a image file
SDL_Surface* CSDLImage::LoadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

	
	if( loadedSurface == nullptr )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, m_surface->format, NULL );
		if( optimizedSurface == nullptr )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

bool CSDLImage::Show(SDL_Window *window)
{
	
	bool bRc=true;
	try 
	{
  

		if(LoadImage(m_imagefilename))
		{
			SDL_BlitSurface(  m_surface, NULL,  SDL_GetWindowSurface( window ), NULL );
			SDL_UpdateWindowSurface( window );
	
		}
		else
		{
			bRc=false;
		}
	}
	catch (...) 
	{
     cerr << "exception LoadImage"<<endl;
	 bRc=false;
	}

	return bRc;
}
