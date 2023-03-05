#include "queue.h"
template <class T>
Queue<T>::Queue()
{
    head = tail = nullptr;
    max_size = 0;
    items = 0;
}
template <class T>
Queue<T>::Queue(int s)                            //констуктор. В параметре передается РАЗМЕР очереди
{
    /* С сайта
    
    head = new Node;                    //выделяет память для хранения элемента
    tail = head;                        // При создании очереди хвост и голова являются одним и тем же элементом
    head->value = nullptr;              // записываем значение
    head->next_elem_addr = nullptr;     //записываем ноль т.к. другого элемента еще нету
    
    */
    head = tail = nullptr;              // Нету элементов
    max_size = s;                       // Очередь стала иметь размер s
    items = 0;
}
template <class T>
Queue<T>::~Queue()
{
    Node * temp;                        //хранение временного элемента
    while(head != nullptr)              //пока в очереди не закончатся клиенты
    {
        temp = head;                    // Сохранение адреса начального элемента
        head = head->next_elem_addr;    //назанчение НОВОГО адреса голове(следующий элемент)
        delete temp;                    //удаление старой головы
    }
}

template <class T>
bool Queue<T>::isempty() const             // Функция проверяет пустая ли очередь
{
    return items == 0;
}

template <class T>
bool Queue<T>::isfull() const
{
    return items == max_size;           // Функция проверяет заполнена ли очередь
}

template <class T>
int Queue<T>::queue_count() const          //возвращает количество элементов в очереди
{
    return items;
}

template <class T>
bool Queue<T>::push(T & value)             // Добавляет(вталкивает) элемент в очередь
{
    if(isfull())
    {
        return false;
    }
    Node * temp = new Node;             //выделяем память для хранения нового элемента
    temp->next_elem_addr = nullptr;     // Записываем в поле адреса нового хвоста ноль, так как за ним ничего нету
    temp->value = value;                //Заполняем поле значения нового хвоста
    if(head == nullptr)
    {
        head = temp;
    }else{
        tail->next_elem_addr = temp;    // Записываем в поле адреса старого хвоста адрес нового хвоста
    }
    tail = temp;                        //Записываем в указель хвоста адрес действительного хвоста
    items++;                            //увеличиваем количество элементов на 1
    return true;
}

template <class T>
bool Queue<T>::pop(T & value)              //Удаляет элемент(выталкивает) и возвращает его
{
    if(isempty())
    {
        return false;
    }

    Node * temp = head;                 //записываем адрес головы
    value = head -> value;              //записываем значение головы
    head = head->next_elem_addr;        //изменяем адрес головы
    delete temp;                        //удаляем старую голову
    items--;                            //уменьшаем размер очереди
    return true;
}
