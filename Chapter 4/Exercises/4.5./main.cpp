#include <iostream>
struct CandyBar
{
    char name[20];
    double weight;
    int calories;
};
int main()
{
    using namespace std;
    CandyBar snack =
    {
        "Mocha Munch",
        2.3,
        350
    };
    cout << "Snack's name is " << snack.name << endl;
    cout << "Snack's weight is " << snack.weight << " pounds." << endl;
    cout << "Snack's calories are " << snack.calories << endl;
    return 0;
}

