#include "cpar.h"

cPar::cPar()
{

}

cPar::cPar(tPar Tip, QString val) {
    mTip=Tip;
    mVal=val;
}

cPar::cPar(QString val) {

    mVal=val;

    // Si no es passa el tipus, el suposa/calcula
    bool Ok;
    int a = val.toInt(&Ok,10);
    if (Ok){
        mTip=tPar::Enter;
    } else {
        bool Ok;
        double a = val.toDouble(&Ok);
        if (Ok){
            mTip=tPar::Real;
        }
    }
}

void cPar::setTip(tPar Tip) {
    mTip=Tip;
}

tPar cPar::getTip() {
    return mTip;
}

void cPar::setVal(QString val)
{
    mVal=val;
}

QString cPar::getVal()
{
    return mVal;
}

