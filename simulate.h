#ifndef SIMULATE_H
#define SIMULATE_H

#include <QWidget>
#include "nodeprocess.h"

namespace Ui {
class Simulate;
}

class Simulate : public QWidget
{
    Q_OBJECT

public:
    explicit Simulate(QWidget *parent = nullptr);
    ~Simulate();
    Node *list;
    bool showStart, creatRow;
    void setShow(bool);
    int cpu, quantum;
    void simulate();
    void print(int, Process);
    void setList(Node *&);
    void setProperties(int , int);
    void showData();
private slots:
    void on_START_clicked();

private:
    Ui::Simulate *ui;

    enum {
        NAME, PRIORITY, CPU, TIME_ARRIVED, STATUS, WAITING, SUCCESS
    };
};

#endif // SIMULATE_H
