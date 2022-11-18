#include <iostream>
struct pizza
{
    char name[100];
    int diameter;
    double weight;
};
int main()
{
    using namespace std;
    pizza * ppizza = new pizza;
    cout << "Enter diametre of the pizza: ";
    cin >> ppizza -> diameter;   //первый способ
    cout << "Enter the name of the company: ";
    cin.get();
    cin.get(ppizza -> name,100);   //второй способ
    cout << "Enter its weight: ";
    cin >> (*ppizza).weight;   // третий способ
    cout << "The diametre of the pizza is: " << ppizza -> diameter << endl;
    cout << "The name of the company is: " << ppizza -> name << endl;
    cout << "The weight of the pizza is: " << (*ppizza).weight << endl;
    return 0;
}
