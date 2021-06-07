#ifndef FENETREAPROPOS_H
#define FENETREAPROPOS_H

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QIcon>
#include <QDialog>

class fenetreApropos: public QDialog
{
public:
    fenetreApropos();
    ~fenetreApropos();
private:
    QLabel *logo;
    QLabel *information;
    QLabel *noms;
    QLabel *qrCode;
};

#endif // FENETREAPROPOS_H
