#ifndef CALT_H
#define CALT_H

#include <QObject>
#include "cpar.h"

class cAlt
{
public:
    cAlt();
    cAlt(QStringList ll);
    cAlt(QString Id,QString IdPre, QStringList Params);
private:
    QString mId;
    QString mIdModPre;
    QList<cPar> mParams;
};

#endif // CALT_H
