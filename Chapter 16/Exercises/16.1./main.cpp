#include <iostream>
#include <string>

bool palindrome(const std::string & st);

int main()
{
    std::cout << "Enter word <q to quit> : ";
    std::string word;
    while(std::cin >> word && word != "q")
    {
        if(palindrome(word) == true)
        {
            std::cout << word << " is palindrome!\n";
        }else{
            std::cout << word << " isn't palndrome!\n";
        }
    }
    std::cout << "Bye!\n";
    return 0;
}

bool palindrome(const std::string & st)
{
    for(int i = 0, j = st.size() - 1; i < j; i++, j--)      //цикл действует пока левосторонняя меньше правосторонней
    {
        if(st[i] != st[j])          //если левосторонняя буква не равна правосторонней 
        {
            return false;
        }
    }
    return true;

}
