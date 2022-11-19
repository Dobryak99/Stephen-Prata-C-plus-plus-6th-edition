#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string month[12] = { "january","february","march","april","may","june","july","august","september","october","november","december" };
    int sales[3][12];
    int i,j,sold_in_total=0,summa = 0;
    for (j = 0; j < 3; j++)
    {
        summa = 0;
        for (i = 0; i < 12; i++)
        {
            cout << month[i] << " sold:\t";
            cin >> sales[j][i];
            summa += sales[j][i];
        }
        cout << " sold in a year : " << summa << endl;
        sold_in_total += summa;
    }
    cout << " Sold in total : " << sold_in_total;
    return 0;
}
