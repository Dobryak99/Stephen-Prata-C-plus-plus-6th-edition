#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string word;
    int vowels = 0;
    int consonants = 0;
    int other = 0;
    cout << "Enter words(\"q\" to quit):";
    while (cin >> word && word != "q")
    {
        if(isalpha(word[0]))   // сравнение первой буквы каждого слова
        {
            if(word[0] == 'a' || word[0] == 'A')
                vowels++;
            else if(word[0] == 'e' || word[0] == 'E')
                vowels++;
            else if(word[0] == 'i' || word[0] == 'I')
                vowels++;
            else if(word[0] == 'y' || word[0] == 'Y')
                vowels++;
            else if(word[0] == 'o' || word[0] == 'O')
                vowels++;
            else if(word[0] == 'u' || word[0] == 'U')
                vowels++;
            else
                consonants++;
        }
        else
        {
            other++;
        }
    }
    cout << vowels << " begins with vowels.\n";
    cout << consonants << " begins with consonants.\n";
    cout << other << " others.\n";
    return 0;
}
/* Второй возможный вариант
 
 #include <iostream>
 #include <string>
 #include <cctype>
 using namespace std;
 int main()
 {
 string word;
 int vowels = 0;
 int consonants = 0;
 int other = 0;
 cout << "Enter words(\"q\" to quit):";
 while (cin >> word && word != "q")
 {
 if(isalpha(word[0]))   // сравнение первой буквы каждого слова
 {
 switch(word[0])
 {
 case 'a':
 case 'A':
 case 'E':
 case 'e':
 case 'i':
 case 'I':
 case 'o':
 case 'O':
 case 'u':
 case 'U':
 case 'Y':
 case 'y': vowels++;
 break;
 default: consonants++;
 }
 }
 else
 {
 other++;
 }
 }
 cout << vowels << " begins with vowels.\n";
 cout << consonants << " begins with consonants.\n";
 cout << other << " others.\n";
 return 0;
 }
 
 */
