#include "fenetreapropos.h"

fenetreApropos::fenetreApropos()
{
    setStyleSheet("background-color:grey;");

    setWindowIcon(QIcon(":/logo.png"));

    setWindowTitle("Analyseur de trames KNX");

    setFixedSize(700,400);

    logo = new QLabel(this);
    QPixmap leLogo(":/logo.png");
    QPixmap leVrai=leLogo.scaled(QSize(145,135),Qt::IgnoreAspectRatio);
    logo->setPixmap(leVrai);
    //logo->resize(150,100);
    logo->move(300,30);

    information = new QTextEdit(this);
    information->setText("Ce logiciel est un analyseur de télégrammes KNX. \nIl permet d'afficher et décomposer les télégrammes qui passent par le module KNX. \nIl permet alors de repérer les erreurs possibles dans la transmission des télégrammes.");
    information->move(150,170);
    information->setReadOnly(true);
    information->setFrameShape(QFrame::NoFrame);
    information->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    information->resize(500,100);
    information->setFont(QFont("Times",10));

    auteur = new QTextEdit(this);
    auteur->setText("@Auteur: Rida VERDU, Victor FONTOURA SEARA, Johanne RANDRIANARIJAONA");
    auteur->move(30,300);
    auteur->setReadOnly(true);
    auteur->setFrameShape(QFrame::NoFrame);
    auteur->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    auteur->resize(500,40);
    auteur->setFont(QFont("Times",10));

    git = new QTextEdit(this);
    git->setText("Code source: https://github.com/rzdhop/KNX-Communication-Analyser");
    git->move(30,325);
    git->setReadOnly(true);
    git->setFrameShape(QFrame::NoFrame);
    git->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    git->resize(500,40);
    git->setFont(QFont("Times",10));
    //<a href="yourlink">link text</a>

    doc = new QTextEdit(this);
    doc->setText("Documentation: https://rzdhop.github.io/KNX-Communication-Analyser/#/fr/");
    doc->move(30,350);
    doc->setReadOnly(true);
    doc->setFrameShape(QFrame::NoFrame);
    doc->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    doc->resize(500,40);
    doc->setFont(QFont("Times",10));
}

fenetreApropos::~fenetreApropos()
{

}
