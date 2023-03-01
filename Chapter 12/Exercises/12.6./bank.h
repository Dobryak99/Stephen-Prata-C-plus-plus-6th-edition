#ifndef BANK_H_
#define BANK_H_

class Customer
{
    private:
        long arrive;                    //момент появления в очереди
        int processtime;                //время обслуживания клиента
    public:
        Customer() {arrive = processtime = 0;}
        void set(long when);
        long when() const { return arrive; }
        int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
    private:
        //Определение области действия класа
        // Node - это вложенное определение структуры, локальное для данного класса
        struct Node
        {
            Item item;
            struct Node * next;
        };
        enum{Q_SIZE = 10};

        // Закрытые члены класа
        Node * front;                   // указатель на начало Queue
        Node * rear;                    // указатель на конец Queue
        int items;                      // количество элементов в очереди
        const int q_size;               //максимальное количество элементов в очереди
    public:
        Queue(int qs = Q_SIZE);         //создание очереди с предельным размером qs
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item & item);           //добавление элемента в конец очереди
        bool dequeue(Item & item);                  //удалени из очереди
        Queue(const Queue & q) : q_size(0) {}       //констурктор копирования
        Queue & operator=(const Queue & q) {return *this;}  // оператор присваивания
};


#endif
