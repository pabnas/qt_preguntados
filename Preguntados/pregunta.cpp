#include "pregunta.h"

Pregunta::Pregunta()
{

}

void Pregunta::settextopregunta(QString texto)
{
    Texto_de_pregunta = texto;
}

void Pregunta::setposibles_respuestas(int opcion, QString texto)
{
    Posibles_respuestas[opcion+1] = texto;
}

void Pregunta::setrespuesta_correcta(QString texto)
{
    Respuesta_correcta = texto;
}

QString Pregunta::gettextopregunta()
{
    return Texto_de_pregunta;
}

QString Pregunta::getposible_respuesta(int opcion)
{
    return Posibles_respuestas[opcion-1];
}
QString Pregunta::getrespuesta_correcta()
{
    return Respuesta_correcta;
}
