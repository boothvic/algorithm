/*
 * Author: L.F.N   File Name: fillFrame.cpp
 * Created Time: 2018年06月05日 星期二 16时24分18秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;
#include <cstring>

struct stringy
{
    char* str;
    int ct;
};

void show(const struct stringy sty, int n =1);
void show(const char* st,  int n = 1);
int set(struct stringy&, const char *);

int main(int argc, char **argv)
{
    struct stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void show(const struct stringy sty, int n )
{
    cout << "call show():\n";
    if (n == 1)
        cout << sty.str << endl;
    else
    {
        while (n-- > 0)
            cout << sty.str << endl;
    }
    cout << "call show() end:\n";
}

void show(const char* st,  int n)
{
    if (n == 1)
        cout << st << endl;
    else
    {
        while (n-- > 0)
            cout << st << endl;
    }
}

int set(struct stringy& sty, const char * st)
{
    sty.ct = strlen(st);
    char * stys = new char[sty.ct + 1];
    int i;
    for (i = 0; i < sty.ct; i ++)
    {
        stys[i] = *st;
        st ++;
    }
    stys[i] = '\0';
    cout <<"call set(): " << endl;
    sty.str = stys;
    return 0;
}

