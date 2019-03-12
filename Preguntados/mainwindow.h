#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

#include "ruleta.h"
#include "jugador.h"
#include "pregunta.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *time;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void tiempo_acabado();
    void cargar_preguntas();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Jugador j1;
    Jugador j2;
    Pregunta arte[20];
    Pregunta ciencia[20];
    Pregunta deporte[20];
    Pregunta entretenimiento[20];
    Pregunta geografia[20];
    Pregunta historia[20];

};

#endif // MAINWINDOW_H
