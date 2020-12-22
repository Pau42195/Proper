#include "clincsv.h"
#include <QStringList>


cLinCsv::cLinCsv(QString orig)
{
    QString line;

    this->clear();
    auto valuesC=orig.split( delimitador);
    for (int j=0; j<valuesC.size();j++) { // Totes les parts separades per "
        line = valuesC.at(j);
        if (!line.trimmed().isEmpty()) {
            auto values=line.split(separador);
            // si comença per ", la primera serà buida
            if (j>0) values.removeFirst(); // Eliminar el valor que va de les " a la ,
            for (int i =0; i<values.size(); i++) {
                this->append(values.at(i));
            }
        }
        if (j<valuesC.size()-1) {
            j++;
            this->append(valuesC.at(j));
        }
    }
}

