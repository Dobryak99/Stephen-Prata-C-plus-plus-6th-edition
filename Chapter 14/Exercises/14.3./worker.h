//workermi.h --классы работников с множественым наследованием
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

class Worker                                    // Работник - АБК(абстрактный базовый класс)
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string & s, long n) : fullname(s) , id(n) {}
    virtual ~Worker() = 0;                  //чистый виртуальный деструктор
    virtual void Set() = 0;
    virtual void Show() const = 0;
};


class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0) : Worker(s,n), panache(p) {}
    Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum{other, alto, contralto, soprano, bass, baritone, tenor};
    enum{Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char * pv[Vtypes];                   //строковые эквиваленты видов голосов
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other) : Worker(s,n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const std::string &s, long n, int p = 0, int v = other) : Worker(s,n) , Waiter(s,n,p), Singer(s,n,v) {}
    SingingWaiter(const Worker & wk, int p = 0, int v = other) : Worker(wk), Waiter(wk,p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wk, int v = other) : Worker(wk), Waiter(wk), Singer(wk, v) {}
    SingingWaiter(const Singer & wk, int p = 0) : Worker(wk), Waiter(wk,p), Singer(wk) {}
    void Set();
    void Show() const;
};

#endif

