#ifndef SIMULATEFORM_H
#define SIMULATEFORM_H

#include <QWidget>
#include "nodeprocess.h"
#include "simulate.h"
#include "addwidget.h"

namespace Ui {
class simulateForm;
}

class simulateForm : public QWidget
{
    Q_OBJECT

public:
    Node *list;
    explicit simulateForm(QWidget *parent = nullptr);
    ~simulateForm();
    Simulate *simulate = new Simulate;
    int quantum, cpu;
    void setProperties(int,int);
    void setList(Node *&);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_QUANTUM_valueChanged(int arg1);

private:
    Ui::simulateForm *ui;
};

#endif // SIMULATEFORM_H
