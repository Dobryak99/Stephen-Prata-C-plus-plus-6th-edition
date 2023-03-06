//tv.h -- классы Tv и Remote

#ifndef TV_H_
#define TV_H_

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
    void settings() const;                      //отображение всех настроек
};

class Remote
{
private:
    int mode;                                   //управление TV or DVD
public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) {t.onoff();}
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) { t.set_input();}
};


#endif
