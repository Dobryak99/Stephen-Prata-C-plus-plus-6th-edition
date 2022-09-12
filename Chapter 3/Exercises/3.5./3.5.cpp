#include <iostream>
int main()
{
    using namespace std;
    long long pop_world, pop_usa;
    cout << "Enter the World's population:";
    cin >> pop_world;
    cout << "enter the population of USA:";
    cin >> pop_usa;
    double percent = (double(pop_usa) * 100) / double(pop_world); // преобразовали переенные в тип double
    cout << "The population of the USA is " << percent << "% of the World population." <<endl;
    return 0;
}
