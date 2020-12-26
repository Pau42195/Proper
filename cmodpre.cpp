#include "cmodpre.h"

cModPre::cModPre()
{

}

QString cModPre::getIdReq() const
{
    return mIdReq;
}

void cModPre::setIdReq(QString idreq)
{
    mIdReq=idreq;
}

int cModPre::getNiv()
{
    return mNiv;
}

void cModPre::setNiv(int niv)
{
    mNiv=niv;
}

QString cModPre::getPatPre()
{
    return mPatPre;
}

void cModPre::setPatPre(QString patpre)
{
    mPatPre=patpre;
}

QString cModPre::getParRes()
{
    return mPatRes;
}

void cModPre::setPatRes(QString patres)
{
    mPatRes=patres;
}

QList<cPar> cModPre::getParams()
{
    return mParams;
}

void cModPre::setParams(QStringList params)
{
    QString pa;
    cPar *parm;
    while (params.size()>0) {
        pa=params.first();
        params.removeFirst();
        parm = new cPar(pa);
        mParams.append(*parm);
    }
}
