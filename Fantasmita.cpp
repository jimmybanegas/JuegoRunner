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
    if(arriba)
     {
        this->y+=8;
        this->x+=8;
     }
    else
      {
        this->y-=8;
        this->x+=8;
      }

    if(x>900)
        this->x-=8;
        this->y+=8;

    if(y>400)
        arriba=false;

    if(y<-10)
        arriba=true;
}
