#include <iostream>
long double probability(unsigned numbers, unsigned picks);
int main()
{
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and ";
    cout << "the number of picks allowed:\n";
    while((cin >> total >> choices) && choices <= total)
    {
        int Meganumber = (total / 2) / 1;   //вероятность мегачисла из половины всех чисел
        double result = probability(total, choices) * Meganumber;  // вероятность выиграть суперприз
        cout << "You have one chance in ";
        cout << result;
        cout << " of winning.\n";
        cout << "Next four numbers(q to quit):";
    }
    cout << "Bye!\n";
    return 0;
}
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned int p;
    for(n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
