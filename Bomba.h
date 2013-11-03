#ifndef BOMBA_H
#define BOMBA_H
#include "Enemigo.h"


class Bomba : public Enemigo
{
public:
    Bomba(Personaje *personaje);
    void logica();
    void dibujar(SDL_Surface *screen);
    virtual ~Bomba();
protected:
private:
};

#endif // BOMBA_H
