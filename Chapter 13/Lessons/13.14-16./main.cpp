//usedma.cpp -- наслдеование, друзья и динмаическое выделение памяти
#include "dma.hpp"
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    
    baseDMA shirt("Portabelly" ,8);
    lacksDMA balloon("Red", "Blombo", 4);
    hasDMA map("Mercator", "Buffalo keys", 5);
    
    cout << "Displaying baseDMA objects:\n" << shirt << endl;
    
    cout << "Displaying lacksDMA objects:\n" << balloon << endl;
    
    cout << "Displaying hasDMA objects:\n" << map << endl;
    
    lacksDMA balloon2(balloon);                 //копирование balloon в balloon2
    cout << "result of lacksDMA copy:\n" << balloon2 << endl;
    
    hasDMA map2;
    map2 = map;
    cout << "result hasDMA assignment:\n" << map2 << endl;
    return 0;
}
