#include "creq.h"

cReq::cReq()
{

}

cReq::cReq(QString idreq, int niv) {
    m_Dif = niv;
    m_IdReq=idreq;
}

void cReq::setDif(QString Dif)
{
    m_Dif = Dif;
}

QString cReq::getDif()
{
    return m_Dif;
}

void cReq::setIdReq(QString idreq)
{
    m_IdReq=idreq;
}

QString cReq::getIdReq()
{
    return m_IdReq;
}
