#include <iostream>
#include "golf.cpp"

void setgolf(golf & g, const char * name, int hc);

int setgolf(golf & g);

void handicap(golf & g, int hc);

void showgolf(const golf & a);

int main()
{
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;
    handicap(ann,number);
    showgolf(ann);
    int col_players = 0;
    std::cout << "Enter the number of players: ";
    std::cin >> col_players;
    std::cin.get();
    golf * players = new golf[col_players];
    int counter= 0;
    for(int i = 0;i < col_players; i++)
    {
        if(setgolf(players[i]) == 0)
        {
            break;
        }
        counter++;
    }
    for(int i = 0; i < counter; i++)
    {
        showgolf(players[i]);
    }
    std::cin.get();
    std::cin.get();
    delete [] players;

    return 0;
}
