#ifndef PERSON_H_
#define PERSON_H_

#include <cstdlib>          //для rand(), srand()
#include <ctime>            //time()
#include <string>
#include <iostream>

class Person
{
    private:
        std::string fname;
        std::string lname;
    protected:
        virtual void Data() const;
        virtual void Get();
    public:
        Person() : fname("NONE"), lname("NONE") {} 
        Person(std::string & fn, std::string & ln) : fname(fn), lname(ln) {}
        virtual ~Person() = 0;
        virtual void Show() const = 0;
        virtual void Set() = 0;
};

class Gunslinger : virtual public Person
{
    private:
        double ready_time;
        int cuts;
    protected:
        void Data() const;
        void Get();
    public:
        Gunslinger() : Person(), ready_time(0), cuts(0) {}
        Gunslinger(std::string & fn, std::string & ln, double rt, int c) : Person(fn,ln), ready_time(rt), cuts(c) {}
        Gunslinger(const Person & p, double rt, int c) : Person(p), ready_time(rt), cuts(c) {}
        void Show() const;
        void Set();
        double Draw() const {return ready_time;}
};

class PokerPlayer : virtual public Person
{
    private:
        int card;
    protected:
        void Data() const;
        void Get();
    public:
        PokerPlayer() : Person(), card(0) {}
        PokerPlayer(std::string & fn,std::string & ln, int card) : Person(fn,ln), card(card) {}
        PokerPlayer(const Person & p, int card) : Person(p), card(card) {}
        void Show() const;
        int Draw();
        void Set();
};

class BadDude : public Gunslinger, public PokerPlayer
{
    protected:
        void Data() const;
        void Get();
    public:
        BadDude() {}
        BadDude(std::string & fn, std::string & ln, double rt, int c, int card) : Person(ln,fn), Gunslinger(fn,ln, rt,c), PokerPlayer(fn,ln, card) {}
        BadDude(const Person & p, double rt,int c,int card) : Person(p), Gunslinger(p, rt, c), PokerPlayer(p, card) {}
        BadDude(const Gunslinger & p, int card) : Person(p), Gunslinger(p), PokerPlayer(p, card) {}
        BadDude(const PokerPlayer & p, double rt, int c) : Person(p), Gunslinger(p, rt, c), PokerPlayer(p) {}
        void Show() const;
        int Cdraw();
        double Gdraw();
        void Set();
};

#endif
