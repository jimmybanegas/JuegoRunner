#ifndef AVION_H
#define AVION_H
#include "Personaje.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>


class Avion
{
    public:
        int x;
        int y;

    int getX();
    int getY();

    std::vector<SDL_Surface*> sprites;

        Avion(int x, int y);
        virtual ~Avion();
    protected:
    private:
};

#endif // AVION_H
