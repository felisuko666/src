#include "CApp.h"
 
void CApp::OnEvent(SDL_Event* Event) 
{
	
	
	switch(Event->type)
	{
		case SDL_QUIT:
			Running = false;
		break;
		case SDL_KEYDOWN:
			Running = false;
		break;
		
		switch (Event->key.keysym.sym) 
		{
            case SDLK_ESCAPE:
            case SDLK_q:
              Running = false;
            break;
        }
        break;
	}
	
		 
}