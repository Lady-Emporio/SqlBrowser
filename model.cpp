#include "model.h"
#include "settings.h"

Model::Model(QWidget *parent) : QWidget(parent)
{
    static int counter=0;
    this->setObjectName("Model"+QString("").setNum(counter));
    ++counter;
    transaction_name=this->objectName();
    path_db=Settings::get("path_db");
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    QHBoxLayout * row1=new QHBoxLayout(this);
    QPushButton * select=new QPushButton("select",this);
    table=new QLineEdit(this);
    row1->addWidget(table);
    row1->addWidget(select);
    connectToDB();
    model = new QSqlTableModel(this,db);
    tableView=new QTableView(this);
    //model->setTable(table->text());
    tableView->setModel(model);
    mainLayout->addLayout(row1);
    mainLayout->addWidget(tableView);
    this->setLayout(mainLayout);

    //ableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    // Устанавливаем размер колонок по содержимому
    tableView->resizeColumnsToContents();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->horizontalHeader()->setStretchLastSection(true);

    //model->select(); // Делаем выборку данных из таблицы
    connect(select, SIGNAL(clicked()), this, SLOT(updateModel()));
}
void Model::updateModel(){
    qDebug()<<"change model "<<table->text();
    model->setTable(table->text());
    model->select();
}

void Model::connectToDB(){
    db = QSqlDatabase::addDatabase("QSQLITE",transaction_name);
    db.setDatabaseName(path_db);//Имя базы.
    if (!db.open()){
        GetErrorMessage();
        return;
    };
}

void Model ::GetErrorMessage(){
    QMessageBox msgBox;
    msgBox.setText(db.lastError().text());
    msgBox.exec();
    db.close();
    QSqlDatabase::removeDatabase(transaction_name);
}
