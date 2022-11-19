#include <iostream>
int main()
{
    using namespace std;
    double Dafna_profit = 100;
    double Cleo_profit = 100;
    int year = 0;
    do
    {
        year++;
        Dafna_profit += 0.10 * 100;
        Cleo_profit += Cleo_profit * 0.05;
        cout << "Dafna's profit " << Dafna_profit << " per " << year << " years." << endl;
        cout << "Cleo's profit " << Cleo_profit << " per " << year << " years." <<  endl;
        cout << "====================================================" << endl;
    }while (Dafna_profit >= Cleo_profit);
    cout << "It took " << year << " years.\n";
    return 0;
}
