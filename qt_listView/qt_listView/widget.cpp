#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QAction>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QAction* open = new QAction("test");



    model = new QStringListModel(QColor::colorNames(),this);
    modelProxy = new QSortFilterProxyModel(this);
    modelProxy->setSourceModel(model);
    modelProxy->setFilterKeyColumn(0);

    view = new QListView(this);
    view->setModel(modelProxy);


    QLineEdit *filterInput = new QLineEdit();
    QLabel *filterLabel = new QLabel(tr("Filter"));
    QHBoxLayout *filterLayout = new QHBoxLayout();
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(filterInput);
    filterLayout->setMargin(20);

    syntxBox = new QComboBox();
    syntxBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    syntxBox->addItem(tr("Regular experssion"),QRegExp::RegExp);
    syntxBox->addItem(tr("Wildcard"),QRegExp::Wildcard);
    syntxBox->addItem(tr("Fixed string"),QRegExp::FixedString);
    QLabel*syntaxLabel = new QLabel(tr("Syntax"));
    QHBoxLayout*syntaxLayout = new QHBoxLayout();
    syntaxLayout->addWidget(syntaxLabel);
    syntaxLayout->addWidget(syntxBox);
    syntaxLayout->setMargin(20);


    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(view);
    layout->addLayout(filterLayout);
    layout->addLayout(syntaxLayout);


    connect(filterInput,SIGNAL(textChanged(QString)),this,SLOT(filterChanged(QString)));









}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    this->cnt++;
    qDebug() << this->cnt;
}


void Widget::filterChanged(const QString &text){
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(
        syntxBox->itemData(syntxBox->currentIndex()).toUInt());
    QRegExp regExp(text,Qt::CaseInsensitive,syntax);
    modelProxy->setFilterRegExp(regExp);
}




