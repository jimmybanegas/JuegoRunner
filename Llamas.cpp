#include "Llamas.h"

Llamas::Llamas(Personaje * personaje)
{
    this->x=850;
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

void Llamas::logica(SDL_Surface *screen)
{
    if(derecha)
        this->y+=3;
    else
        this->y-=3;

    if(y>380)
       derecha=false;

    if(y<0)
       derecha=true;

}
