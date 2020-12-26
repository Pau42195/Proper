#ifndef CPREG_H
#define CPREG_H

#include <QObject>
#include "cpar.h"

class cPre
{
public:
    cPre();
    cPre(
        QString IdPro,
        QString IdAlu,
        QString Rol,
        QString IdDefPro,
        QString PatDif,
        QString IdModPre,
        QString Req,
        int NPar,
        QString PatPre,
        QString PatRes,
        QString IdAlt,
        QString IdPre,
        QString Dificultats,
        QList<cPar> Params);

private:
    QString m_IdPro;
    QString m_IdAlu;
    QString m_Rol;
    QString m_IdDefPro;
    QString m_PatDif;
    QString m_IdModPre;
    QString m_Req;
    int m_NPar;
    QString m_PatPre;
    QString m_PatRes;
    QString m_IdAlt;
    QString m_IdPre;
    QString m_Dificultats;
    QList<cPar> m_Params;






};

#endif // CPREG_H
