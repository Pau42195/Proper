#ifndef CREQ_H
#define CREQ_H

#include <QObject>
#include <QString>

class cReq
{
public:
    cReq();
    cReq(QString idreq, int niv);
    void setNiv(int niv);
    int getNiv();
    void setIdReq(QString idreq);
    QString getIdReq();

private:
    QString mIdReq;
    int mNiv;
};

#endif // CREQ_H
