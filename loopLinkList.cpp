/*
 * Author: L.F.N   File Name: loopLinkList.cpp
 * Created Time: 2018年06月10日 星期日 10时47分00秒
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
    node *next;
};

void outLoopLink(int n, int k, int m)
{
    node *p, *q, *curr;
    p = (node*)malloc(sizeof(node));
    p->data = 0;
    p->next = p;
    curr = p;
    for (int i = 1; i < n; i++)
    {
        q = (node*)malloc(sizeof(node));
        q->data = i;
        q->next = curr->next;
        curr->next = q;
        curr = q;
    }

    node* r = curr;
    while (k--)
    {
        r = p;
        p = p->next;
    }
    while (n--)
    {
        for (int s = m-1;s--;r=p,p=p->next);
        r->next = p->next;
        cout << p->data << endl;
        free(p);
        p = r->next;
    }
}

int main(int argc, char **argv)
{
    outLoopLink(13, 4, 2);
    return 0;
}
