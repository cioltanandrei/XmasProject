#include "map_layer.h"

const int PIXELS_PER_TILE=64;

void Map_Layer::Load(int _number,int _w,int _h,FILE *where)
{
 w=_w;
 h=_h;
 texture_id=new int*[h];
 for(int y=0;y<h;y++)
     {
      texture_id[y]=new int[w];
     }

 for(int y=0;y<h;y++)
     {
      for(int x=0;x<w;x++)
          {
           fscanf(where,"%d ",&texture_id[y][x]);
           images[texture_id[y][x]]=NULL;
          }
     }
 for(std::map<int,Texture*>::iterator it=images.begin();it!=images.end();it++)
     {
      it->second=Get_Texture_from_id(it->first);
     }

 big_image=Create_Transparent_Texture(w*PIXELS_PER_TILE,h*PIXELS_PER_TILE);

 for(int y=0;y<h;y++)
     {
      for(int x=0;x<w;x++)
          {
           Apply_Texture(x*PIXELS_PER_TILE,y*PIXELS_PER_TILE,images[texture_id[y][x]],big_image);
          }
     }

 for(std::map<int,Texture*>::iterator it=images.begin();it!=images.end();it++)
     {
      Destroy_Texture(it->second);
     }
 images.clear();
}

Texture *Map_Layer::Get_big_image()
{
 return big_image;
}

void Map_Layer::Clear_big_image()
{
 Destroy_Texture(big_image);
}

Texture *Get_Texture_from_id(int id)
{
 char name[TEXT_LENGTH_MAX],path[TEXT_LENGTH_MAX];
 strcpy(path,"res/maps/texture/");
 itoa(id,name);
 strcat(path,name);
 strcat(path,".png");
 Texture *_texture=Load_Transparent_Texture(path);
 return _texture;
}
