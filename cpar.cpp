#include "cpar.h"

cPar::cPar()
{

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

