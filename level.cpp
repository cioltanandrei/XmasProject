#include "level.h"

const int PIXELS_PER_MOVE=20;

const int FPS_MAX=60;

void Level::Load(char *_player_name,int w,int h)
{
 player.Load(_player_name);
 map.Load("Test");
 position.w=w;
 position.h=h;
}

void Level::Clear()
{
 player.Clear();
 map.Clear();
}

void Level::Print(Texture *_screen)
{
 Apply_Texture(0,0,map.Get_big_image(),_screen);
 player.Print(_screen);
}

void Level::Handle_Events()
{
 int x,y;
 x=player.Get_screen_posX();
 y=player.Get_screen_posY();
 int dirX=0,dirY=0;
 if(keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
    {
     //y=std::max(0,y-PIXELS_PER_MOVE);
     dirY=-1;
    }
 if(keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
    {
     //y=std::min(position.h,y+PIXELS_PER_MOVE);
     dirY=1;
    }
 if(keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
    {
     //x=std::max(0,x-PIXELS_PER_MOVE);
     dirX=-1;
    }
 if(keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
    {
     //x=std::min(position.w,x+PIXELS_PER_MOVE);
     dirX=1;
    }
 Player_make_move(dirX,dirY,PIXELS_PER_MOVE);
}

bool Level::Player_make_move(int dirX,int dirY,int distance)
{
 int x=player.Get_screen_posX(),y=player.Get_screen_posY();
 x+=dirX*distance;
 y+=dirY*distance;
 std::pair<int,int> points[4];

 points[0].first=x/PIXELS_PER_TILE;
 points[0].second=y/PIXELS_PER_TILE;

 points[1].first=x/PIXELS_PER_TILE+(x%PIXELS_PER_TILE!=0);
 points[1].second=y/PIXELS_PER_TILE;

 points[2].first=x/PIXELS_PER_TILE;
 points[2].second=y/PIXELS_PER_TILE+(y%PIXELS_PER_TILE!=0);

 points[3].first=x/PIXELS_PER_TILE+(x%PIXELS_PER_TILE!=0);
 points[3].second=y/PIXELS_PER_TILE+(y%PIXELS_PER_TILE!=0);

 bool is_move_possible=true;
 if(x<0 || y<0)
    is_move_possible=false;
 for(int i=0;i<4 && is_move_possible;i++)
     {
      is_move_possible=(is_move_possible && !map.Is_obstacle(points[i].first,points[i].second));
     }
 if(is_move_possible)
    {
     player.Set_screen_posX(x);
     player.Set_screen_posY(y);
     player.Set_dirX(dirX);
     player.Set_dirY(dirY);
     player.Set_is_moving((dirX!=0 || dirY!=0));
     return true;
    }
 else
    {
     if(dirX!=0 && dirY!=0)
        {
         if(Player_make_move(0,dirY,distance))
            return true;
         if(Player_make_move(dirX,0,distance))
            return true;
         player.Set_dirX(0);
         player.Set_dirY(0);
         player.Set_is_moving(false);
         return false;
        }
     else
        {
         if(distance>1 && Player_make_move(dirX,dirY,distance/2))
            return true;
         player.Set_dirX(0);
         player.Set_dirY(0);
         player.Set_is_moving(false);
         return false;
        }
    }
}

void Level::Start(char *_player_name,Texture *_screen)
{
 Load(_player_name,1366,768);

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
        SDL_Delay(25);
        fps.start();
       }
 Clear();
}
