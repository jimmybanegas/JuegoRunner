#ifndef COCODRILO_H
#define COCODRILO_H
#include "Enemigo.h"

class Cocodrilo :public Enemigo
{
public:
    Cocodrilo(Personaje * personaje);
    void logica();
    void dibujar(SDL_Surface *screen);
    virtual ~Cocodrilo();
protected:
private:
};

#endif // COCODRILO_H