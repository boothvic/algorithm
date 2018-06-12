/*
 * Author: L.F.N   File Name: doubleLinkList.cpp
 * Created Time: 2018年06月10日 星期日 09时39分09秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

struct dnode
{
    int data;
    struct dnode* next;
    struct dnode* pre;
};

dnode* create()
{
    dnode *head, *p, *s;
    head = (dnode*)malloc(sizeof(dnode));
    p = head;
    int x, cycle = 1;
    while (cycle)
    {
        cout << "Enter x: ";
        cin >> x;
        if ( x!= 0)
        {
            s = (dnode*)malloc(sizeof(dnode));
            s->data = x;
            cout << s->data << endl;
            p->next = s;
            s->pre = p;
            p = s;
        }
        else
            cycle = 0;
    }
    head = head->next;
    head->pre = NULL;
    p->next = NULL;

    return head;
}

dnode* del(dnode* head, int num)
{
    dnode *p;
    p = head;
    while (num != p->data && p->next != NULL)
    {
        p = p->next;
    }

    if (num == p->data)
    {
        if (p == head)  //头节点
        {
            head = head->next;
            head->pre = NULL;
            free(p);
        }
        else if (p->next == NULL) //尾节点
        {
            p->pre->next = NULL;
            free(p);
        }
        else
        {
            p->next->pre = p->pre;
            p->pre->next = p->next;
            free(p);
        }
    }
    else
    {
        cout << "not found!\n";
    }
    return head;
}

dnode* insert(dnode* head, int num)
{
    dnode *p, *q;
    q = head;
    p = (dnode*)malloc(sizeof(dnode)); //新节点
    p->data = num;

    while (p->data > q->data && q->next != NULL)
    {
        q = q->next;
    }

    if (p->data <= q->data)
    {
        if (head == q)
        {
            p->next = q;
            q->pre = p;
            head = p;
        }
        else
        {
            q->pre->next = p;
            p->next = q;
            p->pre = q->pre;
            q->pre = p;
        }
    }
    else  //比表中所有数值都大，插入到表尾
    {
        q->next = p;
        p->pre = q;
        p->next = NULL;
    }
    return head;
}

void print(const dnode* head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main(int argc, char **argv)
{
    dnode* head;
    dnode one;
    int n, delNum, insertNum;
    head = create();
    print(head);
    cout << "\ndelete date : ";
    cin >> delNum;
    head = del(head, delNum);
    print(head);
    cout << "\ninsert data: ";
    cin >> insertNum;
    head = insert(head, insertNum);
    print(head);

    return 0;
}
