//usealgo.cpp -- использование нескольких элементов STL
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;
char toLower(char ch) { return tolower(ch);}
string & ToLower(string & st);
void display(const string & s);

int main()
{
    vector<string> words;
    cout << "enetr words(enter quit to quit):\n";
    string input;
    while(cin >> input && input != "quit")
    {
        words.push_back(input);
    }
    cout << "You entered the following words:\n";   //отображение введеных слов
    for_each(words.begin(), words.end(), display);
    cout << endl;
    
    //помещение слов в набор с преобразованием букв в строчные
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator< set<string> > (wordset, wordset.begin()), ToLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;
    
    //помещение и частоты его помещения в карту
    map<string, int> wordmap;
    set<string>::iterator si;
    for(si = wordset.begin(); si != wordset.end(); si++)
    {
        wordmap[*si] = count(words.begin(), words.end(), *si);
    }
    
    //отображение содержимого карты
    cout << "\nWord frequency:\n";
    for(si = wordset.begin(); si != wordset.end(); si++)
    {
        cout << *si << ": " << wordmap[*si] << endl;
    }
    return 0;
}

string & ToLower(string & st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string & s)
{
    cout << s << " ";
}
