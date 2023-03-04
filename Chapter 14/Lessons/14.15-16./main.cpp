//stkoptr1.cpp -- тестирование стека указателей
#include "stackp1.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

const int Num = 10;

int main()
{
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    
    //создание пустого стека размером stacksize
    Stack<const char *> st(stacksize);
    
    // Входной ящик
    const char * in[Num] = {
        "1: Hank Gilgamesh", "2: Kiki Ishtar",
        "3: Betty Rocker", "4: Ian Flagranti",
        "5: Wolfgang Kibble", "6: Portia Koop",
        "7: Joy Almondo", "8: Xaverie Paprika",
        "9: Juan Moore", "10: Masha Mache",
    };
    
    //Выходной ящик
    
    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    
    while(processed < Num)
    {
        if(st.isempty())
        {
            st.push(in[nextin++]);
        }else if(st.isfull())
        {
            st.pop(out[processed++]);
        }else if(std::rand() % 2 && nextin < Num)           //шансы 50 на 50
        {
            st.push(in[nextin++]);
        }else{
            st.pop(out[processed++]);
        }
    }
    
    for(int i = 0; i < Num; i++)
    {
        std::cout << out[i] << std::endl;
    }
    std::cout << "Goodbye!\n";
    return 0;
}
