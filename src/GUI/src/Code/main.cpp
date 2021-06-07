#include "fenetreprincipale.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fenetrePrincipale fenetre;
    fenetre.show();
    return a.exec();
}
