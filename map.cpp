#include "map.h"

void Map::Load(char *name)
{
 char path[TEXT_LENGTH_MAX];
 strcpy(path,"res/maps/all/");
 strcat(path,name);
 strcat(path,".map");
 FILE *where=fopen(path,"r");
 fscanf(where,"%d %d %d ",&w,&h,&number_of_layers);
 big_image=Create_Transparent_Texture(w*PIXELS_PER_TILE,h*PIXELS_PER_TILE);
 for(int i=0;i<number_of_layers;i++)
     {
      Map_Layer layer;
      layer.Load(i,w,h,where);
      Apply_Texture(0,0,layer.Get_big_image(),big_image);
      layer.Clear_big_image();
     }

 obstacles=new bool*[h];
 for(int y=0;y<h;y++)
     obstacles[y]=new bool[w];
 for(int y=0;y<h;y++)
     {
      for(int x=0;x<w;x++)
          {
           int aux;
           fscanf(where,"%d ",&aux);
           obstacles[y][x]=(bool)aux;
          }
     }
 fclose(where);
}

void Map::Clear()
{
 for(int y=0;y<h;y++)
     {
      for(int x=0;x<w;x++)
          {
           obstacles[y][x]=false;
          }
     }
 Destroy_Texture(big_image);
 w=h=0;
 number_of_layers=0;
}

bool Map::Is_obstacle(int x,int y)
{
 if(y<0 || y>=h || x<0 || x>=w)
    return true;
 return obstacles[y][x];
}

Texture *Map::Get_big_image()
{
 return big_image;
}
