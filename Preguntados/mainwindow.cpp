#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QThread>
#include <QMessageBox>

int counter;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    srand(QTime::currentTime().msec());
    ui->label->setPixmap(QPixmap(":/new/prefix1/ruleta"));

    /*ui->label_2->hide();
    ui->label_3->hide();
    ui->pushButton->hide();
    ui->label->hide();

    ui->pushButton->setIcon(QIcon(":/Logo-preguntados.png"));
    ui->pushButton->setIconSize(QSize(65,65));

    ui->Arte1->hide();
    ui->Arte2->hide();
    ui->Ciencia1->hide();
    ui->Ciencia2->hide();
    ui->Deportes1->hide();
    ui->Deportes2->hide();
    ui->Entretenimiento1->hide();
    ui->Entretenimiento2->hide();
    ui->Geografia1->hide();
    ui->Geografia2->hide();
    ui->Historia1->hide();
    ui->Historia2->hide();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    counter = 0;
    int vueltas = 0;
    Ruleta r;
    int objetivo = r.categoria();


    //QTimer *timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(tiempo_acabado()));
    //timer->start(1000);

    while(1)
    {
        QApplication::processEvents();
        QPixmap ship(":/new/prefix1/ruleta");
        QPixmap rotate(ship.size());

        QPainter p(&rotate);
        p.setRenderHint(QPainter::Antialiasing);
        p.setRenderHint(QPainter::SmoothPixmapTransform);
        p.setRenderHint(QPainter::HighQualityAntialiasing);

        p.translate(rotate.size().width()/2,rotate.size().height()/2);
        p.rotate(counter);
        p.translate(-rotate.size().width()/2,-rotate.size().height()/2);

        p.drawPixmap(0,0,ship);
        p.end();

        ui->label->setPixmap(rotate);

        if(counter >= 360)
            counter = 0;
        else
        {
            counter++;
            QThread::msleep(1);
        }

        if(counter == objetivo)
        {
            vueltas++;
        }
        if(vueltas == 3)
            break;
    }

}

void MainWindow::tiempo_acabado()
{
    //velocidad--;
}

void MainWindow::on_pushButton_2_clicked()
{
    if((ui->plainTextEdit->toPlainText() == NULL) | (ui->plainTextEdit_2->toPlainText() == NULL))
    {
        QMessageBox msgBox;
        msgBox.setText("Porfavor ingrese dos nombre para los usuarios");
        msgBox.exec();
    }
    else
    {
        ui->pushButton->show();
        ui->label->show();
        ui->plainTextEdit->hide();
        ui->plainTextEdit_2->hide();

        j1.setnombre(ui->plainTextEdit->toPlainText());
        j2.setnombre(ui->plainTextEdit_2->toPlainText());

        ui->label_2->setText(j1.getnombre());
        ui->label_3->setText(j2.getnombre());
        ui->label_2->show();
        ui->label_3->show();
        ui->pushButton_2->hide();
    }
}

void MainWindow::cargar_preguntas()
{
    QFile file("p_ciencia.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream text_stream(&file);

    text_stream.seek(0);

    for(int i=0;i<20;i++)
    {
        ciencia[i].settextopregunta(text_stream.readLine());
        text_stream.readLine();
        for(int j=0;j<4;j++)
        {
            ciencia[i].setposibles_respuestas(j+1,text_stream.readLine());
        }
        text_stream.readLine();
        ciencia[i].setrespuesta_correcta(text_stream.readLine());
        text_stream.readLine();
    }
    file.close();
}
