#ifndef MAP_H
#define MAP_H

#include "map_layer.h"

class Map
{
 private:
 int w,h;
 int number_of_layers;
 Texture *big_image;
 bool **obstacles;

 public:
 void Load(char *name);
 void Clear();
 bool Is_obstacle(int x,int y);
 Texture *Get_big_image();
};

#endif // MAP_H
