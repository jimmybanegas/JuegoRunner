#include "Bomba.h"

Bomba::Bomba(Personaje *personaje)
{
    this->x=450;
    this->y=0;
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
    if(x>500)
        x=400;

    if(y>300)
        y=0;

        this->x+=2;
        this->y+=2;


   if(personaje->personaje_x+128==this->x && personaje->personaje_y+128==this->y)
      {
           exit(0);
          SDL_BlitSurface( IMG_Load("personajes/gameover.png"), NULL, screen2, &offset );

      }

}
