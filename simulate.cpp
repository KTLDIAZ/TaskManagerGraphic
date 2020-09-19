#include "simulate.h"
#include "ui_simulate.h"
#include <QString>
#include <QMessageBox>
#include <QTimer>

Simulate::Simulate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulate)
{
    ui->setupUi(this);
    setWindowTitle("Simulate");
    QStringList titles;
    timer2 = new QTimer(this);
    timer1 = new QTimer(this);
    timer1->setInterval(1000);
    titles << "Name" << "Priority" << "Cpu" << "Time Arrived" << "Status" << "Waiting" << "Success";
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    connect(timer1, SIGNAL(timeout()), this, SLOT(printProcess()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(simulate()));
}

Simulate::~Simulate()
{
    delete ui;
}

void Simulate::setList(Node *&_list) {
    list = _list;
}

void Simulate::setShow(bool _show) {
    showStart = _show;
    if(showStart == false)
        ui->START->hide();
}
void Simulate::setProperties(int _cpu, int _quantum) {
    cpu = _cpu;
    quantum = _quantum;
}

void Simulate::print(int row, Process process) {
    if(creatRow == true)
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(row,NAME, new QTableWidgetItem(process.name));
    ui->tableWidget->setItem(row,PRIORITY, new QTableWidgetItem(QString::number(process.priority)));
    ui->tableWidget->setItem(row,CPU, new QTableWidgetItem(QString::number(process.cpu)));
    ui->tableWidget->setItem(row,TIME_ARRIVED, new QTableWidgetItem(QString::number(process.time_arrived)));
    ui->tableWidget->setItem(row,STATUS, new QTableWidgetItem(process.status));
    ui->tableWidget->setItem(row,WAITING, new QTableWidgetItem(QString::number(process.waiting_time)));
    ui->tableWidget->setItem(row,SUCCESS, new QTableWidgetItem(QString::number(process.success_time)));
}

void Simulate::showData() {
    aux = list;
    creatRow = true;
    row =0;
    while(aux != nullptr){
        print(row, aux->data);
        aux = aux->next;
        row = row + 1;
    }
}

void Simulate::showResult() {
    aux = list;
    row =0;
    while(aux != nullptr){
        print(row, aux->data);
        aux = aux->next;
        row = row + 1;
    }
}

void Simulate::printProcess() {
    creatRow = false;
    if(aux2->data.cpu != 0){
        aux2->data.status = "In process";
    }
    print(row, aux2->data);
}

void Simulate::simulate() {
    creatRow = false;
    if (aux->data.cpu <= quantum && aux->data.status != "Success") {
        cpu -= aux->data.cpu;
        aux->data.waiting_time += execution_time;
        execution_time += aux->data.cpu;
        aux->data.cpu = 0;
        aux->data.success_time += quantum;
        aux->data.status = "Success";
        print(row,aux->data);
    } else if (aux->data.cpu > 0) {
        if(cpu != aux->data.cpu) {
            aux->data.waiting_time += execution_time;
            execution_time += quantum;
        }
        aux->data.status = "Blocked";
        aux->data.cpu -= quantum;
        aux->data.success_time += quantum;
        if(aux->data.cpu <= 0) {
            aux->data.status = "Success";
            aux->data.success_time += aux->data.waiting_time;
        }
        cpu -= quantum;

        print(row,aux->data);
    }
    aux = aux->next;
    aux2 = aux2->next;
    row += 1;
    if(aux == NULL){
        aux = list;
        aux2 = list;
        row = 0;
    }
    if(cpu == 0) {
        showResult();
        timer1->stop();
        timer2->stop();
    }
}

void Simulate::on_START_clicked()
{
    row =0;
    aux = list;
    aux2 = list;
    timer1->start(1000);
    timer2->start(2000);
}
