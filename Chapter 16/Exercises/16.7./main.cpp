#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>


std::vector<int> Lotto(int all_num, int chosen_num);
int Random(int num);

int main()
{
    srand(time(NULL));
    std::cout << "Game LOTTO\nThere are 51 numbers total. Randomly picked 6 numbers.\n!!!GOOD LUCK!!!\n";
    std::vector<int> winners;
    winners = Lotto(51,6);
    std::cout << "Winner combination: ";
    std::vector<int>::iterator vwins;
    for(vwins = winners.begin(); vwins != winners.end(); vwins++)
    {
        std::cout << *vwins << " ";
    }    
    std::cout << std::endl;
    return 0;
}

std::vector<int> Lotto(int all_num, int chosen_num)
{
    int temp_arr[all_num];
    for(int i = 0; i < all_num; i++)
    {
        temp_arr[i] = Random(all_num);
    }
    std::vector<int> temp(temp_arr, temp_arr + all_num);         //вектор из all_num  элементов int с рандомным значением
    std::set<int> temp_set(temp.begin(), temp.end());       //сортировка и удалени повторных элементов
    temp.assign(temp_set.begin(), temp_set.end());          //копирование обратно элементов temp

    std::vector<int> result(temp.begin(), temp.begin() + chosen_num);           //взяли первые chosen_num значения
    return result;
}

int Random(int num)
{
    int rnum = rand() % num + 1;
    return rnum;
}
