#include "Enemigo.h"


Enemigo::Enemigo()
{
    va_para_la_derecha=true;
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
    if(va_para_la_derecha)
        this->x++;
    else
        this->x--;

    if(x>400)
        va_para_la_derecha=false;

    if(x<50)
        va_para_la_derecha=true;

}
