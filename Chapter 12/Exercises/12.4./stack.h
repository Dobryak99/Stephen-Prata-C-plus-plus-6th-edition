#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;
class Stack
{
    private:
        enum{MAX = 10};
        Item * pitems;                      //хранит элементы стека
        int size;                           //количество элементов в стеке
        int top;                            //индекс для верхнего элемента в стеке
    public:
        Stack(int n = 10);                  //Создает стек с n элементами
        Stack(const Stack & st);
        ~Stack();
        bool isempty() const;
        bool isfull() const;

        //push() возвращает значение false, если стэк заполнен,
        // и true в противном случае
        bool push(const Item & item);       //добавление жлемента в очередь

        //pop() возвращает значение false, если стэк уже пустой
        // и true в противном случае
        bool pop(Item & item);

        Stack & operator=(const Stack & st);
        friend std::ostream & operator<<(std::ostream & os, const Stack & st);
};

#endif
