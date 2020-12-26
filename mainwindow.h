#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cmodpre.h"
#include "cdefpro.h"
#include "dbmanager.h"
#include "cpro.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QStandardItemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

//    void on_actionObrir_triggered();
//    void on_actionObrirDb_triggered();
//    void on_actionGuardar_triggered();
//    cPro CreaProva(QString Id, QString Titol, QDateTime Quan, QString IdCurs, QString RolId, QString IdDefPro);

//    void on_actionAlumnes_triggered();

//    void on_actionCarregar_preguntes_triggered();

//    void on_comboBox_activated(const QString &arg1);

  //  void on_actionPrepara_Prova_20_21_2T_M2_05_2T_triggered();

    void on_cmdCreaPro_clicked();

private:
    Ui::MainWindow *ui;
    DbManager mdb;
    QList<cModPre> mPreguntes;
    QList<cDefPro> mAluReq;

};
#endif // MAINWINDOW_H
