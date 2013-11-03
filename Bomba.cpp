#include "Bomba.h"

Bomba::Bomba(Personaje *personaje)
{
    this->x=200;
    this->y=200;
    this->sprites.push_back(IMG_Load("personajes/bomba01.png"));
    this->sprites.push_back(IMG_Load("personajes/bomba02.png"));
    this->sprites.push_back(IMG_Load("personajes/bomba03.png"));
    this->personaje=personaje;
    //ctor

}

Bomba::~Bomba()
{
    //dtor
}


void Bomba::dibujar(SDL_Surface *screen)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    SDL_BlitSurface( this->sprites[cuadroactual], NULL, screen, &offset );

    cuadroactual++;

    if(cuadroactual>=3)
    {
        cuadroactual=0;

    }
}


void Bomba::logica()
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
