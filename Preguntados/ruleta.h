#ifndef RULETA_H
#define RULETA_H

#include <QObject>

class Ruleta
{
public:
    Ruleta();
    int categoria();
    int getposicion();
    int setvelocidad();


private:
    int posicion;
    int velocidad;
    int counter;
};

#endif // RULETA_H
