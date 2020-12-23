#ifndef CPAR_H
#define CPAR_H

#include <QObject>

enum tPar {Enter, Fraccio, Figura, Text, Real};

class cPar
{
public:
    cPar();
    cPar(tPar tip, QString val);
    cPar(QString val);
    void setTip(tPar Tip);
    tPar getTip();
    void setVal(QString val);
    QString getVal()
    ;
private:
    tPar mTip;
    QString mVal;
};

#endif // CPAR_H
