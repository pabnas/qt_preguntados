#include "jugador.h"

Jugador::Jugador()
{
    for(int i=0;i < 6;i++)
        trofeos[i] = 0;
    puntaje = 0;
}

void Jugador::setnombre(QString nombre)
{
    Nombre = nombre;
}

QString Jugador::getnombre()
{
    return Nombre;
}
