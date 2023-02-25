#ifndef _10_8_H_
#define _10_8_H_
#include <string>

class List
{
    private:
        static const int Max = 5;
        std::string items[Max];
        int top;
    public:
        List();
        ~List();
        bool isempty() const;
        bool isfull() const;
        bool add(const std::string & item);
        void visit(void (*pf)(std::string &));
        void reset();
        void show() const;
};

#endif
