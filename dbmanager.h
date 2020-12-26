#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include "cpro.h"

class DbManager
{
public:

    DbManager();
    ~DbManager();

    bool Open(QString Path);

    void CreaProva(QString IdProva);
    cPro CreaProva(QString Id, QString Titol, QDateTime Quan, QString IdCurs, QString RolId, QString IdDefPro);


    bool isOpen() const;

    bool createTable();

    bool addPerson(const QString& name);

    bool removePerson(const QString& name);

    bool personExists(const QString& name) const;

    void printAllPersons() const;

    bool removeAllPersons();

private:
    QSqlDatabase m_db;
    QSqlTableModel *m_defpro;
};

#endif // DBMANAGER_H
