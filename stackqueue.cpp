/*
 * Author: L.F.N   File Name: stack.cpp
 * Created Time: 2018年06月11日 星期一 14时11分22秒
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

struct stackqueue
{
    node* base;
    node* top;
};

bool push(stackqueue* S, int x);
bool pop(stackqueue* S);

int main(int argc, char **argv)
{
    return 0;
}

bool push(stackqueue* S, int x)
{
    node* s;
    s = (node*)malloc(sizeof(node));
    s->data = x;
    s->next = NULL;

    if (S->base == NULL)
    {
        S->base = s;
        S->top = s;
    }
    else
    {
        S->top->next = s;
        S->top = s;
    }
    return true;
}

bool pop(stackqueue* S)
{
    node* p;
    if (S->base == NULL)
    {
        cout << "overflow!\n";
        return false;
    }
    else
    {
        p = S->base;
        if (S->base == S->top)
        {
            S->base = NULL;
            S->top = NULL;
        }
        else
        {
            while (p->next != S->top)
            {
                p = p->next;
            }
            S->top = p;
            S->top->next = NULL;
        }
    }
    return true;
}
