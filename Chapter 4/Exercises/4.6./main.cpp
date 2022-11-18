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
    CandyBar snack[3] =
    {
        {"Snikers",1.8,400},
        {"Mars",1.2,322},
        {"Twix",1.6,289}
    };
    cout << "Name of the first snack is " << snack[0].name << endl;
    cout << "Weight of the first snack is " << snack[0].weight << endl;
    cout << "There are " << snack[0].calories <<  " calories in the first snack." << endl << endl;
    cout << "Name of the second snack is " << snack[1].name << endl;
    cout << "Weight of the second snack is " << snack[1].weight << endl;
    cout << "There are " << snack[1].calories <<  " calories in the second snack." << endl << endl;
    cout << "Name of the third snack is " << snack[2].name << endl;
    cout << "Weight of the third snack is " << snack[2].weight << endl;
    cout << "There are " << snack[2].calories <<  " calories in the third snack." << endl << endl;
    return 0;
}
