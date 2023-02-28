
//queue.h -- интерфейс для очереди
#ifndef QUEUE_HPP_
#define QUEUE_HPP_

//Очередь содержащая элементы Customer
class Customer
{
private:
    long arrive;                                    //момент появления клиента
    int processtime;                                //время обслуживания клиента
public:
    Customer() {arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const { return processtime;}
};

typedef Customer Item;

class Queue
{
private:
    //определение области действия класса
    //Node - вложенная структура, локальная для данного класса
    struct  Node
    {
        Item item;
        struct Node * next;
    };
    enum{Q_SIZE = 10};
    
    //закрытые члены класса
    Node * front;                                   // Указатель на начало Queue
    Node * rear;                                    // Указатель на конец Queue
    int items;                                      // текущее количество элементов в Queue
    const int qsize;                                //максимальное количество элементов Queue
    
    //упреждение объявления для предотвращения открытого копирования
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) {return *this;}
public:
    Queue(int qs = Q_SIZE);                         //создание очереди с предельным размером qs
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);               //добавление элемента в конец
    bool dequeue(Item & item);                      //удаление элемента из начала
};


#endif
