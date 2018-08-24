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
    QHBoxLayout * row2=new QHBoxLayout(this);
    QHBoxLayout * row3=new QHBoxLayout(this);
    QPushButton * select=new QPushButton("select",this);
    QPushButton * commit=new QPushButton("commit",this);
    QPushButton * addRowButton=new QPushButton("add row",this);
    table=new QLineEdit(this);
    row1->addWidget(table);
    row1->addWidget(select);
    connectToDB();
    row2->addWidget(commit);
    row3->addWidget(addRowButton);
    model = new QSqlTableModel(this,db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableView=new QTableView(this);
    //model->setTable(table->text());
    tableView->setModel(model);
    mainLayout->addLayout(row1);
    mainLayout->addLayout(row3);
    mainLayout->addWidget(tableView);
    mainLayout->addLayout(row2);
    this->setLayout(mainLayout);

    //ableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    // Устанавливаем размер колонок по содержимому
    tableView->resizeColumnsToContents();
    //tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *   removeAct = new QAction("remove row",this);
    tableView->addAction(removeAct);
    //model->select(); // Делаем выборку данных из таблицы
    connect(select, SIGNAL(clicked()), this, SLOT(updateModel()));
    connect(commit, SIGNAL(clicked()), this, SLOT(commitModel()));
    connect(removeAct, SIGNAL(triggered()), this, SLOT(delete_row()));
    connect(addRowButton, SIGNAL(clicked()), this, SLOT(addRow()));
}
void Model::updateModel(){
    qDebug()<<"change model "<<table->text();
    model->setTable(table->text());
    model->select();
}

void Model::commitModel()
{
    if(!model->submitAll()){
        QMessageBox msgBox;
        msgBox.setText(model->lastError().text());
        msgBox.exec();
    }
}

void Model::addRow()
{
    model->insertRow(model->rowCount());
}

void Model::delete_row()
{
    QModelIndex model_index=tableView->currentIndex();
    if(model_index.column()!=-1 or model_index.row()!=-1){
        QMap<int, QVariant> dataItem=model->itemData(model_index);
        //QAbstractItemModel::createIndex(1,1);
        const QAbstractItemModel *itemModel = model_index.model();
        if (nullptr == itemModel)
        {
            return;
        }
        int row=model_index.row();
        QString text;
        for (int i = 0; i < model->columnCount(); ++i)
        {
            text+="column "+QString("").setNum(i)+" :"+ model->data(itemModel->index(model_index.row(), i)).toString()+" \n";
        }
        QMessageBox msgBox;
        msgBox.setText("Need delete row?");
        msgBox.setInformativeText(text);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Yes:
                qDebug()<<"delete"<<row;
                model->removeRow(row);
                break;
        }
    }
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
