#include "tabtenn2.hpp"

#include <iostream>

int main()
{
    using std::cout;
    TableTennisPlayer player1("Tara", "Boomdea" , false);
    RatedPlayer rplayer1(1140,"Mallory", "Duck" , true);
    rplayer1.Name();                        //объект производного класса использует метод базового класса
    if(rplayer1.HasTable())
    {
        cout << ": has a table.\n";
    }else{
        cout << ": hasn't a table.\n";
    }
    player1.Name();                         //объект базового класса использует метод базового класса
    if(player1.HasTable())
    {
        cout << ": has a table.\n";
    }else{
        cout << ": hasn't a table.\n";
    }
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << std::endl;
    
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << std::endl;
    return 0;
}
