#ifndef JUGADOR_H
#define JUGADOR_H

#include <QString>

class Jugador
{
public:
    Jugador();
    void setnombre(QString nombre);
    QString getnombre();

private:
    QString Nombre;
    int puntaje;
    int trofeos[6];
};

#endif // JUGADOR_H
