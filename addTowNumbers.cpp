/*
 * Author: Vic Lin   File Name: addTwoNumbers.cpp
 * Created Time: 2017年12月10日 星期日 12时15分22秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL) {}
};

class Solution {
public:
    //method 1
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, i = 0, j = 0;
        while (l1 != NULL) {
            n1 += l1->val * pow(10, i++);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            n2 += l2->val * pow(10, j++);
            l2 = l2->next;
        }

        int sum = n1 + n2;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while (sum) {
            cur->next = new ListNode(sum%10);
            sum /= 10;
            cur = cur->next;
        }
        return res->next;
    }

    //method 2
    ListNode* add2Numbers(ListNode* l1, ListNode* l2) {
       ListNode* p = l1;
       ListNode* q = l2;
       ListNode* res = new ListNode(-1);
       ListNode* cur = res;
       int carry = 0;
       while (p || q ) {
           int x = (p?p->val:0);
           int y = (q?q->val:0);
           int sum = x + y + carry; 
           carry = sum / 10;
           cur->next = new ListNode(sum%10);
           cur = cur->next;
           if (p)
               p = p->next;
           if (q)
               q = q->next;
       }
       if (carry > 0)
           cur->next = new ListNode(carry);

        return res->next;
    }
};

int main(int argc, char **argv)
{
    ListNode* l1 = new ListNode(-1);
    ListNode* l2 = new ListNode(-1);

    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    int num;
    cout << "Input l1(End input with one negative number): ";
    while (cin >> num && num >=0) {
        cur1->next = new ListNode(num);
        cur1 = cur1->next;
    }

    cout << "Input l2(End input with one negative number): ";
    while (cin >> num && num >=0) {
        cur2->next = new ListNode(num);
        cur2 = cur2->next;
    }
    l1 = l1->next;
    l2 = l2->next;

    Solution s;
    //call method 1
    ListNode* r = s.addTwoNumbers(l1, l2);
    //call method 2
    //ListNode* r = s.add2Numbers(l1, l2);
    while (r) {
        cout << r->val << "\t";
        r = r->next;
    }
    return 0;
}
