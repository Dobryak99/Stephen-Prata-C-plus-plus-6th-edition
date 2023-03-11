//fow1.cpp --  shared_ptr
#include <iostream>
#include <memory>
#include <string>

int main()
{
    using namespace std;
    
    shared_ptr<string> films[5] =
    {
        shared_ptr<string> (new string("Fowl Balls")),
        shared_ptr<string> (new string("Duck Walks")),
        shared_ptr<string> (new string("Chicken runs")),
        shared_ptr<string> (new string("Turkey errors")),
        shared_ptr<string> (new string("Goose eggs"))
    };
    
    shared_ptr<string> pwin;
    
    pwin = films[2];
    
    cout << "the nominees for best avian basebal film are\n";
    for(int i = 0; i < 5; i++)
    {
        cout << *films[i] << endl;
    }
    cout << "The winner is " << *pwin << endl;
    cin.get();
    return 0;
}
