#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <QString>

class Pregunta
{
public:
    Pregunta();
    void settextopregunta(QString texto);
    void setposibles_respuestas(int opcion,QString texto);
    void setrespuesta_correcta(QString texto);
    QString gettextopregunta();
    QString getposible_respuesta(int opcion);
    QString getrespuesta_correcta();

private:
    QString Texto_de_pregunta;
    QString Posibles_respuestas[4];
    QString Respuesta_correcta;
};

#endif // PREGUNTA_H
