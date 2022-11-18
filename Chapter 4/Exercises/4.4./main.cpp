#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string name;
    string surname;
    string sum;
    cout << "Enter your first name: ";
    getline(cin,name);
    cout << "Enter your last name: ";
    getline(cin,surname);
    sum = surname;
    sum += ", ";
    sum += name;
    cout << "Here's the information in a single string: " << sum << endl;
    return 0;
}
