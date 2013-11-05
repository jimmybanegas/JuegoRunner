#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "Personaje.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>



class Personaje
{
public:
    int personaje_x;
    int personaje_y;


    bool moviendose;
    int getX();
    int getY();
    std::vector<SDL_Surface*> personajes;

    Personaje(int personaje_x, int personaje_y);

    virtual ~Personaje();
protected:
private:
};

#endif // PERSONAJE_H
