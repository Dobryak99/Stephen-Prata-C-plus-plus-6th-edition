#ifndef CD2_H_
#define CD2_H_
#include <string>

//базовый класс
class Cd                                    //представляет компакт-диск
{
    private:
        char * performance;
        std::string label;
        int selections;                     //количество сборников
        double playtime;                    //время воспроизведения в минутах
    public:
        Cd(const char * s1,const std::string & s2, int n, double x);
        Cd(const Cd & d);
        Cd();
        virtual ~Cd();
        virtual void Report() const;        //вывод всех даных о диске
        Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
    private:
        char * track;
    public:
        Classic(const char * t,const char * s1,const std::string &s2, int n, double x);
        Classic(const char * t, const Cd & d);
        Classic();
        ~Classic();
        virtual void Report() const;
        Classic & operator=(const Classic & cl);
};


#endif
