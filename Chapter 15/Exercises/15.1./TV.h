#ifndef TV_H_
#define TV_H_

#include <iostream>
class Remote;
class Tv
{
private:
    int state;                                  //ON or OFF
    int volume;                                 //дискретные уровни громкости
    int maxchannel;                             //максимальное количество каналов
    int channel;                                //текущий канал
    int mode;                                   //ANTENA or CABEL
    int input;                                  //TV or DVD
public:
    friend class Remote;                        // Remote имеет доступ к закрытой части TV
    enum{Off, On};                              //включен или выключен
    enum{MinVal, MaxVal = 20};                  //настройка уровня громкости
    enum{Antena, Cable};                        //режим настройки кабеля или антены
    enum{TV, DVD};                              //сигнал от антены или видеоплеера
    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On) ? Off : On;}
    bool ison() const { return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antena) ? Cable : Antena;}
    void set_input() {input = (input == TV) ? DVD : TV;}
    void settings(Remote & r) const;                      //отображение всех настроек
    void set_remote(Remote & r);
};

class Remote
{
private:
    int mode;                                   //управление TV or DVD
    int regime;
public:
    enum{Normal, Interactive};                  //режим пульта 
    friend class Tv;
    Remote(int m = Tv::TV, int r = Normal) : mode(m), regime(r) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) {t.onoff();}
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) { t.set_input();}
    void set_remote() { regime = (regime == Normal) ? Interactive : Normal; }
};


#endif
