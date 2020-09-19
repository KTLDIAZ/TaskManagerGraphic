#ifndef SIMULATE_H
#define SIMULATE_H

#include <QWidget>
#include "nodeprocess.h"

namespace Ui {
class Simulate;
}

class QTimer;

class Simulate : public QWidget
{
    Q_OBJECT

public:
    explicit Simulate(QWidget *parent = nullptr);
    ~Simulate();
    Node *list;
    Node *aux, *aux2;
    void showResult();
    bool showStart, creatRow;
    void setShow(bool);
    int cpu, quantum, row, execution_time = 0;
    void print(int, Process);
    void setList(Node *&);
    void setProperties(int , int);
    void showData();
private slots:
    void on_START_clicked();
    void printProcess();
    void simulate();
private:
    Ui::Simulate *ui;
    QTimer *timer1, *timer2;
    enum {
        NAME, PRIORITY, CPU, TIME_ARRIVED, STATUS, WAITING, SUCCESS
    };
};

#endif // SIMULATE_H
