#ifndef PLAYER_H
#define PLAYER_H

#include "texture.h"

class Player
{
 private:
 char name[TEXT_LENGTH_MAX];
 int hp;
 Texture *skin_image;

 bool is_moving=false;
 int dirX=0,dirY=0;
 int last_dirX=0,last_dirY=0;
 int animation_pos=0,number_of_animation_frames=2;

 int screen_posX,screen_posY;

 public:
 void Load(char *_name);
 void Clear();
 ///Set
 void Set_name(char *_name);
 void Set_hp(int _hp);
 void Set_screen_posX(int _screen_posX);
 void Set_screen_posY(int _screen_posY);
 void Set_dirX(int _dirX);
 void Set_dirY(int _dirY);
 void Set_is_moving(bool _is_moving);
 //void Set_player_posX(int _player_posX);
 //void Set_player_posY(int _player_posY);
 ///Get
 char *Get_name();
 int Get_hp();
 int Get_screen_posX();
 int Get_screen_posY();
 int Get_dirX();
 int Get_dirY();
 int Get_last_dirX();
 int Get_last_dirY();
 bool Get_is_moving();
 Texture *Get_skin_image();
 ///Game
 void Print(Texture *_screen);
};

#endif // PLAYER_H
