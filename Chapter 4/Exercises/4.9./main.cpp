#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
    string name;
    double weight;
    int calories;
};
int main()
{
    CandyBar * pCandyBar = new CandyBar[3];  // создание динамической структуры из 3-х элементов
    
    //динамический массив нельзя инициализировать как статический массив, потому приходится инициализировать его почлено, т.к. это противоречит принципу и логике выделения динамической памяти
    
    pCandyBar[0].name = "Snikers";
    pCandyBar[0].weight = 2.78;
    pCandyBar[0].calories = 235;
    pCandyBar[1].name = "Twix";
    pCandyBar[1].weight = 2.01;
    pCandyBar[1].calories = 345;
    pCandyBar[2].name = "Mars";
    pCandyBar[2].weight = 1.963;
    pCandyBar[2].calories = 1025;
    
    cout << "The first snack's name is " << pCandyBar[0] .name << ". Its weight: " << pCandyBar[0].weight
    << ". Its calories are: " << pCandyBar[0].calories << endl;
    cout << "The second snack's name is " << pCandyBar[1] .name << ". Its weight: " << pCandyBar[1].weight
    << ". Its calories are: " << pCandyBar[1].calories << endl;
    cout << "The third snack's name is " << pCandyBar[2] .name << ". Its weight: " << pCandyBar[2].weight
    << ". Its calories are: " << pCandyBar[2].calories << endl;
    delete [] pCandyBar;
    return 0;
}
