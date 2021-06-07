#include "fenetreapropos.h"

fenetreApropos::fenetreApropos()
{
    setWindowIcon(QIcon(":/logo.png"));

    setWindowTitle("Analyseur de trames KNX");

    logo = new QLabel(this);
    QPixmap leLogo(":/logo.png");
    QPixmap leVrai=leLogo.scaled(QSize(70,60),Qt::IgnoreAspectRatio);
    logo->setPixmap(leVrai);
    //logo->resize(150,100);
    logo->move(150,80);

    information = new QLabel("test", this);
    information->move(250,120);


}

fenetreApropos::~fenetreApropos()
{

}
