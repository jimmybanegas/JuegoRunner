#include "Cocodrilo.h"

Cocodrilo::Cocodrilo(Personaje * personaje)
{
    this->x=0;
    this->y=400;

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
        this->x+=4;
    else
        this->x-=4;

    if(x>850)
        derecha=false;

    if(x<0)
        derecha=true;

  //TERMINAR EL JUEGO

    if(checkCollision())
      {
          exit(0);
          SDL_BlitSurface( IMG_Load("personajes/gameover.png"), NULL, screen2, &offset );

      }



}


