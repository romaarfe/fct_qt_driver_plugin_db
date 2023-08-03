#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <sqlcipher/sqlite3.h>  // Inclui a biblioteca SQLite com suporte a codificação (provavelmente SQLCipher)
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSelect_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
