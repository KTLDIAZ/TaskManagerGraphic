#include "widget.h"
#include "ui_widget.h"
#include "addwidget.h"
#include <QMessageBox>
#include "simulate.h"
#include "simulateform.h"

Process newProcess;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    cpu = 0;
    connect(addwid, SIGNAL(save()), this, SLOT(add()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::add() {
    Process process;
    process.name = newProcess->name;
    process.cpu = newProcess->cpu;
    process.priority = newProcess->priority;
    process.time_arrived = newProcess->time_arrived;
    process.waiting_time = 0;
    process.success_time = 0;
    process.status = "Ready";
    cpu += newProcess->cpu;
    push(list, process);
}

void Widget::on_AddProcess_clicked()
{
    addwid->show();
    addwid->setProcess(newProcess);
}

void Widget::on_show_clicked()
{
    Simulate *simu = new Simulate;
    simu->setList(list);
    simu->show();
    simu->setShow(false);
    simu->showData();
}

void Widget::on_pushButton_clicked()
{
    simulateForm *simuform = new simulateForm;
    simuform->setList(list);
    simuform->setProperties(cpu, 4);
    simuform->show();
}
