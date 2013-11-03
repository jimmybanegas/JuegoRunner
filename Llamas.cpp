#include "Llamas.h"

Llamas::Llamas(Personaje * personaje)
{
    this->x=500;
    this->y=100;

    this->sprites.push_back(IMG_Load("personajes/llama01.png"));
    this->sprites.push_back(IMG_Load("personajes/llama02.png"));
    this->sprites.push_back(IMG_Load("personajes/llama03.png"));
    this->personaje=personaje;
    //ctor
}

Llamas::~Llamas()
{
    //dtor
}

void Llamas::dibujar(SDL_Surface *screen)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    //Blit
    SDL_BlitSurface( this->sprites[cuadroactual], NULL, screen, &offset );

    cuadroactual++;

    if(cuadroactual>=3)
    {
        cuadroactual=0;

    }
}

void Llamas::logica()
{
    if(va_para_la_derecha)
        this->y++;
    else
        this->y--;

    if(y>250)
        va_para_la_derecha=false;

    if(y<50)
        va_para_la_derecha=true;
}
