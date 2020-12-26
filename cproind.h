/* Aquesta Classe conté la informació d'un alumne per a fer una prova
 *
 *
*/


#ifndef CALU_H
#define CALU_H

#include <QObject>
#include "cpreg.h"

class cProInd
{
public:
    cProInd();
    cProInd(QObject &parent, QString IdAlu,QString Rol,int NumInd, int NumAlu, QString Nom, QString Cognoms);

private:
    QObject *m_Prova;
    QString m_IdAlu;
    QString m_Rol;
    int m_NumInd; // Nº Ordre de l'examen (seran iguals sui l'examen és per tothom. Aquest son tots correlatius
    // Redundants, però així ja hi són i no s'han de carregar per imprimir, i queden com a redundants
    int m_NumAlu; // Nº Ordre de l'alumne a les llistes
    QString m_Nom;
    QString m_Cognoms;
    cPre j;
    QList<cPre> m_Pregs;

};

#endif // CALU_H
