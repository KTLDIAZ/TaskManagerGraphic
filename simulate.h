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
    void showResult();
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
    QTimer *m_timer;
    enum {
        NAME, PRIORITY, CPU, TIME_ARRIVED, STATUS, WAITING, SUCCESS
    };
};

#endif // SIMULATE_H
