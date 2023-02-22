// stack.h -- определение класса для абстрактного типа данных - стека
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    enum{MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    
    // push() возвращает false, если стек полон, и true - в противном случае
    
    bool push(const Item & item);   //добавляет элемент в стек
    
    //pop() возвращает false, если стек пуст, и true - в противном случае
    
    bool pop(Item & item);
};


#endif
