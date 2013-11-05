#include "Personaje.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
using namespace std;

Personaje::Personaje(int personaje_x, int personaje_y)
{
    this->personaje_x=personaje_x;
    this->personaje_y=personaje_y;
    this->moviendose=false;

    this->personajes.push_back(IMG_Load("personajes/run01.png"));
    this->personajes.push_back(IMG_Load("personajes/run02.png"));
    this->personajes.push_back(IMG_Load("personajes/run03.png"));
    this->personajes.push_back(IMG_Load("personajes/run04.png"));

    //ctor
}

Personaje::~Personaje()
{
    //dtor
}

int Personaje::getX()
{
    return personaje_x;
}

int Personaje::getY()
{
    return personaje_y;
}


