#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("Settings");
    All_QString_PARAMS.insert("path_db", "MainDB.sqlite");
    All_QString_PARAMS.insert("font_size", "15");
    All_QString_PARAMS.insert("path_to_image", "./Internet Explorer_32.png");
    readSettings();
    makeGui();
    clear();
}
Settings::~Settings(){
    qDebug()<<"Why i`m deleting?";
}

Settings * Settings::S(){
    static Settings * setting=new Settings;
    return setting;
}

void Settings::readSettings(){
    QFile file("style.json");
    if(!file.exists()){
        writeSettings();
        return;
    }
    file.open(QIODevice::ReadOnly);
    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    file.close();
    QJsonObject root=document.object();

    QMapIterator<QString, QString> i(All_QString_PARAMS);
    while (i.hasNext()) {
        i.next();
        if(!root.contains(i.key())){
            insertInFile(i.key(),i.value());
        }
    };
}

void Settings::writeSettings(){
    qDebug()<<"Create json and write";
    QMapIterator<QString, QString> i(All_QString_PARAMS);
    QJsonObject root;
    while (i.hasNext()) {
        i.next();
        QJsonValue JSvalue(i.value());
        root.insert(i.key(), JSvalue);
    };
    QJsonDocument new_doc(root);
    QFile jsonFile("style.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(new_doc.toJson());
    jsonFile.close();
}

void Settings::makeGui(){
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    this->setLayout(mainLayout);
    QHBoxLayout *row1=new QHBoxLayout(this);
    mainLayout->addLayout(row1);
    row1->addWidget(new QLabel("path to db (.../...) ",this));
    pathToDB=new QLineEdit(this);
    row1->addWidget(pathToDB);
    QHBoxLayout *row2=new QHBoxLayout(this);
    mainLayout->addLayout(row2);
    row2->addWidget(new QLabel("SQL font size",this));
    font_size=new QLineEdit(this);
    font_size->setValidator( new QRegExpValidator( QRegExp( "[1-3][0-9]" ) ) );
    row2->addWidget(font_size);
    QHBoxLayout *row3=new QHBoxLayout(this);
    QPushButton *update=new QPushButton("update",this);
    QPushButton * clear=new QPushButton("clear",this);
    row3->addWidget(update);
    row3->addWidget(clear);
    mainLayout->addLayout(row3);
    connect(update, SIGNAL(clicked()), this, SLOT(update()));
    connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
}

void Settings::update(){
    All_QString_PARAMS["path_db"]=pathToDB->text();
    All_QString_PARAMS["font_size"]=font_size->text();
    QMapIterator<QString, QString> i(All_QString_PARAMS);
    while (i.hasNext()) {
        i.next();
        insertInFile(i.key(),i.value());
    };
}

void Settings::clear(){
    pathToDB->setText(All_QString_PARAMS["path_db"]);
    font_size->setText(All_QString_PARAMS["font_size"]);
}

void insertInFile(QString key,QString value){
    qDebug()<<"insert in file: "<<key<<" | "<<value;
    QFile file("style.json");
    file.open(QIODevice::ReadOnly);
    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    QJsonObject root=document.object();
    QJsonValue JSvalue(value);
    root.insert(key, JSvalue);

    QJsonDocument new_doc(root);
    QFile jsonFile("style.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(new_doc.toJson());
    jsonFile.close();
}

QString Settings::get(QString param){
    return Settings::S()->All_QString_PARAMS[param];
}

void Settings::set(QString param,QString value){
    Settings::S()->All_QString_PARAMS[param]=value;
}
