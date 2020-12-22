#ifndef CALUMNE_H
#define CALUMNE_H

#include <QObject>
#include "creq.h"

class cAluReq
{
public:
    cAluReq();
    cAluReq(QString nom);
    void setNom(QString nom);
    QString getNom();
    QList<cReq> Requeriment;
private:
    QString mNom;
};

#endif // CALUMNE_H
