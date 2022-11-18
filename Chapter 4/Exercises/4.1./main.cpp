#include <iostream>
int main ()
{
    using namespace std;
    const int size = 20;
    char name[size];
    char surname[size];
    char grade;
    int age;
    cout << "What is your first name ? ";
    cin.getline(name, size);
    cout << "What is your last name ? ";
    cin.getline(surname, size);
    cout << "What letter grade do you deserve ? ";
    cin >> grade;
    cout << "What is your age ? ";
    cin >> age;
    cout << "Name: " << surname << ", " << name << endl;
    grade += 1;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;
    return 0;
}
