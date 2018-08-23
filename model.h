#ifndef MODEL_H
#define MODEL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QGraphicsView>
#include <QToolBar>
#include <QMdiArea>
#include <QMenuBar>
#include <QMenu>
#include <QString>
#include <QMdiSubWindow>
#include <QTableWidget>
#include <QSqlTableModel>
#include <QTableView>
class Model : public QWidget
{
    Q_OBJECT
    QSqlDatabase   db;
    QSqlTableModel  *model;
    QTableView*tableView;
    void connectToDB();
    QString path_db;
    QString transaction_name;
    void GetErrorMessage();
    QLineEdit *table;

public:
    explicit Model(QWidget *parent = 0);

signals:

public slots:
    void updateModel();
    void commitModel();
    void addRow();
    void delete_row();
};

#endif // MODEL_H
