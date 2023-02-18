#include <iostream>
using namespace std;
struct CandyBar
{
    const char * name;
    double weight;
    int callories;
};
void set(CandyBar &lollipops, const char * name = "Millenuim Munch",double weight = 2.85, int callories = 350);
void show(CandyBar & lollipops);
int main()
{
    CandyBar box1;
    CandyBar box2;
    CandyBar box3;
    set(box1);
    show(box1);
    set(box2, "Raffaelo", 3.50, 500);
    show(box2);
    set(box3, "Twix", 2.54,430);
    show(box3);
    return 0;
}
void set(CandyBar & lollipops, const char * name,double weight, int callories)
{
    lollipops.name = name;
    lollipops.weight = weight;
    lollipops.callories = callories;
}
void show(CandyBar & lollipops)
{
    cout << lollipops.name << endl;
    cout << lollipops.weight << endl;
    cout << lollipops.callories << endl;
}
