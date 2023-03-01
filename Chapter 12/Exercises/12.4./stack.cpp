#include <iostream> 
#include "stack.h"

Stack::Stack(int n)
{
    if (n < 1)
	{
		std::cout << "Error. Argument must be a positive integer. ";
		std::cout << "Setting n to 10." << std::endl;
		n = 10;
	}
	pitems = new Item[n];
	size = top = 0;
}

Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    for(int i = 0; i < st.size; i++)
    {
        pitems[i] = (st.pitems)[i];
    }
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if(top < MAX)
    {
        //происходит увеличение стэка на один элемент
        // и этому элементу присваивают значение item
        pitems[top++] = item;
        return true;
    }else{
        return false;
    }
}

bool Stack::pop(Item & item)
{
    if(top > 0)
    {
        //item присваивается предыдущее значение в стэке
        item = pitems[--top];
        return true;
    }else{
        return false;
    }
}

Stack & Stack::operator=(const Stack & st)
{
    if(this == &st)
    {
        return *this;
    }
    delete [] pitems;
    
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for(int i = 0; i < size; i++)
    {
        pitems[i] = (st.pitems)[i];
    }
    return *this;

}

std::ostream & operator<<(std::ostream & os, const Stack & st)
{
    for(int i = 0; i < st.top; i++)
    {
        os << "item #" << i + 1 << " = " << (st.pitems)[i] << std::endl;
    }
    return os;
}

