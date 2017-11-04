#include "level.h"

//#define DEBUG

int main( int argc, char *args[] )
{
 SDL_Init(SDL_INIT_EVERYTHING);
 #ifndef DEBUG
 Open_Window_and_Renderer(1366,768,0);
 //SDL_WINDOW_FULLSCREEN
 last_frame=Create_Transparent_Texture(1366,768);
 #else
 Open_Window_and_Renderer(3840,2160,0);
 //SDL_WINDOW_FULLSCREEN
 last_frame=Create_Transparent_Texture(3840,2160);
 #endif // DEBUG

 Texture *screen;
 screen=new Texture;
 screen->w=3840;
 screen->h=2160;
 screen->image=NULL;
 SCREEN=screen;

 Level level;
 level.Start("Skin_Andy1",screen);
}
