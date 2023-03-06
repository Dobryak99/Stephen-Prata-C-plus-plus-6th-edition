//queuetp.h - шаблон очереди с вложенным классом
#ifndef QUEUETP_H_
#define QUEUETP_H_

template<class Item>
class QueueTP
{
private:
    enum{Q_SIZE = 10};
    //Node - определение вложенного класса
    class Node
    {
    public:
        Item item;
        Node * next;
        Node(const Item & i) : item(i), next(nullptr) {}
    };
    Node * head;
    Node * tail;
    int items;
    const int qsize;
    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP & operator=(const QueueTP & q) {return *this;}
public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const {return items == 0;}
    bool isfull() const {return items == qsize;}
    int queuecount() const {return items;}
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

//методы QueueTP

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    head = tail = nullptr;
    items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
    Node * temp;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
    if(isfull())
    {
        return false;
    }
    Node * add = new Node(item);
    items++;
    if(head == 0)
    {
        head = add;
    }else{
        tail ->next = add;
    }
    tail = add;
    return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if(head == 0)
    {
        return false;
    }
    item = head -> item;
    items--;
    Node * temp = head;
    head = head ->next;
    delete temp;
    if(items == 0)
    {
        tail = nullptr;
    }
    return true;
}



#endif
