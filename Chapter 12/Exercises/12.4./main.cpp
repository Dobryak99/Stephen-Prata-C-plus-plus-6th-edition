#include <iostream>
#include <cctype>
#include "stack.h"
#include "stack.cpp"

int main()
{
    using namespace std;
    cout << "--Setting stack1--\n";
    Stack stack1;
    cout << "--Setting stack2--\n";
    Stack stack2(3);
    cout << "--Setting stack3--\n";
    Stack stack3(-2);
    cout << "--Setting stack4--\n";
    Stack stack4(8);
    cout << endl;
    
    cout << "stack1.isempty = " << stack1.isempty() << endl;
    
    stack1.push(30);
    stack1.push(35);
    stack1.push(40);
    
    stack4 = stack1;
    stack3 = stack1;
    unsigned long x = 0;
    stack3.pop(x);
    cout << "Stack1: " << stack1 << endl;
    cout << "Stack4: " << stack4 << endl;
    cout << "Stack3: " << stack3 << endl;
    
    return 0;
    
    
    
    
    
}
