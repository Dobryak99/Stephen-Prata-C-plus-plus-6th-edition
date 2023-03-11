//list.cpp -- использование списка
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n) { std::cout << n << " "; }

int main()
{
    using namespace std;
    
    int stuff[5] = {1,2,4,8,6};
    list<int> one(5,2);                         //список из 5 двоек
    list<int> two;
    two.insert(two.begin(), stuff,stuff + 5);
    int more[6] = {6,4,2,4,6,5};
    list<int>three(two);
    three.insert(three.end(), more, more + 6);
    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl << "List two: ";               //второй список
    for_each(two.begin(), two.end(), outint);
    cout << endl << " List three: ";            //третий список
    for_each(three.begin(), three.end(), outint);
    three.remove(2);
    cout << endl << "List three minus 2s: ";    //вычитание второго списка из третьего
    for_each(three.begin(), three.end(), outint);
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";    //третий список после splice()
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);
    three.unique();
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);
    three.sort();
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);
    two.sort();
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    return 0;
}
