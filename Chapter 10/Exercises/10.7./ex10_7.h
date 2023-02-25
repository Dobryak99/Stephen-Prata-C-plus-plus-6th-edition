#ifndef _10_7_H_
#define _10_7_H_

class Plorg
{
    private:
        char fullname[19];
        int CI;     //  Сontentment index CI - индекс удовлетворенности
    public:
        Plorg();
        Plorg(const char * fn, int ci = 50);
        ~Plorg();
        void new_CI(int n);
        void show() const;
};

#endif
