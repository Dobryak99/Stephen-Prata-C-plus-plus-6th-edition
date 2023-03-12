//  hangman.cpp --использование некоторых методов работы со строками
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <vector>


using std::string;
const int NUM = 26;

std::vector<string> wordlist;
std::string word;

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    
    //-------------------------------------------------------------------------//
    std::ifstream fin;
    fin.open("words.txt");                          //открыть файл
    if(fin.is_open() == false)
    {
        std::cerr << "Can't open file. Bye!\n";
        exit(EXIT_FAILURE);
    }

    while(fin >> word)                              //вводим данные из файла 
    {
        wordlist.push_back(word);                   //вставляем в конец вектора
    }
    //-------------------------------------------------------------------------//

    std::srand(std::time(0));
    
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while(play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int quesses = 6;
        cout << "Guess my secret word. It has " << length << " letters, and you guess\n"
        << "one letter at a time. You get " << quesses << " wrong answers.\n";
        cout << "Your word: " << attempt << endl;
        while(quesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if(badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
            {
                cout << "You already quessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == string::npos)
            {
                cout << "Oh, bad quess!\n";
                --quesses;
                badchars += letter;
            }else{
                cout << "Good guess!\n";
                attempt[loc] = letter;
                //проверить, не появляется ли буква еще раз
                loc = target.find(letter, loc + 1);
                while(loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if(attempt != target)
            {
                if(badchars.length() > 0)
                {
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << quesses << " bad quesse left.\n";
            }
        }
        if(quesses > 0)
        {
            cout << "That's right.\n";
        }else{
            cout << "Sorry, the word is " << target << ".\n";
        }
        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }
    cout << "Bye!\n";
    return 0;
}
