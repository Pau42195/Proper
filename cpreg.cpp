#include "cpreg.h"

cPre::cPre()
{

}


cPre::cPre(QString IdPro, QString IdAlu, QString Rol, QString IdDefPro, QString PatDif,
           QString IdModPre, QString Req, int NPar, QString PatPre, QString PatRes,
           QString IdAlt, QString IdPre, QString Dificultats, QList<cPar> Params)
{
    m_IdPro =      IdPro;
    m_IdAlu =       IdAlu;
    m_Rol =         Rol;
    m_IdDefPro = IdDefPro;
    m_PatDif =     PatDif;
    m_IdModPre=  IdModPre;
    m_Req =        Req;
    m_NPar =       NPar;
    m_PatPre =    PatPre;
    m_PatRes =   PatRes;
    m_IdAlt =       IdAlt;
    m_IdPre =      IdPre;
    m_Dificultats =  Dificultats;
    m_Params     =  Params;

}
