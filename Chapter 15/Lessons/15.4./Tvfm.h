//tvfm.h -- классы Tv и Remote и дружественная функция член

#ifndef TVFM_H_
#define TVFM_H_

class Tv;

class Remote
{
public:
    enum State{Off, On};
    enum {MinVal, MaxVal = 20};
    enum{Antena, Cable};
    enum {TV, DVD};
private:
    int mode;
public:
    Remote(int m = TV) : mode(m) {}
    bool volup(Tv & t);                 //только прототип
    bool voldown(Tv & t);
    void onoff(Tv & t);
    void chanup(Tv & t);
    void chandown(Tv & t);
    void set_mode(Tv & t);
    void set_input(Tv & t);
    void set_chan(Tv & t, int c);
};

class Tv
{
public:
    friend void Remote::set_chan(Tv & t, int c);
    enum State{Off, On};
    enum {MinVal, MaxVal = 20};
    enum{Antena, Cable};
    enum {TV, DVD};
    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On) ? Off : On;}
    bool ison() {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antena) ? Cable : Antena;}
    void set_input() {input = (input == TV) ? DVD : TV;}
    void settings() const;
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

//методы Remote как встроенные функции
inline bool Remote::volup(Tv & t) {return t.volup();}
inline bool Remote::voldown(Tv & t) {return t.voldown();}
inline void Remote::onoff(Tv & t) {return t.onoff();}
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) {t.chandown();}
inline void Remote::set_mode(Tv & t) { t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}
inline void Remote::set_chan(Tv & t, int c) {t.channel = c;}



#endif
