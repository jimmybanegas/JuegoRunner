#include "Fantasmita.h"

Fantasmita::Fantasmita(Personaje *personaje)
{
    this->x=100;
    this->y=100;

    this->sprites.push_back(IMG_Load("personajes/volador01.png"));
    this->sprites.push_back(IMG_Load("personajes/volador02.png"));
    this->sprites.push_back(IMG_Load("personajes/volador03.png"));
    this->personaje=personaje;
    //ctor
}

Fantasmita::~Fantasmita()
{
    //dtor
}

void Fantasmita::dibujar(SDL_Surface *screen)
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


void Fantasmita::logica()
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
