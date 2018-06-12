/*
 * Author: L.F.N   File Name: stack.cpp
 * Created Time: 2018年06月11日 星期一 14时43分07秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

const int STACKINITSIZE = 100;
const int STACKINCREMENT = 10;

struct SqStack
{
    int* base;
    int* top;
    int stacksize;
};

bool InitStack(SqStack& S);
bool GetTop(const SqStack S, int& e);
bool Push(SqStack& S, int e);
bool Pop(SqStack& S, int& e);
bool StackTraverse(SqStack S, bool (*visit)());

int StackLength(const SqStack& S)
{
    return S.stacksize;
}

bool StackEmpty(const SqStack& S)
{
    if (S.top == S.base)
        return true;
    return false;
}

bool ClearStack(SqStack& S)
{
    if (StackEmpty(S))
        return true;
    while (S.top != S.base)
        *--S.top = 0;
    return true;
}

bool DestoryStack(SqStack& S)
{
    free(S.base);
    S = {NULL, NULL, 0};
    return true;
}

int main(int argc, char **argv)
{
    SqStack S = {NULL, NULL, 0};
    //SqStack& S = Sq;
    if (StackEmpty(S))
        cout << "Empty stack\n";
    if (!InitStack(S))
        cout << "Init error!\n";
    if (Push(S, 233))
        cout << "Push: " << *(S.top-1) << endl;
    if (Push(S, 2333))
        cout << "Push: " << *(S.top-1) << endl;
    if (Push(S, 23333))
        cout << "Push: " << *(S.top-1) << endl;
    int e = 0;
    if (GetTop(S,e))
        cout << "GetTop: " << e << endl;
    if (Pop(S,e))
        cout << "Pos: " << e << endl;
    //if (ClearStack(S))
    //    cout << "Clear stack\n";
    if (DestoryStack(S))
        cout << "Destory stack\n";
    //cout << *(S.top) << endl;
    if (StackEmpty(S))
        cout << "Empty stack\n";
    cout << "Length: " << StackLength(S) << endl;
    return 0;
}

bool InitStack(SqStack& S)
{
    S.base = (int*)malloc(STACKINITSIZE *sizeof(int));
    if (!S.base)
        return false;
    S.top = S.base;
    S.stacksize = STACKINITSIZE;
    return true;
}

bool GetTop(SqStack S, int& e)
{
    if (S.top == S.base)//判断栈是否为空
        return false;
    e = *(S.top-1);
    return true;
}
bool Push(SqStack& S, int e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (int*)realloc(S.base, 
                (S.stacksize + STACKINCREMENT) * sizeof(int));
        if (!S.base)
            return false;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return true;
}

bool Pop(SqStack& S, int& e)
{
    if (S.top == S.base)
        return false;
    e = *--S.top; //与*S.top--等价
    return true;
}
