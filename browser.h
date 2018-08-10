#ifndef BROWSER_H
#define BROWSER_H

#include <QMainWindow>
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
void GetErrorMessage(QSqlDatabase *db, QString transaction_name);
class SqlBrowser;

class Browser : public QMainWindow
{
    Q_OBJECT
public:
    Browser(QWidget *parent = 0);
    SqlBrowser * SBwidget;
public slots:
    void action_Sql_All();
    void action_Sql_only_table();
    void action_Sql_all_for_all();
};

class SqlBrowser : public QWidget
{
    Q_OBJECT
public:
    QTextEdit * sql_text;
    QTextEdit * return_text;
    SqlBrowser(QWidget *parent = 0);
    QString path_db;
public slots:
    void runSql();
};
#endif // BROWSER_H