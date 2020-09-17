#ifndef NODEPROCESS_H
#define NODEPROCESS_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <QString>

using namespace std;

struct Process {
    QString name;
    QString status;
    int priority;
    int cpu;
    int time_arrived;
    int waiting_time;
    int success_time;
};

struct Node {
    Process data;
    struct Node *next;
};

void push(Node *&,const Process&);
void sort(Node *&);
void swapNodes(Node *, Node *);
void sortPriority(Node *&);
void sortTimeArrivedPriority(Node *&);
void sortCpu(Node *&);
void sortTimeArrivedCpu(Node *&);
void sortMixedPriority(Node *&);
void sortMixedCpu(Node *&);
void sortMixedArrived(Node *&);

#endif // NODEPROCESS_H
