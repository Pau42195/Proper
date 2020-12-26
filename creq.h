#ifndef CREQ_H
#define CREQ_H

#include <QObject>
#include <QString>

class cReq
{
public:
    cReq();
    cReq(QString idreq, int niv);
    void setDif(QString Dif);
    QString getDif();
    void setIdReq(QString idreq);
    QString getIdReq();

private:
    QString m_IdReq;
    QString m_Dif;
};

#endif // CREQ_H
