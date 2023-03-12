#include <iostream>
#include <algorithm>
#include <set>

int reduce(long ar[], int n);

int main()
{
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
    return 0;
}

int reduce(long ar[], int n)
{
    int num_amount = 0;
    std::set<long> temp(ar, ar + n);         //сортировка и удаление повторных значений
    std::set<long>::iterator int_iter;
    for(int_iter = temp.begin(); int_iter != temp.end(); int_iter++)
    {
        std::cout << *int_iter << " ";      //выводит значения массива
        num_amount++;                       //cчитаем количестов элементов
    }
    return num_amount;
}
