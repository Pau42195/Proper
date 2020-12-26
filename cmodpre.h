#ifndef CPRE_H
#define CPRE_H

#include <QObject>
#include "cpar.h"

class cModPre
{
public:
    cModPre();
    QString getIdReq() const;
    void setIdReq(QString idreq);
    int getNiv();
    void setNiv(int niv);
    QString getPatPre();
    void setPatPre(QString patpre);
    QString getParRes();
    void setPatRes(QString patres);
    QList<cPar> getParams();
    void setParams(QStringList params);

private:
    QString mIdReq;
    int mNiv;
    QString mPatPre;
    QString mPatRes;
    QList<cPar> mParams;
};

#endif // CPRE_H
