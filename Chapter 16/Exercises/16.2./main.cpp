#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool palindrome(std::string & st);

int main()
{
    std::cout << "Enter word <q to quit> : ";
    std::string word;
    while(std::getline(std::cin, word) && word != "q")
    {
        if(palindrome(word) == true)
        {
            std::cout << word << " is a palindrome!\n";
        }else{
            std::cout << word << " isn't a palindrome!\n";
        }
    }
    std::cout << "Bye!\n";
    return 0;
}

bool palindrome(std::string & st)
{
    
    std::string temp;
    //преобразование прописных букв в строчные
    for(int i = 0; i < st.size() ; i++)
    {
        
        if(isalpha(st[i]))                              //если буква
        {
            temp.push_back(tolower(st[i]));             //вставляем в конец temp прописную букву
        }
    }


    for(int i = 0, j = temp.size() - 1 ; i <= j; i++, j--)      //цикл действует пока левосторонняя меньше правосторонней
    {
        if(temp[i] != temp[j])          //если левосторонняя буква не равна правосторонней 
        {
            return false;
        }
    }
    return true;

}
