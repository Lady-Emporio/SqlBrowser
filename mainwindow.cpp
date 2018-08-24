#include "mainwindow.h"
#include "settings.h"
#include "model.h"
saveMdiSub::saveMdiSub(QWidget *parent) :QMdiSubWindow(parent){}
void saveMdiSub::closeEvent(QCloseEvent *event){
    if(this->widget()->objectName()=="Settings"){
        Settings::S()->clear();
        QWidget * i=new QWidget(this);
        this->setWidget(i);
    }
}
saveMdiSub::~saveMdiSub(){qDebug()<<"we are del";}

Browser::Browser(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar * mainMenu=new QMenuBar(this);
    this->setMenuBar(mainMenu);
    mainMenu->addAction("SQL",this,SLOT(action_SQL()));
    QMenu * popularComands=new QMenu("Commands",this);
    mainMenu->addMenu(popularComands);
    popularComands->addAction("select * from sqlite_master",this,SLOT(action_Sql_All()));
    popularComands->addAction("select * from sqlite_master where type = 'table'",this,SLOT(action_Sql_only_table()));
    popularComands->addAction("select * from ...",this,SLOT(action_Sql_all_for_all()));

    mainMenu->addAction("Settings",this,SLOT(action_Settings()));
    mainMenu->addAction("Model",this,SLOT(action_Model()));
    mainMenu->addAction("Big sql",this,SLOT(action_bigSql()));
    QMenu * sizeComands=new QMenu("Size",this);
    mainMenu->addMenu(sizeComands);
    sizeComands->addAction("clear",this,SLOT(action_size_default()));
    sizeComands->addAction("sql text",this,SLOT(action_sql_text_size()));
    sizeComands->addAction("return text",this,SLOT(action_return_text_size()));

    mdiArea = new QMdiArea(this);
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);
}

void Browser::action_size_default(){
    if(mdiArea->activeSubWindow()!=0){
        if(mdiArea->activeSubWindow()->widget()->objectName().startsWith("SqlBrowser")){
            SqlBrowser*sql=reinterpret_cast<SqlBrowser*>( mdiArea->activeSubWindow()->widget() );
            sql->sql_text->setMinimumSize(10, 10);
            sql->sql_text->setMaximumSize(1000,1000);
            sql->return_text->setMinimumSize(10, 10);
            sql->return_text->setMaximumSize(1000,1000);
        };
    };
}

void Browser::action_sql_text_size(){
    if(mdiArea->activeSubWindow()!=0){
        if(mdiArea->activeSubWindow()->widget()->objectName().startsWith("SqlBrowser")){
            SqlBrowser*sql=reinterpret_cast<SqlBrowser*>( mdiArea->activeSubWindow()->widget() );
            sql->sql_text->setFixedWidth(sql->width()*0.8);
            sql->return_text->setMinimumSize(10, 10);
            sql->return_text->setMaximumSize(1000,1000);
        };
    };
}

void Browser::action_return_text_size(){
    if(mdiArea->activeSubWindow()!=0){
        if(mdiArea->activeSubWindow()->widget()->objectName().startsWith("SqlBrowser")){
            SqlBrowser*sql=reinterpret_cast<SqlBrowser*>( mdiArea->activeSubWindow()->widget() );
            sql->return_text->setFixedWidth(sql->width()*0.8);
            sql->sql_text->setMinimumSize(10, 10);
            sql->sql_text->setMaximumSize(1000,1000);
        };
    };
}

void Browser::action_bigSql()
{
    saveMdiSub *subWindow1 = new saveMdiSub;
    SqlBrowser *i=new SqlBrowser(this,"BigSql");
    subWindow1->setWindowTitle(i->objectName());
    subWindow1->setWidget(i);
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();
}

void Browser::action_Model(){
    saveMdiSub *subWindow1 = new saveMdiSub;
    Model *i=new Model(this);
    subWindow1->setWindowTitle(i->objectName());
    subWindow1->setWidget(i);
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();
}

void Browser::action_SQL(){
    saveMdiSub *subWindow1 = new saveMdiSub;
    SqlBrowser *i=new SqlBrowser(this);
    subWindow1->setWindowTitle(i->objectName());
    subWindow1->setWidget(i);
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();
}

void Browser::action_Settings(){
    QList<QMdiSubWindow *>	allSub=mdiArea->subWindowList();
    for(auto x:allSub){
        if(x->widget()->objectName()=="Settings"){
            x->close();
        };
    };
    saveMdiSub *subWindow1 = new saveMdiSub;
    subWindow1->setWidget(Settings::S());
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();
}

void Browser::closeAndUpdate(){
    QList<QMdiSubWindow *>	allSub=mdiArea->subWindowList();
    for(auto x:allSub){
        if(x->widget()->objectName()!="Settings"){
            x->widget()->close();
        };
    };
}

void Browser::action_Sql_All()
{
    saveMdiSub *subWindow1 = new saveMdiSub;
    SqlBrowser *i=new SqlBrowser(this);
    i->sql_text->setPlainText("select * from sqlite_master");
    subWindow1->setWindowTitle(i->objectName());
    subWindow1->setWidget(i);
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();
}

