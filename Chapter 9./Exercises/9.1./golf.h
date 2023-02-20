//golf.h
#ifndef _GOLF_H_
#define _GOLF_H_
const int Len = 40;

struct golf
{
    char fullname[40];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

int setgolf(golf & g);

void handicap(golf & g, int hc);

void showgolf(const golf & a);
#endif 
