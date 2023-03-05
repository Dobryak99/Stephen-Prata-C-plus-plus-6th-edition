#include "person.h"

Person::~Person() 
{

}

void Person::Data() const
{
    std::cout << "First name: " << fname << "\n";
    std::cout << "Last name: " << lname << "\n";
}

void Person::Get()
{
    std::getline(std::cin, fname);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);
}

void Person::Show() const
{
    Data();
}

void Gunslinger::Set()
{
    std::cout << "Enter first name: ";
    Person::Get();
    Gunslinger::Get();
}

void Gunslinger::Data() const
{
    std::cout << "Ready time: " << Draw() << "\n";
    std::cout << "Gun's cuts: " << cuts << "\n";
}

void Gunslinger::Get()
{
    std::cout << "Enter ready time: ";
    std::cin >> ready_time;
    std::cout << "Enter gun's cuts: ";
    std::cin >> cuts;
    while(std::cin.get() != '\n')
    {
        continue;
    }
}

void Gunslinger::Show() const
{
    std::cout << "Category: Gunslinger.\n";
    Person::Data();
    Data();
}

void PokerPlayer::Set()
{
    std::cout << "Enter first name: ";
    Person::Get();
    PokerPlayer::Get();
}

int PokerPlayer::Draw()
{
    int temp;
    srand(time(0));
    temp = rand() % 52 + 1;
    return temp;
}

void PokerPlayer::Data() const
{
    std::cout << "Value of card: " << card << "\n";
}

void PokerPlayer::Get()
{
    card = Draw();
}

void PokerPlayer::Show() const
{
    std::cout << "Category: PokerPlayer.\n";
    Person::Data();
    Data();
}

void BadDude::Data() const
{
    Gunslinger::Data();
    PokerPlayer::Data();
}

int BadDude::Cdraw()
{
    return PokerPlayer::Draw();
}

double BadDude::Gdraw()
{
    return Gunslinger::Draw();
}

void BadDude::Get()
{
    Gunslinger::Get();
    PokerPlayer::Get();
}

void BadDude::Set()
{
    std::cout << "Enter first name: ";
    Person::Get();
    Get();
}

void BadDude::Show() const
{
    std::cout << "Category: BadDude.\n";
    Person::Data();
    Data();
}
