#ifndef MAP_LAYER_H
#define MAP_LAYER_H

#include "texture.h"
#include <map>

extern const int PIXELS_PER_TILE;

class Map_Layer
{
 private:
 int w,h;
 int **texture_id;
 std::map<int,Texture*> images;
 Texture *big_image;

 public:
 void Load(int number,int _w,int _h,FILE *where);
 Texture *Get_big_image();
 void Clear_big_image();
};

Texture *Get_Texture_from_id(int id);

#endif // MAP_LAYER_H
