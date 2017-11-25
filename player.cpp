#include "player.h"

const int SKIN_IMAGE_W_PIXELS=32,SKIN_IMAGE_H_PIXELS=32;
const bool ANIMATION=false;

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

 is_moving=false;
 dirX=dirY=0;
 last_dirX=last_dirY=0;
 animation_pos=0;
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

void Player::Set_dirX(int _dirX)
{
 if(dirX!=0 || dirY!=0)
    last_dirX=dirX;
 dirX=_dirX;
}

void Player::Set_dirY(int _dirY)
{
 if(dirX!=0 || dirY!=0)
    last_dirY=dirY;
 dirY=_dirY;
}

void Player::Set_is_moving(bool _is_moving)
{
 if(_is_moving!=is_moving && _is_moving==true)
    animation_pos=1;
 is_moving=_is_moving;
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

int Player::Get_dirX()
{
 return dirX;
}

int Player::Get_dirY()
{
 return dirY;
}

int Player::Get_last_dirX()
{
 return last_dirX;
}

int Player::Get_last_dirY()
{
 return last_dirY;
}

bool Player::Get_is_moving()
{
 return is_moving;
}

///Game
void Player::Print(Texture *_screen)
{
 //Apply_Texture(screen_posX,screen_posY,skin_image,_screen);
 int pos=-1;
 int _dirX=0,_dirY=0;
 if(is_moving)
    {
     _dirX=dirX;
     _dirY=dirY;
    }
 else
    {
     _dirX=last_dirX;
     _dirY=last_dirY;
    }
 if(_dirY==-1)//sus-jos
    pos=3;
 else
    {
     if(_dirY==1)
        pos=1;
     else
        {
         if(_dirX==-1)//stanga-dreapta
            pos=0;
         else
            pos=2;
        }
    }
 if(is_moving)
    {
     if(ANIMATION==true)
        Apply_Texture(pos*SKIN_IMAGE_W_PIXELS,animation_pos*SKIN_IMAGE_H_PIXELS,screen_posX,screen_posY,SKIN_IMAGE_W_PIXELS,SKIN_IMAGE_H_PIXELS,skin_image,_screen);
     else
        Apply_Texture(pos*SKIN_IMAGE_W_PIXELS,(int)is_moving*SKIN_IMAGE_H_PIXELS,screen_posX,screen_posY,SKIN_IMAGE_W_PIXELS,SKIN_IMAGE_H_PIXELS,skin_image,_screen);
     animation_pos++;
     animation_pos%=number_of_animation_frames;
    }
 else
    {
     if(ANIMATION==true)
        Apply_Texture(pos*SKIN_IMAGE_W_PIXELS,(int)is_moving*SKIN_IMAGE_H_PIXELS,screen_posX,screen_posY,SKIN_IMAGE_W_PIXELS,SKIN_IMAGE_H_PIXELS,skin_image,_screen);
     else
        Apply_Texture(pos*SKIN_IMAGE_W_PIXELS,(int)is_moving*SKIN_IMAGE_H_PIXELS,screen_posX,screen_posY,SKIN_IMAGE_W_PIXELS,SKIN_IMAGE_H_PIXELS,skin_image,_screen);
    }
}
