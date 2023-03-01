#include "bank.h"
#include <cstdlib>              //для rand()

Queue::Queue(int qs) : q_size(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while(front != nullptr)
    {
        temp = front;               //сохранение адреса начального элемента
        front = front -> next;      //переустановка указателя на следующий элемент
        delete temp;                //удаление предыдущего начального элемента
    }
}

bool Queue::isempty()const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == q_size;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if(isfull())
    {
        return false;
    }
    Node * add = new Node;          //создание узла
    add -> item = item;             // занесение указателей на узлы
    add -> next = nullptr;
    items++;
    if(front == nullptr)
    {
        front = add;                //элемент помещается в начало
    }else{
        rear -> next = add;         //иначе он помещается в конец
    }
    rear = add;                     //смена указателя конца(указывает на новый узел)
    return true;
}

bool Queue::dequeue(Item & item)
{
    if(isempty())
    {
        return false;
    }
    item = front -> item;
    items--;
    Node * temp = front;
    front = front -> next;
    delete temp;
    if(items == 0)
    {
        rear = nullptr;
    }
    return true;
}


//при появлении клиента фиксриутеся момент его прибытия, а время
// обслуживание выбирается случайным образом из диапазона 1 - 3 
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
