/*
 * Author: L.F.N   File Name: singleLinkList.cpp
 * Created Time: 2018年06月09日 星期六 15时21分50秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

strcut node
{
    int item;
    struct node *next;
};

node* create()
{
    node* head;
    node* *p;
    node* s;
    int x, cycle = 1;
    head = (node*)malloc(sizeof(node));
    p = head;
    while (cycle)
    {
        cout << "\ninput data: ";
        cin >> x;
        if (x != 0)
        {
            s = (node*)malloc(sizeof(node));
            s->item = x;
            cout << endl << s->item;
            p->next = s;
            p = s;
        }
        else
            cycle = 0;
    }
    head = head->next;
    p->next = NULL;
    cout << endl << head->item;
    return head;
}

int length(node* head)
{
    int n = 0;
    node* p;
    p = head;
    while (p != NULL)
    {
        p = p->next;
        ++n;
    }
    return n;
}

void print(node* head)
{
    node* p;
    int n;
    n = length(head);
    cout << n << " records in node.\n";
    p = head;
    while (p != NULL)
    {
        cout << endl;
        cout << p->item;
        p = p->next;
    }
}

node* del(node* head, int num)
{
    node* p;
    node* q;
    p = head;
    while (num != p->item && p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    if (num == p->item)
    {
        if (p == head)
        {
            head = p->next;
            free(p);
        }
        else
        {
            q->next = p->next;
            free(p);
        }
    }
    else
        cout << "could not been found.\n";
    return head;
}

node* insert(node* head, int num)
{
    node* p;
    node* q;
    node* r;
    p = head;
    q = (node*)malloc(sizeof(node));
    q->item = num;
    while (q->item > p->item && p->next != NULL)
    {
        r = q;
        p = p->next;
    }
    if (q->item <= p->item)
    {
        if (head == p)
        {
            q->next = p;
            head = q;
        }
        else
        {
            r->next = q;
            q->next = p;
        }
    }
    else
    {
        p->next = q;
        q->next = NULL;
    }
    return head;
}

node* sort(node* head)
{
    node* p;
    node* q;
    node* r;
    int n;
    int temp;
    n = length(head);
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    p = head;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (p->item > p->next->item)
            {
                temp = p->item;
                p->item = p->next->item;
                p->next->item = temp;
            }
            p = p->next;
        }
    }
    return head;
}

node* reverse(node* head)
{
    node* p;
    node* q;
    node* r;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    p = head;
    q = head->next;
    head ->next = NULL;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }

    head = p;
    return head;
}

int main(int argc, char **argv)
{
    node* head;
    int n, delNum, insertNum;
    head = create();
    print(head);

    cout << "\nInt: ";
    cin >> delNum;
    head = del(head, delNum);
    print(head);
    cout << "inset Int: ";
    cin >> insertNum;
    head = insert(head, insertNum);
    print(head);
    
    return 0;
}

