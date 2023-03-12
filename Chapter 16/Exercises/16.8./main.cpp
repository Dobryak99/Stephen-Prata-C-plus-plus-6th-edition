#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <set>

int main()
{
    std::list<std::string> M_list;
    std::list<std::string> P_list;
    std::list<std::string>::iterator l_iter;
    std::cout << "Which list would you like to use, M(Matt) or P(Patt) <q to quit>: ";
    char choice;
    int people_count;
    std::string name;
    while(std::cin >> choice && choice != 'q')
    {
        if(M_list.size() > 0 && P_list.size() > 0)              //если списки не пустые(в первый раз не вызывается, т.к. списки еще пустые)
        {
            std::cout << "Would you like to merge both lists? <y/n>: ";
            char ch_merge;
            std::cin >> ch_merge;
            if(ch_merge == 'y')
            {
                std::list<std::string> MergedList;
                //поочередное присваивание двух списков одному общему
                MergedList.merge(M_list);
                MergedList.merge(P_list);
                std::set<std::string> t_merge(MergedList.begin(), MergedList.end());        //соритровка и удаление повторяющихся
                MergedList.assign(t_merge.begin(), t_merge.end());
                std::cout << "Merged List:\n";
                for(l_iter = MergedList.begin(); l_iter != MergedList.end(); l_iter++)
                {
                    std::cout << (*l_iter) << std::endl;
                }
                std::cout << "Now, You will be redirected to chosen List.\n";
            }else{
                std::cout << "OK, You will be redirected to chosen List.\n";
            }
        }
        //если в switch будут объявляться переменные (Новые) то ОБЯЗАТЕЛЬНО добавляем {}
        switch(choice)
        {
            case 'M':
            case 'm':   {
                            std::cout << "How many people would you like to add? ";
                            std::cin >> people_count;                                       //вводим количество людей
                            if(people_count <= 0)
                            {
                                std::cout << "Number of people can't be negative. Returning back to main menu.\n";
                                break;
                            }
                            while(std::cin.get() != '\n')
                            {
                                continue;
                            }
                            for(int i = 0; i < people_count; i++)
                            {
                                std::cout << "Enter the name who you would like to add: ";
                                std::getline(std::cin,name);                                //вводим имена
                                M_list.push_back(name);                                     //добавляем имя в список
                            }
                            std::set<std::string> tempM(M_list.begin(), M_list.end());       //сориторвка и удаление повторяющихся элементов
                            M_list.assign(tempM.begin(), tempM.end());                        //копирование обратно в объект list

                            std::cout << "Here's Matt's list:\n";
                            
                            for(l_iter = M_list.begin(); l_iter != M_list.end(); l_iter++)
                            {
                                std::cout << (*l_iter) << std::endl;
                            }

                            
                            //второй вариант вывода
                            //copy(M_list.begin(), M_list.end(), std::ostream_iterator(std::cout, " "));
                            break;
                            }

            case 'P':
            case 'p':   {
                            std::cout << "How many people would you like to add? ";
                            std::cin >> people_count;                                       //вводим количество людей
                            if(people_count <= 0)
                            {
                                std::cout << "Number of people can't be negative. Returning back to main menu.\n";
                                break;
                            }
                            while(std::cin.get() != '\n')
                            {
                                continue;
                            }
                            for(int i = 0; i < people_count; i++)
                            {
                                std::cout << "Enter the name who you would like to add: ";
                                std::getline(std::cin,name);                                //вводим имена
                                P_list.push_back(name);                                     //добавляем имя в список
                            }
                            std::set<std::string> temp(P_list.begin(), P_list.end());       //сориторвка и удаление повторяющихся элементов
                            P_list.assign(temp.begin(), temp.end());                        //копирование обратно в объект list

                            std::cout << "Here's Patt's list:\n";
                            for(l_iter = P_list.begin(); l_iter != P_list.end(); l_iter++)
                            {
                                std::cout << (*l_iter) << std::endl;
                            }
                            //второй вариант вывода
                            //copy(P_list.begin(), P_list.end(), std::ostream_iterator(std::cout, " "));
                            break;
                        }

            default:    std::cout << "Wrong input. Try again.\n";
                        break;
        }
        std::cout << "Which list would you like to use, M(Matt) or P(Patt) <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}
