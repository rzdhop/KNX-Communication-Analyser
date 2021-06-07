#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QIcon>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QObject>
#include "fenetreapropos.h"
#include "decode.hpp"

class fenetrePrincipale: public QMainWindow
{
  Q_OBJECT

public:
    fenetrePrincipale();
    ~fenetrePrincipale();
public slots:
    void AddAdress();
    void ShowInfo();
    void clearTrames();
    //void ShowLogs();
private:
   QPushButton *a_propos;
   QPushButton *historique;
   QPushButton *logs;
   QLabel *information;
   QPushButton *play;
   QPushButton *info;
   QPushButton *reinitialisation;
   QTableWidget *tabAdresse;
   QLabel *plusInfo;
   QLabel *binaryControl;
   QLabel *charControl;
   QLabel *priority;
   QLabel *addressSource;
   QLabel *adressDestinataire;
   QLabel *group;
   QLabel *ttl;
   QLabel *dataFrame;
   QLabel *lenght;
   QLabel *parityByte;
   QLabel *binaryControlRecup;
   QLabel *charControlRecup;
   QLabel *priorityRecup;
   QLabel *addressSourceRecup;
   QLabel *addressDestinataireRecup;
   QLabel *groupRecup;
   QLabel *ttlRecup;
   QLabel *dataFrameRecup;
   QLabel *lenghtRecup;
   QLabel *parityByteRecup;
   fenetreApropos fenApropos;

   //void TableWidgetDisplay();
};

#endif // FENETREPRINCIPALE_H
