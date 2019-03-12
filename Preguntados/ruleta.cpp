#include "ruleta.h"

Ruleta::Ruleta()
{

}

int Ruleta::categoria()
{
    int resultado;
    float a;
    int b;
    a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b = a * 7;

    if(b == 0)//arte
        resultado = 104;
    else if(b == 1)//ciencia
        resultado = 312;
    else if(b == 2)//corona
        resultado = 208;
    else if(b == 3)//deporte
        resultado = 52;
    else if(b == 4)//entretenimiento
        resultado = 156;
    else if(b == 5)//geografia
        resultado = 260;
    else//historia
        resultado = 1;

    return resultado;
}

