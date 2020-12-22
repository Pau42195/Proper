#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>

#include "cpre.h"
#include "calureq.h"
#include "clincsv.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mAluReq = new QStandardItemModel(this);
    //ui->tableView->setModel(mAlumnes);
    //setCentralWidget(ui->tableView);
    ui->tvAluReq->setModel(mAluReq);
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
    mPreguntes.clear();
    int ColCount = 0;
    while (!xin.atEnd()) {

        auto line = xin.readLine();
        QStringList *values = new cLinCsv(line);

        if (values->size() > ColCount) {
            ColCount = values->size();
            mAluReq->setColumnCount(colCount);
        }
        for (int i=0; i<values->size(); i++) {
            setValueAt(iFila,i,values->at(i));
        }
        iFila++;
    }

    file.close();

}

void MainWindow::on_actionObrirDb_triggered()
{
    auto nomFitxer = QFileDialog::getOpenFileName(this,"Obrir",QDir::currentPath(),"CSV file (*.csv)");

    if (nomFitxer.isEmpty()) return;



    QFile file(nomFitxer);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream xin(&file);
    int iFila = 0;
    int colCount = 0;
    mPreguntes.clear();
    int ColCount = 0;
    while (!xin.atEnd()) {

        auto line = xin.readLine();
        QStringList *values = new cLinCsv(line);

        if (values->size() > ColCount) {
            ColCount = values->size();
            mAluReq->setColumnCount(colCount);
        }
        for (int i=0; i<values->size(); i++) {
            setValueAt(iFila,i,values->at(i));
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
    const int rowCount = mAluReq->rowCount();
    const int colCount = mAluReq->columnCount();
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
    if (!mAluReq->item(fil,col)) {
        mAluReq->setItem(fil,col,new QStandardItem(valor));
    } else {
        mAluReq->item(fil,col)->setText(valor);
    }
}

QString MainWindow::getValueAt(int f, int c)
{
    if ( !mAluReq->item(f,c)) return "";
    return mAluReq->item(f,c)->text();

}


void MainWindow::on_actionAlumnes_triggered()
{
    ui->dkAlumnes->toggleViewAction();
}

void MainWindow::on_actionCarregar_preguntes_triggered()
{
    auto nomFitxer = QFileDialog::getOpenFileName(this,"Obrir",QDir::currentPath(),"CSV file (*.csv)");

    if (nomFitxer.isEmpty()) return;

    QFile file(nomFitxer);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream xin(&file);

    mPreguntes.clear();
    while (!xin.atEnd()) {
        auto line =xin.readLine();
        QStringList *values = new cLinCsv(line);
        cPre pregunta;
        pregunta.setIdReq(values->first());
        values->removeFirst();
        pregunta.setNiv(values->first().toInt());
        values->removeFirst();
        pregunta.setPatPre(values->first());
        values->removeFirst();
        pregunta.setPatRes(values->first());
        values->removeFirst();
        pregunta.setParams(*values);
        mPreguntes.append(pregunta);
    }
    file.close();

}
