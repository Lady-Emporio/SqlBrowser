#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QLineEdit>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QRadioButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QGridLayout>
#include <QHeaderView>
#include <QFileDialog>
void insertInFile(QString key,QString value);

class Settings : public QWidget
{
    Q_OBJECT
    explicit Settings(QWidget *parent = 0);
    QMap<QString,QString> All_QString_PARAMS;
    ~Settings();
    void makeGui();

    QLineEdit *font_size;
    QLineEdit *pathToDB;
    QLineEdit *path_to_image;
    QFile file;
public:
    static Settings *S();
    static QString get(QString param);
    static void set(QString param,QString value);
    void readSettings();
    void writeSettings();
    void writeInFile(QString text);
signals:

public slots:
    void update();
    void clear();
    void chooseFile();
};
#endif // SETTINGS_H
