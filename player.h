#ifndef PLAYER_H
#define PLAYER_H

#include "texture.h"

class Player
{
 private:
 char name[TEXT_LENGTH_MAX];
 int hp;
 Texture *skin_image;

 int screen_posX,screen_posY;

 public:
 void Load(char *_name);
 void Clear();
 ///Set
 void Set_name(char *_name);
 void Set_hp(int _hp);
 void Set_screen_posX(int _screen_posX);
 void Set_screen_posY(int _screen_posY);
 ///Get
 char *Get_name();
 int Get_hp();
 int Get_screen_posX();
 int Get_screen_posY();
 Texture *Get_skin_image();
 ///Game
 void Print(Texture *_screen);
};

#endif // PLAYER_H
