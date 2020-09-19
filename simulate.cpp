#include "simulate.h"
#include "ui_simulate.h"
#include <QString>
#include <QMessageBox>

Simulate::Simulate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulate)
{
    ui->setupUi(this);
    setWindowTitle("Nodes");
    QStringList titles;
    titles << "Name" << "Priority" << "Cpu" << "Time Arrived" << "Status" << "Waiting" << "Success";
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
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
    int row = 0;
    Node *aux;
    aux = list;
    creatRow = true;
    while(aux != nullptr){
        print(row, aux->data);
        aux = aux->next;
        row = row + 1;
    }
}

void Simulate::showResult() {
    int row = 0;
    Node *aux;
    aux = list;
    while(aux != nullptr){
        print(row, aux->data);
        aux = aux->next;
        row = row + 1;
    }
}

void Simulate::simulate() {
    Node *aux;
    aux = list;
    int execution_time=0;
    int row = 0;
    creatRow = false;
    while(aux != NULL) {
        if(aux->data.cpu != 0){
            aux->data.status = "In process";
        }
        if (aux->data.cpu <= quantum && aux->data.status != "Success") {
            print(row,aux->data);
            cpu -= aux->data.cpu;
            aux->data.waiting_time += execution_time;
            execution_time += aux->data.cpu;
            aux->data.cpu = 0;
            aux->data.success_time += quantum;
            aux->data.status = "Success";
            print(row,aux->data);
        } else if (aux->data.cpu > 0) {
            if(cpu != aux->data.cpu)
                aux->data.waiting_time += execution_time;
            print(row,aux->data);
            aux->data.status = "Blocked";
            aux->data.cpu -= quantum;
            aux->data.success_time += quantum;
            if(aux->data.cpu <= 0)
                aux->data.status = "Success";
            cpu -= quantum;
            execution_time += quantum;
            print(row,aux->data);
        }
        aux = aux->next;
        if(aux == NULL){
            aux = list;
            row = 0;
        }
        if(cpu == 0) {
            aux->data.status = "Success";
            aux->data.success_time += aux->data.waiting_time;
            break;
        }
        row ++;
    }
    showResult();
}

void Simulate::on_START_clicked()
{
    simulate();
}
