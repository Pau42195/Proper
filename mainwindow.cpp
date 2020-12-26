#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QDateTime>

#include "cmodpre.h"
#include "cdefpro.h"
#include "dbmanager.h"
#include "clincsv.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //mAluReq = new QStandardItemModel(this);
    //ui->tableView->setModel(mAlumnes);
    //setCentralWidget(ui->tableView);
    //ui->tvAluReq->setModel(mAluReq);
    setWindowTitle("Proves Personalitzades");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::on_actionObrir_triggered()
// Potser en un futur cal fer-ho directament i no calgui obrir la base de dades
{
    auto nomFitxer = QFileDialog::getOpenFileName(this,"Obrir",QDir::currentPath(),"SQLite Database (*.db)");

    if (nomFitxer.isEmpty()) return;

    mdb.Open(nomFitxer);

    // TODO: Carregar els cursos, les proves fetes, ...

}



void MainWindow::on_actionAlumnes_triggered()
{
    ui->dkAlumnes->toggleViewAction();
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{

}

void MainWindow::on_actionPrepara_Prova_20_21_2T_M2_05_2T_triggered()
{
    mdb.CarregaProva("20-21-2T-M2-05-2T");
            FesProva()
}
*/

void MainWindow::on_cmdCreaPro_clicked()
{
    auto nomFitxer = QFileDialog::getOpenFileName(this,"Obrir",QDir::currentPath(),"SQLite Database (*.db)");

    if (nomFitxer.isEmpty()) return;

    mdb.Open(nomFitxer);

    mdb.CreaProva("P002","Prova de Proves 2",QDateTime(QDate(25,12,2020),QTime(18,0,0)),"02T","2","Al1Sub1");

}
