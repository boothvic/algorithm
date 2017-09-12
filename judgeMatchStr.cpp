/*
 * Author: Vic Lin   File Name: judgeMachingStrng.cpp
 * Created Time: 2017年09月11日 星期一 13时25分00秒
 *
 * Cpp source code - replace this with a description
 * of the code and write the code below this text
 *
 */


#include <iostream>
#include <string>
using namespace std;

string utilityFunction(string s,int j);
bool noName(string a, string b);

void utilityFunctionTest();
void noNameTest();

int main(int argc, char * argv[])
{
    utilityFunctionTest();
    noNameTest();
    return 0;
}

string utilityFunction(string s,int j)
{
    char* ret = new char[s.length()];
    int d = 0;
    for (int k = 0; k < s.length();k++){
        if (k == j)
            d = 1;
        else
            ret[k-d] = s[k];
    }
    ret[s.length()] = '\0';
    string retStr(ret);
    delete [] ret;
    return retStr;
}

bool noName(string a, string b)
{
    if (a.length() != b.length())
        return false;
    for (int x = 0; x < b.length(); x++){
        if (a[0] == b[x])
            return noName(utilityFunction(a,0), utilityFunction(b,x));
    }
    return b.length() == 0;
}

void utilityFunctionTest()
{
    cout << "Test utilityFunction... \n";
    string s = "abcdefg";
    cout << "when j<s.length():\n";
    for (int i = 0; i < s.length(); ++i){
        cout << "#" << i << " " << utilityFunction(s,i) <<endl;
    }
    cout << "when j>=s.length():\n";
    for (int i = s.length()+2; i >= s.length();--i){
        cout << "#" << i << " " << utilityFunction(s,i) <<endl;
    }

    cout << "Test end!\n";
}

void noNameTest()
{
    const int N = 5;
    string a[N] = {"abcdef","abcdef","abcdef","abcdefhijk","abcdefhijk"};
    string b[N] = {"abcdef","fdecba","uvwxyz","abcdef","uvwxyz"};
    int ret[N] = {1,1,0,0,0};
    cout << "\nTest noName... \n";
    cout << "Expected\tReal\n";
    for (int i = 0; i < N; ++i ){
        cout << ret[i] <<"\t\t" << noName(a[i],b[i]) << endl;
    }

    cout << "Test end!\n";
}
