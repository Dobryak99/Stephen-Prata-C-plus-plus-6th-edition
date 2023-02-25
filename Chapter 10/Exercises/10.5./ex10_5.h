#ifndef _10_5_H_
#define _10_5_H_

struct customer
{
    char fullname[35];
    double payment;
};

typedef customer Item;
 
class Stack
{
    private:
        enum{Max = 10};
        Item items[Max];   //   хранит элементы стека
        int top;
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item & items);
        bool pop(Item & items);
};


#endif
