#ifndef LEVEL_H
#define LEVEL_H

#include "player.h"
#include "map.h"

class Level
{
 private:
 Player player;
 Map map;
 SDL_Rect position;

 public:
 void Load(char *_player_name,int w,int h);
 void Clear();
 void Print(Texture *_screen);
 void Handle_Events();
 void Start(char *_player_name,Texture *_screen);
 bool Player_make_move(int dirX,int dirY,int distance);
};

#endif // LEVEL_H
