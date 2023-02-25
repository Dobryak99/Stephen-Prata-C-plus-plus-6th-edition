#include <iostream>
#include "10.8.h"
#include <cctype>
 List::List()
 {
    std::string items[Max];
    top = 0;
 }

 List::~List()
 {

 }

 bool List::isempty() const
 {
    return top == 0;
 }

 bool List::isfull() const
 {
    return top == Max;
 }

 bool List::add(const std::string & item)
 {
    if(top < Max)
    {
        items[top++] = item;
        return true;
    }else{
        return false;
    }
 }

 void List::visit(void (*pf)(std::string &))
 {
    for(int i = 0; i  < top; i++)
    {
        (*pf)(items[i]);
    }
 }

 void List::reset()
 {
    std::string items[Max];
    top = 0;
 }

 void List::show() const
 {
    for(int i = 0; i < top;i++)
    {
        std::cout << "\nItem #" << i + 1  << " = " << items[i] << std::endl;
    }
 }
 
 
