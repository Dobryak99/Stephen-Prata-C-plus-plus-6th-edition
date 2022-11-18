#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout << "What is your first name? ";
    string name;
    getline(cin, name);
    cout << "What is your last name? ";
    string surname;
    getline(cin,surname);
    cout << "What letter grade do your deserve? ";
    char grade;
    cin >> grade;
    grade += 1; //изменение оценки
    cout << "What is your age? ";
    int age;
    cin >> age;
    cout << "Name: " << surname << ", " << name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;
    return 0;
}
