#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cpre.h"

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

    void on_actionObrir_triggered();
    void on_actionObrirDb_triggered();
    void on_actionGuardar_triggered();

    void on_actionAlumnes_triggered();

    void on_actionCarregar_preguntes_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mAluReq;
    QList<cPre> mPreguntes;
    void setValueAt(int fil,int col, const QString &valor);
    QString getValueAt(int f, int c);
};
#endif // MAINWINDOW_H
