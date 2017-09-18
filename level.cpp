#include "level.h"

const int PIXELS_PER_MOVE=10;

const int FPS_MAX=60;

void Level::Load(char *_player_name,int w,int h)
{
 player.Load(_player_name);
 background=Load_Texture("res/images/background.png");
 position.w=w;
 position.h=h;
}

void Level::Clear()
{
 player.Clear();
 Destroy_Texture(background);
}

void Level::Print(Texture *_screen)
{
 Apply_Texture(0,0,background,_screen);
 player.Print(_screen);
}

void Level::Handle_Events()
{
 int x,y;
 x=player.Get_screen_posX();
 y=player.Get_screen_posY();
 if(keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
    y=std::max(0,y-PIXELS_PER_MOVE);
 if(keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
    y=std::min(position.h,y+PIXELS_PER_MOVE);
 if(keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
    x=std::max(0,x-PIXELS_PER_MOVE);
 if(keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
    x=std::min(position.w,x+PIXELS_PER_MOVE);
 player.Set_screen_posX(x);
 player.Set_screen_posY(y);
}

void Level::Start(char *_player_name,Texture *_screen)
{
 Load(_player_name,1300,700);

 bool quit=false;
 Timer fps;
 fps.start();
 while(!quit)
       {
        Print(_screen);
        Flip_Buffers(_screen);
        SDL_PumpEvents();
        if(keystates[SDL_SCANCODE_ESCAPE])
           quit=true;
        Handle_Events();
        SDL_Delay(30);
        fps.start();
       }
 Clear();
}
