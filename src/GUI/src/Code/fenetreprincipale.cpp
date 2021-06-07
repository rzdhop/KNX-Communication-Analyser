#include <iostream>
using namespace std;
#include <string>
#include <bitset>
#include <cstring>

#include "fenetreprincipale.h"
#include "decode.hpp"
#include "logs.hpp"

fenetrePrincipale::fenetrePrincipale()
{
setFixedSize(800,500);

setWindowFlag(Qt::WindowTitleHint);
setWindowFlag(Qt::WindowSystemMenuHint);
setWindowFlag(Qt::WindowMinimizeButtonHint);

setWindowTitle("Analyseur de trames KNX");
setWindowIcon(QIcon(":/logo.png"));

information = new QLabel("Port:COMX",this);
information->setFont(QFont("Times",10));
information->move(15,5);

a_propos = new QPushButton("À propos", this);
a_propos->resize(75,25);
a_propos->move(710,20);
a_propos->setFont(QFont("Times",8));
a_propos->setStyleSheet("QPushButton { background-color: grey; }");

historique = new QPushButton("Historique", this);
historique->resize(75,25);
historique->move(710,50);
historique->setFont(QFont("Times",8));
historique->setStyleSheet("QPushButton { background-color: grey; }");

logs = new QPushButton("Logs", this);
logs->resize(75,25);
logs->move(710,80);
logs->setFont(QFont("Times",8));
logs->setStyleSheet("QPushButton { background-color: grey; }");

play = new QPushButton(this);
play->setIcon(QIcon(":/play.svg"));
//play->setIconSize(QSize(50,25));
play->resize(50,50);
play->move(50,50);

info = new QPushButton(this);
info->setIcon(QIcon(":/plus.svg"));
info->resize(50,50);
info->move(110,50);

reinitialisation = new QPushButton(this);
reinitialisation->setIcon(QIcon(":/supprimer.svg"));
reinitialisation->resize(50,50);
reinitialisation->move(170,50);

tabAdresse = new QTableWidget(this);
tabAdresse->resize(300,350);
tabAdresse->move(50,120);
tabAdresse->setColumnCount(1);
tabAdresse->setColumnWidth(0,300);
tabAdresse->setHorizontalHeaderItem(0,new QTableWidgetItem("Trames"));


plusInfo = new QLabel("",this);
plusInfo->move(400,120);
plusInfo->setFixedWidth(300);

binaryControl = new QLabel("",this);
binaryControl->move(400,140);

addressSource = new QLabel("", this);
addressSource->move(400,180);

adressDestinataire = new QLabel("",this);
adressDestinataire->move(400,220);

lenght = new QLabel("", this);
lenght->move(400,260);

ttl = new QLabel("", this);
ttl->move(400,300);

dataFrame = new QLabel("", this);
dataFrame->move(400,340);

parityByte = new QLabel("", this);
parityByte->move(400,380);

//charControl = new QLabel("", this);
//charControl->move(400,180);

//group = new QLabel("", this);
//group->move(400,340);

//priority = new QLabel("", this);
//priority->move(400,260);

binaryControlRecup = new QLabel("",this);
binaryControlRecup->move(520,140);

addressSourceRecup = new QLabel("", this);
addressSourceRecup->move(520,180);

addressDestinataireRecup = new QLabel("",this);
addressDestinataireRecup->move(520,220);

lenghtRecup = new QLabel("", this);
lenghtRecup->move(520,260);

ttlRecup = new QLabel("", this);
ttlRecup->move(520,300);

dataFrameRecup = new QLabel("", this);
dataFrameRecup->move(520,340);

parityByteRecup = new QLabel("",this);
parityByteRecup->move(520,380);


//charControlRecup = new QLabel("", this);
//charControlRecup->move(500,180);

//groupRecup = new QLabel("", this);
//groupRecup->move(500,340);

//priorityRecup = new QLabel("", this);
//priorityRecup->move(500,260);


//TableWidgetDisplay();

QObject::connect(play,SIGNAL(clicked()), this, SLOT(AddAdress()));
QObject::connect(info, SIGNAL(clicked()), this, SLOT(ShowInfo()));
QObject::connect(a_propos, SIGNAL(clicked()), &fenApropos, SLOT(exec()));
QObject::connect(reinitialisation, SIGNAL(clicked()), this, SLOT(clearTrames()));
//QObject::connect(logs, SIGNAL(clicked()), this, SLOT(ShowLogs()));
}

void fenetrePrincipale::AddAdress(){
    Decode decode;
    QTableWidgetItem *adresse = new QTableWidgetItem(decode.getFrame().c_str());
    int record = tabAdresse->rowCount();

    tabAdresse->insertRow(record);
    tabAdresse->setItem(record,0,adresse);
    tabAdresse->verticalHeader()->setVisible(false);

}
//tabAdresse->setEditTriggers(QAbstractItemView::NoEditTriggers);
//QMessageBox::information(this, "Elements", "ceci est un test");

void fenetrePrincipale::ShowInfo(){
    int row = tabAdresse->currentRow();
    QString adresse = tabAdresse->item(row,0)->text();
    Decode decode;
    plusInfo->setText(decode.getFrame().c_str());
    binaryControl->setText("Binaire de contrôle:");
    addressSource->setText("Adresse Source:");
    adressDestinataire->setText("Adresse Destinataire:");
    ttl->setText("TTL:");
    dataFrame->setText("Données:");
    lenght->setText("Longueur:");
    parityByte->setText("Bit de parité:");



    binaryControlRecup->setText(decode.getBinary().c_str());
    addressSourceRecup->setText(decode.sourceAdress().c_str());
    addressDestinataireRecup->setText(decode.destinationAdress().c_str());
    lenghtRecup->setText(QString::number(decode.longFrame()));
    ttlRecup->setText(QString::number(decode.TTL()));
    dataFrameRecup->setText(decode.hexData().c_str());
    parityByteRecup->setText(decode.parity().c_str());

}
//group->setText("Groupe:");
//charControl->setText("Char de contrôle:");
//priority->setText("Priorité:");

//a67fbca5ad390badfecdacf70
//groupRecup->setText("6");
//charControlRecup->setText("120");
//priorityRecup->setText("A");

//QMessageBox::information(this, "Elements", "ceci est un test");
void fenetrePrincipale::clearTrames(){
    tabAdresse->clearContents();
    tabAdresse->setRowCount(0);

    plusInfo->setText("");
    binaryControl->setText("");
    addressSource->setText("");
    adressDestinataire->setText("");
    ttl->setText("");
    dataFrame->setText("");
    lenght->setText("");
    parityByte->setText("");


    binaryControlRecup->setText("");
    addressSourceRecup->setText("");
    addressDestinataireRecup->setText("");
    lenghtRecup->setText("");
    ttlRecup->setText("");
    dataFrameRecup->setText("");
    parityByteRecup->setText("");


}

/*void fenetrePrincipale::ShowLogs(){
    Logs logs = Logs();

}*/
fenetrePrincipale::~fenetrePrincipale()
{

}
