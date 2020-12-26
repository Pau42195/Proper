#include "cpro.h"


cPro::cPro()
{

}

QString cPro::Id() const
{
    return m_Id;
}

void cPro::setId(const QString &Id)
{
    m_Id = Id;
}

QString cPro::Titol() const
{
    return m_Titol;
}

void cPro::setTitol(const QString &Titol)
{
    m_Titol = Titol;
}

QDateTime cPro::Data() const
{
    return m_Data;
}

void cPro::setData(const QDateTime &Data)
{
    m_Data = Data;
}

QList<cProInd> cPro::ProInd() const
{
    return m_ProInd;
}

void cPro::setProInd(const QList<cProInd> &ProInd)
{
    m_ProInd = ProInd;
}

QString cPro::IdDefPro() const
{
    return m_IdDefPro;
}

void cPro::setIdDefPro(const QString &IdDefPro)
{
    m_IdDefPro = IdDefPro;
}

QString cPro::RolId() const
{
    return m_RolId;
}

void cPro::setRolId(const QString &RolId)
{
    m_RolId = RolId;
}

QString cPro::IdCurs() const
{
    return m_IdCurs;
}

void cPro::setIdCurs(const QString &IdCurs)
{
    m_IdCurs = IdCurs;
}
