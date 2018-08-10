#include "browser.h"

Browser::Browser(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar * mainMenu=new QMenuBar(this);
    this->setMenuBar(mainMenu);
    QMenu * popularComands=new QMenu("Commands",this);
    mainMenu->addMenu(popularComands);
    popularComands->addAction("select * from sqlite_master",this,SLOT(action_Sql_All()));
    popularComands->addAction("select * from sqlite_master where type = 'table'",this,SLOT(action_Sql_only_table()));
    popularComands->addAction("select * from ...",this,SLOT(action_Sql_all_for_all()));
    SBwidget=new SqlBrowser(this);
    this->setCentralWidget(SBwidget);
}

void Browser::action_Sql_All()
{
    SBwidget->sql_text->setPlainText("select * from sqlite_master");
}

void Browser::action_Sql_only_table()
{
    SBwidget->sql_text->setPlainText("select * from sqlite_master where type = 'table'");
}

void Browser::action_Sql_all_for_all()
{
    QMessageBox msgBox;
    QString transaction_name="GetTable";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",transaction_name);
    db.setDatabaseName(SBwidget->path_db);//Имя базы.
    if (!db.open()){
        GetErrorMessage(&db,transaction_name);
        return;
    };
    QSqlQuery query(db);
    QStringList sqlTasks;
    if(!query.exec("select name from sqlite_master where type = 'table'")){
        GetErrorMessage(&db, transaction_name);
        return;
    };
    while (query.next()) {
        sqlTasks.append(query.value(0).toString());
    };
    db.close();
    db=QSqlDatabase();
    QSqlDatabase::removeDatabase(transaction_name);
    QString rec="";
    for(int i=0;i!=sqlTasks.length();++i){
        rec+="select * from "+sqlTasks[i]+";";
        rec+="\n";
    };
    SBwidget->sql_text->setPlainText(rec);
}

SqlBrowser::SqlBrowser(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * mainLayout=new QVBoxLayout(this);
    sql_text = new QTextEdit(this);
    return_text = new QTextEdit(this);
    QPushButton * run_button=new QPushButton("execute",this);
    QHBoxLayout * group1=new QHBoxLayout(this);
    group1->addWidget(sql_text);
    group1->addWidget(return_text);
    mainLayout->addLayout(group1);
    mainLayout->addWidget(run_button);
    this->setLayout(mainLayout);
    connect(run_button, SIGNAL(clicked()), this, SLOT(runSql()));

    path_db="MainDB.sqlite";
}

void SqlBrowser::runSql(){
    return_text->setPlainText("");

    QString transaction_name="RunSql";
    QMessageBox msgBox;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",transaction_name);
    db.setDatabaseName(path_db);//Имя базы.
    if (!db.open()){
        GetErrorMessage(&db,transaction_name);
        return;
    };
    QSqlQuery query(db);
    QString text=this->sql_text->toPlainText();
    QStringList sqlTasks=text.split(";");
    QString rec;
    for (int i=0;i!=sqlTasks.length();++i){
        QString next_sql=sqlTasks[i];
        if(next_sql.isEmpty() || next_sql==" " || next_sql=="\n"){
            continue;
        };
        if(!query.exec(next_sql)){
            msgBox.setText(db.lastError().text()+" | "+query.lastError().text());
            msgBox.exec();
            query.finish();
            rec="**********\n"+db.lastError().text()+" | "+query.lastError().text()+"\n"+next_sql+"\n*********\n";
            continue;
        };
        while (query.next()) {
            int max=query.record().count();
            for(int i=0;i<max;++i){
                rec+=query.value(i).toString();
                rec+=" | ";
            };
            rec+="\n";
        };
        rec+="-----------------\n";
    };
    return_text->setPlainText(rec);
    query.finish();
    db.commit();
    db.close();
    db=QSqlDatabase();
    QSqlDatabase::removeDatabase(transaction_name);
}

void GetErrorMessage(QSqlDatabase *db,QString transaction_name){
    QMessageBox msgBox;
    msgBox.setText(db->lastError().text());
    msgBox.exec();
    db->close();
    db=nullptr;
    QSqlDatabase::removeDatabase(transaction_name);
}
