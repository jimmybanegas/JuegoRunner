#include "Avion.h"

Avion::Avion(int x, int y)
{
    this->x=x;
    this->y=y;


    this->sprites.push_back(IMG_Load("personajes/airplane.png"));
    this->sprites.push_back(IMG_Load("personajes/airplane1.png"));
    this->sprites.push_back(IMG_Load("personajes/airplane2.png"));

//ctor
}

Avion::~Avion()
{
    //dtor
}
