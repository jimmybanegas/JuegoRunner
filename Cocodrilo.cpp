#include "Cocodrilo.h"

Cocodrilo::Cocodrilo(Personaje * personaje)
{
    this->x=700;
    this->y=100;

    this->sprites.push_back(IMG_Load("personajes/croc01.png"));
    this->sprites.push_back(IMG_Load("personajes/croc02.png"));
    this->sprites.push_back(IMG_Load("personajes/croc03.png"));
    this->sprites.push_back(IMG_Load("personajes/croc04.png"));
    this->sprites.push_back(IMG_Load("personajes/croc05.png"));
    this->sprites.push_back(IMG_Load("personajes/croc06.png"));
    this->personaje=personaje;
    //ctor
}

Cocodrilo::~Cocodrilo()
{
    //dtor
}


void Cocodrilo::dibujar(SDL_Surface *screen)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    SDL_BlitSurface( this->sprites[cuadroactual], NULL, screen, &offset );

    cuadroactual++;

    if(cuadroactual>=6)
    {
        cuadroactual=0;

    }
}


void Cocodrilo::logica()
{
    if(derecha)
        this->y++;
    else
        this->y--;

    if(y>250)
        derecha=false;

    if(y<50)
        derecha=true;
}
