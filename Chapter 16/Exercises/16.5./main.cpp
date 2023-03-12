#include <iostream>
#include <algorithm>
#include <set>

template <class T>
int reduce(T ar[], int n);

int main()
{
    //------------------------------------------------------------//
    std::cout << "Testing \"long\":\n";
    long values[] = {2,4,2,3,5,7,8,4,5,10,6,2};
    int count = 0;
    std::cout << "Array before sort:\n";
    for(int i = 0; i < 12; i++)
    {
        std::cout << values[i] << " ";
        count++;
    }
    std::cout << "Count: " << count << std::endl;
    std::cout << "Array after sort:\n";
    int new_count = reduce(values, 12);
    std::cout << "Count: " << new_count << std::endl;
    //------------------------------------------------------------//
    
    std::cout << "Testing \"string\":\n";
    std::string words[] = {"hello", "friend", "socks", "ball", "hello", "pen", "glasses", "pen", "lamp", "cookies", "hello" ,"apple"};
    count = 0;
    new_count = 0;
    std::cout << "Array before sort:\n";
    for(int i = 0; i < 12; i++)
    {
        std::cout << words[i] << " ";
        count++;
    }
    std::cout << "Count: " << count << std::endl;
    std::cout << "Array after sort:\n";
    new_count = reduce(words, 12);
    std::cout << "Count: " << new_count << std::endl;
    return 0;
}
template <class T>
int reduce(T ar[], int n)
{
    int num_amount = 0;
    
    std::set<T> temp(ar, ar + n);         //сортировка и удаление повторных значений
    typename std::set<T>::iterator T_iter;
    for(T_iter = temp.begin(); T_iter != temp.end(); T_iter++)
    {
        std::cout << *T_iter << " ";      //выводит значения массива
        num_amount++;                       //cчитаем количестов элементов
    }
    return num_amount;
}
