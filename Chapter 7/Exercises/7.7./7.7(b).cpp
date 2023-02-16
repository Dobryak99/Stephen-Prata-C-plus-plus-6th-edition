#include <iostream>
const int  Max = 5;

double *fill_array(double ar[], double * end)
{
    using namespace std;
    double temp;
    int i = 1;
    double * pi;
    for(pi = ar; pi != end; i++, pi++)
    {
        cout << "Enter value #" << i << ": ";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input.Input process terminated!!!";
            break;
        }
        else if(temp < 0)
        {
            break;
        }
        *pi = temp;
    }
    return pi;
}

void show_array(double ar[], double * end)
{
    using namespace std;
    int i = 1;
    double *pt;
    for(pt = ar ;pt != end; pt++, i++)
    {
        cout << "Property #" << i << ": $";
        cout << *pt << endl;
    }
}

void revalue(double r, double ar[], double *  end)
{
    double *pt = ar;
    for(int i = 1 ; pt != end; pt++, i++)
    {
        *pt *= r;
    }
}

int main()
{
    using namespace std;
    double properties[Max];
    double * end = fill_array(properties, properties + Max);
    show_array(properties, end);
    if((end - properties) > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while(!(cin >> factor))
            {
            cin.clear();
                while(cin.get() != '\n')
                {   
                    continue;
                }
            cout << "Bad input. Please, enter the number:";
            }
    revalue(factor,properties, end);
    show_array(properties, end);
    }
    cout << "Done!\n";
    cin.get();
    cin.get();
    return 0;
}
