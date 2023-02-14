#include <iostream>
using namespace std;
void menu();
void carnivore();
void tree();
void pianist();
void game();
int main()
{
    char choice;
    menu();
    while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && cin >> choice)
    {
        switch(choice)
        {
            case 'a':
            {
                carnivore();
                break;
            }
            case 'b':
            {
                tree();
                break;
            }
            case 'c':
            {
                pianist();
                break;
            }
            case 'd':
            {
                game();
                break;
            }
            default:
            {
                cout << "That's not a choice. Repeat please.\n";
                menu();
            }
        }
    }
    cout << "Done!\n";
    return 0;
}
void menu()
{
    cout << "Please enter one of the following choices(type \'@\' to terminate):\n"
    << "a) carnivore    b) tree\n"
    << "c) pianist  d)game\nYour choice:";
};
void carnivore()
{
    cout << "The tiger, AHRRRR!!!!\n";
}
void tree()
{
    cout << "You have planted NFT tree. congratulation!!\n";
};
void pianist()
{
    cout << "One of the famous pianists is Ludwig van Beethoven.\n";
};
void game()
{
    cout << "The most famous game in the world is Minecraft.\n";
};
