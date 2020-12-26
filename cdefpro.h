#ifndef CALUMNE_H
#define CALUMNE_H

#include <QObject>
#include "creq.h"

class cDefPro
{
public:
    cDefPro();
    cDefPro(QString nom);
    void setNom(QString nom);
    QString getNom();
    QList<cReq> Requeriment;
private:
    QString mNom;
};

#endif // CALUMNE_H
