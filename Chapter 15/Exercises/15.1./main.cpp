//use_tv.cpp -- использование классов Tv, Remote
#include <iostream>
#include "TV.h"
//#include "TV.cpp"

int main()
{
    using std::cout;
    
    Tv s42;
    Remote grey;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings(grey);
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\"TV:\n";
    s42.settings(grey);
    
    grey.set_chan(s42,10);
    grey.set_remote();
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    
    s42.settings(grey);
    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_remote();
    grey.set_chan(s58,28);
    cout << "\n58\" setings:\n";
    s58.settings(grey);
    return 0;
}
