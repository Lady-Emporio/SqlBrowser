#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("Settings");
    file.setFileName("./log.txt");
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
        }else{
            All_QString_PARAMS[i.key()]=root[i.key()].toString();
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

void Settings::writeInFile(QString text)
{
    if(file.size()>500000000){
        QMessageBox msgBox;
        msgBox.setText("./log.txt: VERY BIG size");
        msgBox.exec();
        return;
    }
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("./log.txt: "+file.errorString());
        msgBox.exec();
    }
    text+="\n********************\n";
    file.write(text.toStdString().c_str());
    file.close();
}

void Settings::makeGui(){
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    this->setLayout(mainLayout);
    QHBoxLayout *row1=new QHBoxLayout(this);
    mainLayout->addLayout(row1);
    row1->addWidget(new QLabel("path to db (.../...) ",this));
    pathToDB=new QLineEdit(this);
    row1->addWidget(pathToDB);

    QPushButton *DialogFileChoose=new QPushButton("Choose file",this);
    row1->addWidget(DialogFileChoose);
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

    QHBoxLayout *row4=new QHBoxLayout(this);
    mainLayout->addLayout(row4);
    row4->addWidget(new QLabel("path to image (.../...) ",this));
    path_to_image=new QLineEdit(this);
    row4->addWidget(path_to_image);

    connect(update, SIGNAL(clicked()), this, SLOT(update()));
    connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(DialogFileChoose, SIGNAL(clicked()), this, SLOT(chooseFile()));
}

void Settings::update(){
    All_QString_PARAMS["path_db"]=pathToDB->text();
    All_QString_PARAMS["font_size"]=font_size->text();
    All_QString_PARAMS["path_to_image"]=path_to_image->text();
    QMapIterator<QString, QString> i(All_QString_PARAMS);
    while (i.hasNext()) {
        i.next();
        insertInFile(i.key(),i.value());
    };
}

void Settings::clear(){
    pathToDB->setText(All_QString_PARAMS["path_db"]);
    font_size->setText(All_QString_PARAMS["font_size"]);
    path_to_image->setText(All_QString_PARAMS["path_to_image"]);
}

void Settings::chooseFile()
{
    QString str = QFileDialog::getOpenFileName(this,"Choose db","./");
    pathToDB->setText(str);
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
