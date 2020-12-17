#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mAlumnes = new QStandardItemModel(this);
    //ui->tableView->setModel(mAlumnes);
    //setCentralWidget(ui->tableView);
    ui->tvAlumnes->setModel(mAlumnes);
    setWindowTitle("Proves Personalitzades");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionObrir_triggered()
{
    auto nomFitxer = QFileDialog::getOpenFileName(this,"Obrir",QDir::currentPath(),"CSV file (*.csv)");

    if (nomFitxer.isEmpty()) return;

    QFile file(nomFitxer);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream xin(&file);
    int iFila = 0;
    int colCount = 0;
    while (!xin.atEnd()) {
        mAlumnes->setRowCount(iFila+1);
        auto line =xin.readLine();
        // Per conservar les ""
        //TODO abans mirar que no hi hagi cap \", i si hi és, evitar el problema
        auto valuesC=line.split("\"");
        int iCol=0;
        for (int j=0; j<valuesC.size();j++) { // Totes les parts separades per "
            line = valuesC.at(j);
            if (!line.trimmed().isEmpty()) {
                auto values=line.split(",");
                // si comença per ", la primera serà buida
                if (j>0) values.removeFirst(); // Eliminar el valor que va de les " a la ,
                if( values.size()+iCol > colCount) {
                    colCount = values.size()+iCol;
                    mAlumnes->setColumnCount(colCount);
                }
                for (int i =iCol; i<(iCol+values.size()); i++) {
                    setValueAt(iFila,i,values.at(i-iCol));
                }
                iCol += values.size();
            }
            if (j<valuesC.size()-1) {
                j++;
                setValueAt(iFila,iCol,valuesC.at(j));
                iCol++;
            }
        }
        iFila++;
    }
    file.close();

}

void MainWindow::on_actionGuardar_triggered()
{
    auto nomFitxer = QFileDialog::getSaveFileName(this,"Desar",QDir::currentPath(),"CSV File (*.csv)");
    if (nomFitxer.isEmpty()) return;
    QFile file(nomFitxer);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream xout(&file);
    const int rowCount = mAlumnes->rowCount();
    const int colCount = mAlumnes->columnCount();
    for (int f=0 ;f < rowCount;f++) {
        xout << getValueAt(f,0);
        for (int c=1 ; c< colCount; c++) {
            xout << ", " << getValueAt (f,c);
        }
        xout << "\n";
    }
    file.flush();
    file.close();



}


void MainWindow::setValueAt(int fil, int col, const QString &valor)
{
    if (!mAlumnes->item(fil,col)) {
        mAlumnes->setItem(fil,col,new QStandardItem(valor));
    } else {
        mAlumnes->item(fil,col)->setText(valor);
    }
}

QString MainWindow::getValueAt(int f, int c)
{
    if ( !mAlumnes->item(f,c)) return "";
    return mAlumnes->item(f,c)->text();

}

