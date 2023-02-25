#ifndef _EX10_3_H_
#define _EX10_3_H_

class Golf
{
    private:
        static const int Len = 40;
        char fullname[Len];
        int handicap;
    public:
        Golf();
        Golf(const char * fn, int hc);
        ~Golf();
        int setGolf();
        void Handicap(int n);
        void showGolf() const;
};
#endif 
