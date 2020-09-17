#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "nodeprocess.h"
#include "addwidget.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Process *newProcess = new Process;
    addWidget *addwid = new addWidget;
    Node *list = nullptr;
    int cpu;
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void add();
private slots:
    void on_AddProcess_clicked();
    void on_show_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
