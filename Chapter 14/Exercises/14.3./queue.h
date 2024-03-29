#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
template <class T>
class Queue
{
    private:
        struct Node                             //структура для хранения элементов очереди
        {
            T value;                            //поле для хранения элемента очереди
            Node * next_elem_addr;              //поле для хранения следующего элемента
        };
        Node * head;                            // указатель, хранящий адрес головы(начала) очереди
        Node * tail;                            // указатель, хранящий адрес хвоста(конца) очереди
        int max_size;                           // Максимальный размер очереди
        int items;                              //количестов элементов
    public:
        Queue();                                //конструктор. создает пустую очередь
        Queue(int s);                           //констуктор. В параметре передается РАЗМЕР очереди
        ~Queue();
        bool isempty() const;                   // Функция проверяет пустая ли очередь
        bool isfull() const;                    // Функция проверяет заполнена ли очередь
        int queue_count() const;                //возвращает количество элементов в очереди
        bool push(T & value);                   // Добавляет(вталкивает) элемент в очередь
        bool pop(T & value);                    //Удаляет элемент(выталкивает) и возвращает его
};


#endif
