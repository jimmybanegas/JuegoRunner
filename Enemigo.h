#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>
#include "Personaje.h"

class Enemigo
{
public:
    Personaje *personaje;
    SDL_Surface *screen2;
    SDL_Rect offset;

    int x,y,cuadroactual;
    bool derecha;
    bool izquierda;
    bool arriba;
    bool abajo;
    std::vector <SDL_Surface*> sprites;

    virtual void dibujar(SDL_Surface *screen);
    virtual void logica();

    Enemigo();
    virtual ~Enemigo();
protected:
private:
};

#endif // ENEMIGO_H
