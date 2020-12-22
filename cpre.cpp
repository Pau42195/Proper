#include "cpre.h"

cPre::cPre()
{

}

QString cPre::getIdReq() const
{
    return mIdReq;
}

void cPre::setIdReq(QString idreq)
{
    mIdReq=idreq;
}

int cPre::getNiv()
{
    return mNiv;
}

void cPre::setNiv(int niv)
{
    mNiv=niv;
}

QString cPre::getPatPre()
{
    return mPatPre;
}

void cPre::setPatPre(QString patpre)
{
    mPatPre=patpre;
}

QString cPre::getParRes()
{
    return mPatRes;
}

void cPre::setPatRes(QString patres)
{
    mPatRes=patres;
}

QList<cPar> cPre::getParams()
{
    return mParams;
}

void cPre::setParams(QStringList params)
{
    QString pa;
    cPar *parm;
    while (params.size()>0) {
        pa=params.first();
        params.removeFirst();
        parm = new cPar(tPar::Text,pa);

        bool Ok;
        int a = pa.toInt(&Ok,10);
        if (Ok){
            parm->setTip(tPar::Enter);
        } else {
            bool Ok;
            double a = pa.toDouble(&Ok);
            if (Ok){
                parm->setTip(tPar::Real);
            }
        }
        params.append(parm);
    }
}
