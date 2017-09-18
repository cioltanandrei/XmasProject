#ifndef LEVEL_H
#define LEVEL_H

#include "player.h"

class Level
{
 private:
 Player player;
 Texture *background;
 SDL_Rect position;

 public:
 void Load(char *_player_name,int w,int h);
 void Clear();
 void Print(Texture *_screen);
 void Handle_Events();
 void Start(char *_player_name,Texture *_screen);
};

#endif // LEVEL_H
