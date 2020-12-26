#ifndef CPRO_H
#define CPRO_H

#include <QObject>
#include<QDateTime>
#include "cproind.h"

class cPro
{
public:
    cPro();
    QString Id() const;
    void setId(const QString &Id);

    QString Titol() const;
    void setTitol(const QString &Titol);

    QString IdCurs() const;
    void setIdCurs(const QString &IdCurs);

    QString RolId() const;
    void setRolId(const QString &RolId);

    QString IdDefPro() const;
    void setIdDefPro(const QString &IdDefPro);

    QDateTime Data() const;
    void setData(const QDateTime &Data);

    QList<cProInd> ProInd() const;
    void setProInd(const QList<cProInd> &ProInd);

private:
    QString m_Id;
    QString m_Titol;
    QDateTime m_Data;
    QString m_IdCurs;
    QString m_RolId;
    QString m_IdDefPro;
    QList<cProInd> m_ProInd;
};

#endif // CPRO_H
