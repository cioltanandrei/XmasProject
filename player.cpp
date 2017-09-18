#include "player.h"

void Player::Load(char *_name)
{
 Set_name(_name);
 char path[TEXT_LENGTH_MAX]={NULL};
 strcpy(path,"res/skins/");
 strcat(path,_name);
 strcat(path,".png");
 skin_image=Load_Transparent_Texture(path);
 screen_posX=100;
 screen_posY=50;
}

void Player::Clear()
{
 Destroy_Texture(skin_image);
 skin_image=NULL;
}

///Set
void Player::Set_name(char *_name)
{
 strcpy(name,_name);
}

void Player::Set_hp(int _hp)
{
 hp=_hp;
}

void Player::Set_screen_posX(int _screen_posX)
{
 screen_posX=_screen_posX;
}

void Player::Set_screen_posY(int _screen_posY)
{
 screen_posY=_screen_posY;
}

///Get
char *Player::Get_name()
{
 return name;
}

int Player::Get_hp()
{
 return hp;
}

int Player::Get_screen_posX()
{
 return screen_posX;
}

int Player::Get_screen_posY()
{
 return screen_posY;
}

Texture *Player::Get_skin_image()
{
 return skin_image;
}

///Game
void Player::Print(Texture *_screen)
{
 Apply_Texture(screen_posX,screen_posY,skin_image,_screen);
}