void Browser::action_Sql_only_table()
{
    saveMdiSub *subWindow1 = new saveMdiSub;
    SqlBrowser *i=new SqlBrowser(this);
    i->sql_text->setPlainText("select * from sqlite_master where type = 'table'");
    subWindow1->setWindowTitle(i->objectName());
    subWindow1->setWidget(i);
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();
}

void Browser::action_Sql_all_for_all()
{
    saveMdiSub *subWindow1 = new saveMdiSub;
    SqlBrowser *i=new SqlBrowser(this);

    subWindow1->setWindowTitle(i->objectName());
    subWindow1->setWidget(i);
    mdiArea->addSubWindow(subWindow1);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    subWindow1->show();


    QMessageBox msgBox;
    QString transaction_name="GetTable";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",transaction_name);
    db.setDatabaseName(i->path_db);//Имя базы.
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
    i->sql_text->setPlainText(rec);
}

SqlBrowser::SqlBrowser(QWidget *parent, QString parameters) : QWidget(parent)
{
    static int counterSqlBrowser=0;
    static int counterBigSql=0;
    if(parameters=="None"){
        QString thisObjectName="SqlBrowser"+QString("").setNum(counterSqlBrowser);
        this->setObjectName(thisObjectName);
        ++counterSqlBrowser;
    }else if(parameters=="BigSql"){
        QString thisObjectName="Big SQL"+QString("").setNum(counterBigSql);
        this->setObjectName(thisObjectName);
        ++counterBigSql;
    }
    QVBoxLayout * mainLayout=new QVBoxLayout(this);
    sql_text = new QTextEdit(this);
    QFont font("Times New Roman", Settings::get("font_size").toInt(), QFont::Normal);
    sql_text->setFont(font);
    return_text = new QTextEdit(this);
    return_text->setFont(font);
    QPushButton * run_button=new QPushButton("execute",this);
    QHBoxLayout * group1=new QHBoxLayout(this);
    group1->addWidget(sql_text);
    group1->addWidget(return_text);
    mainLayout->addLayout(group1);
    mainLayout->addWidget(run_button);
    this->setLayout(mainLayout);
    if(parameters=="None"){
        connect(run_button, SIGNAL(clicked()), this, SLOT(runSql()));
    }else if(parameters=="BigSql"){
        connect(run_button, SIGNAL(clicked()), this, SLOT(BigSql()));
    }
    path_db=Settings::get("path_db");

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
    db.exec("PRAGMA foreign_keys = ON;");
    QSqlQuery query(db);



    QString text=this->sql_text->toPlainText();
    QStringList sqlTasks=text.split(";");
    QString rec;
    QString sqlToFile;
    for (int i=0;i!=sqlTasks.length();++i){
        QString next_sql=sqlTasks[i];
        if(next_sql.isEmpty() || next_sql==" " || next_sql=="\n"){
            continue;
        };
        if(!query.exec(next_sql)){
            msgBox.setText(db.lastError().text()+" | "+query.lastError().text());
            msgBox.exec();
            query.finish();
            QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd*HH:mm:ss");
            rec+="**"+time+"******\n"+db.lastError().text()+" | "+query.lastError().text()+"\n"+next_sql+"\n*********\n";
            continue;
        };
        sqlToFile+=query.lastQuery()+"\n-  -  -  -  -  -  -\n";
        while (query.next()) {
            int max=query.record().count();
            for(int i=0;i<max;++i){
                rec+=query.value(i).toString();
                rec+=" | ";
            };
            rec+="\n";
        };
        QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd*HH:mm:ss");
        rec+="-------"+time+"----------\n";
    };
    QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd*HH:mm:ss");
    sqlToFile+="-------"+time+"----------\n";
    Settings::S()->writeInFile(sqlToFile);
    return_text->setPlainText(rec);
    query.finish();
    db.commit();
    db.close();
    db=QSqlDatabase();
    QSqlDatabase::removeDatabase(transaction_name);
}

void SqlBrowser::BigSql()
{
    return_text->setPlainText("");

    QString transaction_name="BigSQl";
    QMessageBox msgBox;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",transaction_name);
    db.setDatabaseName(path_db);//Имя базы.
    if (!db.open()){
        GetErrorMessage(&db,transaction_name);
        return;
    };
    db.exec("PRAGMA foreign_keys = ON;");
    QSqlQuery query(db);



    QString text=this->sql_text->toPlainText();

    if(!query.exec(text)){
            QMessageBox msgBox;
            msgBox.setText(db.lastError().text()+" | "+query.lastError().text());
            msgBox.exec();
            return;
    };
    Settings::S()->writeInFile(query.lastQuery());
    QString rec;
    while (query.next()) {
            int max=query.record().count();
            for(int i=0;i<max;++i){
                rec+=query.value(i).toString();
                rec+=" | ";
            };
            rec+="\n";
    };
    QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd*HH:mm:ss");
    rec+="";
    rec+="-------"+time+"----------\n";
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

SqlBrowser::~SqlBrowser(){
    qDebug()<<this->objectName();
}
