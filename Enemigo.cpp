#include "Enemigo.h"


Enemigo::Enemigo()
{
    derecha=true;
    izquierda=false;
    arriba=true;
    abajo=false;
    cuadroactual=0;
    offset.x = this->x;
    offset.y = this->y;

}

Enemigo::~Enemigo()
{
    //dtor
}


void Enemigo::dibujar(SDL_Surface *screen)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    //Blit


    SDL_BlitSurface( this->sprites[cuadroactual], NULL, screen, &offset );

    cuadroactual++;

    if(cuadroactual>=4)
    {
        cuadroactual=0;

    }
}


void Enemigo::logica(SDL_Surface *screen)
{
    if(derecha)
        this->x++;
    else
        this->x--;

    if(x>400)
        derecha=false;

    if(x<50)
        derecha=true;


}

bool Enemigo::checkCollision()
{
 if(
    (((personaje->getX() >= this->x)&& (personaje->getX() <= this->x+100)) ||
    ((personaje->getX()+100 >= this->x)&& (personaje->getX()+100 <= this->x+100))) &&
    (((personaje->getY() >= this->y) && (personaje->getY() <= this->y+170)) ||
    ((personaje->getY()+170 >= this->y) && (personaje->getY()+170 <= this->y+170))))
  {
   return true;
  }
  else
  {
    return false;
  }
  return false;
}

