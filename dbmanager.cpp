#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>


bool DbManager::Open(QString Path)
{
    m_db.setDatabaseName(Path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
        return false;
    }
    else
    {
        qDebug() << "Database: connection ok";
    }


//    m_defpro = new QSqlTableModel();
//    m_defpro->setTable("DefinicioProva");
//    m_defpro->select();

//    qDebug() << "Tot bé " + m_defpro->tableName();
//    qDebug() << "     " << m_defpro->rowCount();
//    qDebug() << "     " << m_defpro->record(0).value("Rol");
//    qDebug() << "     " << m_defpro->record(0).value("Requeriments");
//    qDebug() << "     " << m_defpro->record(1).value("Rol");
//    qDebug() << "     " << m_defpro->record(1).value("Requeriments");

    return true;
}

cPro DbManager::CreaProva(QString Id, QString Titol, QDateTime Quan, QString IdCurs, QString RolId, QString IdDefPro)
{

    cPro prv;
    QString Reqs;

    //Carrego les dades de la capçalera
    prv.setId(Id);
    prv.setTitol(Titol);
    prv.setData(Quan);
    prv.setIdCurs(IdCurs);
    prv.setRolId(RolId);
    prv.setIdDefPro(IdDefPro);


    /* Per si no va la crida directa
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("DefinicioProva");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter(QString("IdDefPro='%1'").arg(IdDefPro));
    model->select();// Vaig a buscar els alumnes
    */

    QSqlQuery query;
    QString strsql= QString("SELECT Id,Num,Nom,Cognoms,IdCurs,Rol%1 FROM Alumnes WHERE IdCurs ='%2' and Rol%1 <>''").arg(RolId).arg(IdCurs);
    query.exec(strsql);

    int N=1;
    while (query.next()) {
        // Per cada alumne una prova individualitzada
        QString Rol = query.value(5).toString();
        cProInd proInd((QObject &) prv,
                       query.value(0).toString(),
                       Rol,
                       N,
                       query.value(1).toInt(),
                       query.value(2).toString(),
                       query.value(3).toString());
        prv.ProInd().append(proInd);


        //Ara es busca quines preguntes(requeriments) ha de fer en funció del rol
        QSqlQuery query2;
        QString txtReqs;
        strsql = QString("SELECT IdDefPro, Rol, Requeriments FROM  DefinicioProva WHERE IdDefPro ='%1' and Rol='%2'").arg(IdDefPro).arg(Rol);
        query2.exec(strsql);
        while (query2.next()) {
            txtReqs = query2.value(2).toString();
            qDebug() << "Requeriments  Id:" << query2.value(0).toString() <<  "Rol:" << query2.value(1).toString()  <<  "Req:" << query2.value(2).toString();
        }

        QStringList Reqs = txtReqs.split(";");
        for (int i=0;i<Reqs.size();i++) {
            QSqlQueryModel possibles;
            strsql=QString("select * from ModelsPregunta INNER JOIN Alternatives on ModelsPregunta.Id = Alternatives.IdPre where Req='%1'").arg(Reqs.at(i));
            qDebug() << "Demanaré la query " << strsql;

            possibles.setQuery(strsql);


            int j = rand() % possibles.rowCount();
            qDebug() << "Hi ha " << possibles.rowCount() << " possibles i em quedo la " << j;



        }




        N++;
    }

    if (N==1) qDebug() << "Error: No hi ha alumnes amb Rol";

/*    cProInd(QObject &parent, QString IdAlu,QString Rol,int NumInd, int NumAlu, QString Nom, QString Cognoms);
*/

}

DbManager::DbManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}



bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE gent(id INTEGER PRIMARY KEY, name TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'gent': one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::addPerson(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO gent (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}

bool DbManager::removePerson(const QString& name)
{
    bool success = false;

    if (personExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM gent WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}

void DbManager::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM gent");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

//void DbManager::ompleModel()

bool DbManager::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM gent WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllPersons()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM gent");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all persons failed: " << removeQuery.lastError();
    }

    return success;
}
