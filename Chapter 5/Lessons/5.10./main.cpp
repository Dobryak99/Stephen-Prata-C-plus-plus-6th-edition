// equal.cpp -- равенство или присваивание
#include <iostream>
int main()
{
    using namespace std;
    int quizscores[10] =
    {20, 20, 20, 20 , 20, 19, 20, 18, 20, 20};
    cout << "Doing it right:\n";   //правильно
    int i;
    for (i = 0 ; quizscores[i] == 20; i++)
        cout << "quiz " << i << " is 20\n";
    //предупреждение:  возможно лучше прочитать об этой программе,
    //чем в действительности запускать ее.
    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[i] = 20; i++)
        cout << "quiz " << i << " is 20\n";
    return 0;
}
