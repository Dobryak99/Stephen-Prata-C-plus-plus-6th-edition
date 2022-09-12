#include <iostream>
int main()
{
    using namespace std;
    const double km_to_mile = 62.14;
    const double lit_to_gal = 3.875;
    double raskh_km;
    cout << "Введите расход топлива в Европейском стиле: ";
    cin >> raskh_km; // вводится расход топлива
    cout << raskh_km << " литров на 100 км." << endl;
    double gal = raskh_km / lit_to_gal; // преобразуем литры в галоны
    double mile = km_to_mile / gal; // находим мили на 1 галон
    cout << "В американском стиле это " << mile << " миль на галон.";
    return 0;
}
