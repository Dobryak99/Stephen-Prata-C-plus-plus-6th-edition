#include "DMA.h"
//#include "DMA.cpp"
#include <iostream>

const int CLOTHES = 4;
const int LEN = 40;

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;

    DMA * p_clothes[CLOTHES];
    char temp_label[LEN];
    char temp_style[LEN];
    char temp_color[LEN];
    int temp_rating;
    char choice;
    for(int i = 0; i < CLOTHES; i++)
    {
        cout << "Enter label of the cloth: ";
        cin.getline(temp_label ,LEN);
        cout << "Enter 1 for adding rating\n"
        <<"2 for adding color\n"
        <<"3 for adding style: ";
        while(cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
        {
            cout << "Enter either 1 or 2 or 3: ";
        }
        while(cin.get() != '\n')
        {
            continue;
        }
        if(choice == '1')
        {
            cout << "Enter rating: ";
            cin >> temp_rating;
            p_clothes[i] = new baseDMA(temp_label, temp_rating);
            cin.get();
        }else if(choice == '2')
        {
            cout << "Enter color: ";
            cin.getline(temp_color, LEN);
            p_clothes[i] = new lacksDMA(temp_label, temp_color);
        }else{
            cout << "Enter style: ";
            cin.getline(temp_style, LEN);
            p_clothes[i] = new hasDMA(temp_label, temp_style);
        }
    }

    cout << endl;

    for(int i = 0; i <CLOTHES; i++)
    {
        p_clothes[i] -> View();
    }

    for(int i = 0; i < CLOTHES; i++)
    {
        delete p_clothes[i];
    }

    cout << "Done!\n";
    return 0;

}
