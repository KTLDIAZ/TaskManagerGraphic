#include "nodeprocess.h"

void push(Node *&head, const Process &newProcess) {
    Node* newNode = new Node;
    newNode->data= newProcess;
    Node *aux1 = head;

    if(head == aux1)
        head = newNode;

    newNode->next = aux1;
}

void swapNodes(Node *node1, Node *node2) {
    Process temp = node1->data;
    node1->data = node2 -> data;
    node2->data = temp;
}

void sortPriority(Node *&head) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.priority > left->next->data.priority) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}


void sortTimeArrivedPriority(Node *&head) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.time_arrived > left->next->data.time_arrived && left->data.priority == left->next->data.priority) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void sortCpu(Node *&head) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.cpu > left->next->data.cpu) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void sortTimeArrivedCpu(Node *&head) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.time_arrived > left->next->data.time_arrived && left->data.cpu == left->next->data.cpu) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void sortMixedPriority(Node *&head){
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.priority > left->next->data.priority) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void sortMixedCpu(Node *&head){
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.cpu > left->next->data.cpu) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void sortMixedArrived(Node *&head){
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.time_arrived > left->next->data.time_arrived && left->data.cpu == left->next->data.cpu) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}
