#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <list>

void menu();

int main()
{
    std::ofstream fout;
    std::ifstream fin;
    std::list<std::string> M_list;
    std::list<std::string> P_list;
    std::list<std::string> Both_lists;
    //std::list<std::string>::iterator l_iter;
    menu();
    int choice;
    char characters;
    std::string name;
    while(std::cin >> choice && choice != 4)
    {
        switch(choice)
        {
            case 1: fin.open("mat.dat");
                    if(!fin.is_open())
                    {
                        std::cerr << "Can't open file.\n";
                        exit(EXIT_FAILURE);
                    }
                    while(std::getline(fin, name))
                    {
                        M_list.push_back(name);
                    }
                    M_list.sort();
                    M_list.unique();
                    std::cout << "Here's Mat's list:\n";
                    for(auto l_iter = M_list.begin(); l_iter != M_list.end(); l_iter++)
                    {
                        std::cout << (*l_iter) << std::endl;
                    }
                    fin.close();
                    menu();
                    break;
            case 2: fin.open("pat.dat");
                    if(!fin.is_open())
                    {
                        std::cerr << "Can't open file.\n";
                        exit(EXIT_FAILURE);
                    }
                    while(std::getline(fin, name))
                    {
                        P_list.push_back(name);
                    }
                    P_list.sort();
                    P_list.unique();
                    std::cout << "Here's Pat's list:\n";
                    for(auto l_iter = P_list.begin(); l_iter != P_list.end(); l_iter++)
                    {
                        std::cout << (*l_iter) << std::endl;
                    }
                    fin.close();
                    menu();
                    break;
            case 3: fout.open("matnpat.dat");
                    if(!fout.is_open())
                    {
                        std::cerr << "Can't open file.\n";
                        exit(EXIT_FAILURE);
                    }
                    Both_lists.merge(M_list);
                    Both_lists.merge(P_list);
                    Both_lists.sort();
                    Both_lists.unique();
                    if(Both_lists.size() == 0)
                    {
                        std::cout << "No data in files to merge. Try again later!\n";
                        menu();
                        break;
                    }
                    std::cout << "Here's Merged list:\n";
                    //вывод на экран
                    for(auto l_iter = Both_lists.begin(); l_iter != Both_lists.end(); l_iter++)
                    {
                        std::cout << (*l_iter) << std::endl;
                    }
                    //вывод в файл
                    for(auto l_iter = Both_lists.begin(); l_iter != Both_lists.end(); l_iter++)
                    {
                        fout << (*l_iter) << std::endl;
                    }
                    fout.close();
                    menu();
                    break;
            default:    std::cout << "Wrong input. Try again\n";
                        menu();
                        break;
        }
        
    }
    std::cout << "Bye!\n";
    return 0;
}

void menu()
{
    std::cout << "1) Show Mat's list\t2) Show Pat's list\n3) Merge both lists\t4)Exit\nYour choice: ";
}
