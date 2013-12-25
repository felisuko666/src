#include "CApp.h"
 
void CApp::OnCleanup() 
{
	
	SDL_DestroyWindow(window); 
	SDL_Quit();
	//normal termination
	cout << "Terminating normally." << endl;
}