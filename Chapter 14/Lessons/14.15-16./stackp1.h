//stackp1.h -- модифицироавнный шаблон Stack

#ifndef STACKP1_H_
#define STACKP1_H_

template <class Type>
class Stack
{
private:
    enum{SIZE = 1};
    int stacksize;
    Type * items;
    int top;
public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack & st);                //конструктор копирования
    ~Stack() {delete [] items; }
    bool isempty() {return top == 0; }
    bool isfull() {return top == stacksize; }
    bool push(const Type & item);           //добавление item в стек
    bool pop(Type & item);                  //выталкивание верхнего элемента в item
    Stack & operator=(const Stack & st);    //оператор присваивания
};

template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
    items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0; i < top; i++)
    {
        items[i] = st.items[i];
    }
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if(top < stacksize)
    {
        items[top++] = item;
        return true;
    }else{
        return false;
    }
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }else{
        return false;
    }
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if(this == &st)
    {
        return *this;
    }else{
        delete [] items;
        stacksize = st.stacksize;
        top = st.top;
        items = new Type[stacksize];
        for(int i = 0; i < top; i++)
        {
            items[i] = st.items[i];
        }
        return *this;
    }
}

#endif
