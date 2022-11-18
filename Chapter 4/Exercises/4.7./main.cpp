#include <iostream>
struct Pizza
{
    char name[100];
    int diameter;
    double weight;
};
int main()
{
    using namespace std;
    Pizza menu;
    cout << "Enter the name of the pizza: ";
    cin.getline(menu.name,100);
    cout << "Enter its diameter: ";
    cin >> menu.diameter;
    cout << "Enter its weight: ";
    cin >> menu.weight;
    cout << "Pizza's name is:\t" << menu.name << endl;
    cout << "Pizza's diameter is:\t" << menu.diameter << endl;
    cout << "Pizza's weight is:\t" << menu.weight << endl;
    return 0;
}
