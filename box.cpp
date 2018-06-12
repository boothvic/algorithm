/*
 * Author: L.F.N   File Name: box.cpp
 * Created Time: 2018年06月05日 星期二 09时21分20秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float lenght;
    float volume;
};

void showBox(struct box);
bool changeBoxVolume(struct box*);

int main(int argc, char **argv)
{
    struct box oneBox = {"L.F.N", 2.0, 3.0, 4.0, 0.0};
    showBox(oneBox);
    if (!changeBoxVolume(&oneBox))
        cout << "call changeBoxVolume function error!\n";
    showBox(oneBox);
    return 0;
}

void showBox(struct box oneBox)
{
    cout << "maker: " << oneBox.maker << endl;
    cout << "height: " << oneBox.height << endl;
    cout << "width: " << oneBox.width << endl;
    cout << "lenght: " << oneBox.lenght << endl;
    cout << "volume: " << oneBox. volume << endl;
}
bool changeBoxVolume(struct box* oneBox)
{
    cout << "call changeBoxVolume: \n";
    oneBox->volume = oneBox->height *  oneBox->width * oneBox->lenght;
    //cout << oneBox->volume << endl;
    return true;
}
