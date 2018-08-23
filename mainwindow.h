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
#include <QMdiSubWindow>
#include <QTableWidget>
void GetErrorMessage(QSqlDatabase *db, QString transaction_name);
class SqlBrowser;

class Browser : public QMainWindow
{
    Q_OBJECT
public:
    Browser(QWidget *parent = 0);   
    QMdiArea * mdiArea;
    QMap<QString,QString> setting;
public slots:
    void action_Sql_All();
    void action_Sql_only_table();
    void action_Sql_all_for_all();
    void closeAndUpdate();
    void action_Settings();
    void action_SQL();
    void action_Model();
    void action_size_default();
    void action_sql_text_size();
    void action_return_text_size();
    void action_bigSql();
};

class SqlBrowser : public QWidget
{
    Q_OBJECT
    ~SqlBrowser();
public:
    QTextEdit * sql_text;
    QTextEdit * return_text;
    SqlBrowser(QWidget *parent = 0,QString parameters="None");
    QString path_db;
public slots:
    void runSql();
    void BigSql();
};

class saveMdiSub : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit saveMdiSub(QWidget *parent = 0);
signals:
public slots:
private:
    ~saveMdiSub();
    void closeEvent(QCloseEvent *);
private slots:
};

#endif // BROWSER_H
