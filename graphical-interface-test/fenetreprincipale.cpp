#include "fenetreprincipale.h"
#include "secondefenetre.h"

fenetrePrincipale::fenetrePrincipale()
{

    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);

    //setStyleSheet("background-color:grey;");

    setWindowIcon(QIcon(":/logo.png"));

    setWindowTitle("Analyseur de trames KNX");

    historique = menuBar()->addMenu("&Historique");
    aboutUs = menuBar()->addMenu("&A propos");
    quitter = menuBar()->addMenu("&Quitter");
    quit = new QAction("&Quitter", this);
    quitter->addAction(quit);
    quit->setShortcut(QKeySequence("Ctrl+Q"));
    quit->setIcon(QIcon(":/quitter.png"));

    QWidget::connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    m_bouton = new QPushButton("Ouvrir la fenêtre", this);
    QPalette palette;
    palette.setColor(QPalette::Base, QColor(Qt::black));
    m_bouton->setPalette(palette);
    m_bouton->move(400,250);

    /*liste = new QComboBox(this);
    //valeur = liste->itemData(liste->currentIndex());
    liste->addItem("Port com");
    liste->addItem("Port nom");
    liste->move(400,250);*/

    //valeur = liste->itemData(liste->currentIndex());
    //valeur.toInt();


    //if( valeur == 0 ){

    QObject::connect(m_bouton, SIGNAL(clicked()), &dialogue, SLOT(exec()));

   //}


}
