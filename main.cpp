#include "level.h"

int main( int argc, char *args[] )
{
 SDL_Init(SDL_INIT_EVERYTHING);
 Open_Window_and_Renderer(1366,768,SDL_WINDOW_FULLSCREEN);
 last_frame=Create_Transparent_Texture(1366,768);

 Texture *screen;
 screen=new Texture;
 screen->w=1366;
 screen->h=768;
 screen->image=NULL;
 SCREEN=screen;

 Level level;
 level.Start("Andy",screen);
}
