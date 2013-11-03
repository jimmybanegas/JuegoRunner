#include "Enemigo.h"


Enemigo::Enemigo()
{
    derecha=true;
    izquierda=false;
    arriba=true;
    abajo=false;
    cuadroactual=0;
    //ctor
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


void Enemigo::logica()
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
