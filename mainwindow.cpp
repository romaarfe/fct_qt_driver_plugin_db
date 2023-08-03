#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSelect_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");  // Adiciona uma base de dados SQLite com suporte a codificação (SQLCipher)

    db.setDatabaseName("basedados.db"); // Define o nome da base de dados como "basedados.db"
    db.open();  // Abre a conexão com a base de dados

    QSqlQuery *query = new QSqlQuery();
    query->prepare("PRAGMA key = 'senha';");

    // Cria um modelo para a tabela de consulta
    QSqlQueryModel *model = new QSqlQueryModel();

    query->prepare("SELECT * FROM tabela");
    query->exec();

    model->setQuery(*query);

    // Define o modelo para a tabela na interface gráfica
    ui->tbvTabela->setModel(model);

    db.close();
}

