#ifndef LLAMAS_H
#define LLAMAS_H
#include "Enemigo.h"

class Llamas : public Enemigo
{
public:
    Llamas(Personaje * personaje);
    void logica(SDL_Surface *screen);
    void dibujar(SDL_Surface *screen);
    virtual ~Llamas();
protected:
private:
};

#endif // LLAMAS_H
