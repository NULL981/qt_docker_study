#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QComboBox>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

public:
    int cnt;
    QComboBox* syntxBox;


private:
    QListView* view;
    QStringListModel*model;
    QSortFilterProxyModel*modelProxy;
private slots:
    void filterChanged(const QString &text);
};
#endif // WIDGET_H
