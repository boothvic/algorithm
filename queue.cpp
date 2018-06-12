/*
 * Author: L.F.N   File Name: queue.cpp
 * Created Time: 2018年06月10日 星期日 15时09分06秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct queue
{
    node* front;
    node* rear;
};

queue* initQueue(queue* Q);
bool entryQueue(queue* Q, int x);
bool exitQueue(queue* Q);

int main(int argc, char **argv)
{
    queue* Q = (queue*)malloc(sizeof(queue));
    //cout << "sizeof(queue) " << sizeof(queue) << endl;
    //cout << "sizeof(node) " << sizeof(node) << endl;
    Q = initQueue(Q);
    if (entryQueue(Q, 233))
    {
        cout << Q->front->data << endl;
        cout << Q->rear->data << endl;
    }
    bool flag = entryQueue(Q, 2333);
    cout << Q->front->data << endl;
    cout << Q->front->next->data << endl;
    cout << Q->rear->data << endl;

    cout << "after exit: \n";
    if (exitQueue(Q))
    {
        cout << Q->front->data << endl; 
        cout << Q->rear->data << endl; 
    }
    return 0;
}

queue* initQueue(queue* Q)
{
    Q->front = Q->rear = (node*)malloc(sizeof(node));
    if (!Q->front)
        cout << "overflow!\n";
    Q->front->next = NULL;
    Q->rear->next = NULL;
    return Q;
}

bool entryQueue(queue* Q, int x)
{
    node* s = (node*)malloc(sizeof(node));
    if (!s)
    {
        cout << "overflow!\n";
        return false;
    }
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;

    return true;
}

bool exitQueue(queue* Q)
{
    if (Q->front == Q->rear)
    {
        cout << "error!";
        return false;
    }
    node* p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}

