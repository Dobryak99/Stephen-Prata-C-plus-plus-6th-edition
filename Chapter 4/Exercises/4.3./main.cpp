#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char name[100];
    char surname[100];
    char sum[200];
    cout << "Enter Your first name: ";
    cin >> name;
    cout << "Enter your last name: ";
    cin >> surname;
    strcpy(sum, name);  //копировать name в sum
    strcat(sum, ", "); // добавить ", " в sum
    strcat(sum, surname); //добавить surname  в sum
    cout << "Here's the information in a single string: " << sum << endl;
    return 0;
}
