#include "cproind.h"

cProInd::cProInd()
{

}

cProInd::cProInd(QObject &parent, QString IdAlu, QString Rol, int NumInd, int NumAlu, QString Nom, QString Cognoms)
{
    m_Prova = &parent;
    m_IdAlu=IdAlu;
    m_Rol=Rol;
    m_NumInd = NumInd; // Nº Ordre de l'examen (seran iguals si l'examen és per tothom. Aquest son tots correlatius
    // Redundants, però així ja hi són i no s'han de carregar per imprimir, i queden com a redundants
    m_NumAlu =NumAlu ;
    m_Nom = Nom;
    m_Cognoms = Cognoms;


}

