#include "creq.h"

cReq::cReq()
{

}

cReq::cReq(QString idreq, int niv) {
    mNiv = niv;
    mIdReq=idreq;
}

void cReq::setNiv(int niv)
{
    mNiv = niv;
}

int cReq::getNiv()
{
    return mNiv;
}

void cReq::setIdReq(QString idreq)
{
    mIdReq=idreq;
}

QString cReq::getIdReq()
{
    return mIdReq;
}
