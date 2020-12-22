#ifndef CLINCSV_H
#define CLINCSV_H

#include <QObject>


class cLinCsv : public QStringList
{
 //   Q_OBJECT En principi no ho necessito

    const QString separador = ",";
    const QString delimitador = "\"";


public:

    explicit cLinCsv(QStringList *parent = nullptr);
    cLinCsv(QString Orig);  //Afegeixo un constructor I les estàtiques



};

#endif // CLINCSV_H
