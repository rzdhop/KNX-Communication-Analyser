#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QIcon>

#include "secondefenetre.h"

class fenetrePrincipale: public QMainWindow
{
public:
    fenetrePrincipale();
private:
    QPushButton *m_bouton;
    //QComboBox *liste;
    secondeFenetre dialogue;
    //QVariant valeur;
    QMenu *historique;
    QMenu *aboutUs;
    QMenu *quitter;
    QAction *quit;
};

#endif // FENETREPRINCIPALE_H
