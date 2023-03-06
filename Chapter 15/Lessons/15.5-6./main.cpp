//nested.cpp -- использование очереди имеющий вложенный класс
#include <iostream>
#include <string>
#include "QueueTP.h"

int main()
{
    using std::string;
    using std::cin;
    using std::cout;
    QueueTP<string> cs(5);
    string temp;
    while(!cs.isfull())
    {
        cout << "Enter your name. you will be "
        << "served in the order of arrival.\n"
        << "Name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. processing begins!\n";
    
    while(!cs.isempty())
    {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
    return 0;
}
