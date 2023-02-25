#include <iostream>
#include "ex10_3.h"
//#include "ex10_3.cpp"

int main()
{
    Golf ann;
    ann.showGolf();
    Golf Bred("Bred Pit", 12);
    Bred.showGolf();
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;
    Bred.Handicap(number);
    Bred.showGolf();
    int num_player = 0;
    std::cout << "Enter the number of players: ";
    (std::cin >> num_player).get();
    Golf *players = new Golf[num_player];
    int counter = 0;
    for(int i = 0; i < num_player; i++)
    {
        if(players[i].setGolf() > 0)
        {
            counter++;
        }else{
            break;
        }
    }
    for(int i = 0; i < counter; i++)
    {
        players[i].showGolf();
    }
    delete [] players;
    return 0;
}
