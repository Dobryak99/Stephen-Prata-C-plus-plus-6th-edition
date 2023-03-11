//strgst1.cpp -- применение STL к строке
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    using namespace std;
    string letters;
    cout << "Enter the letter qrouping (q to qut): ";
    while(cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        while(next_permutation(letters.begin(), letters.end()))
        {
            cout << letters << endl;
        }
        cout << "Enter next sequence (q to quit): ";
    }
    cout << "Done!\n";
    return 0;
}
