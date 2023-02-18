#include <iostream>
#include<cstring>
using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & a, const char * ar);

void show(const stringy & a, int n = 1);

void show(const char * ar, int a = 1);

void Del(const stringy & a);


int main()
{
    stringy beany;
    char testing [] = "Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done!");
    Del(beany);
    return 0;
}

void set(stringy & a, const char * ar)
{
    a.ct = strlen(ar);
    a.str = new char(a.ct + 1);
    strcpy(a.str, ar);
}

void show(const stringy & a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a.str << endl;
    }
}

void show(const char * ar, int a)
{
    for(int i = 0; i < a; i++)
    {
        cout << ar << endl;
    }
}

void Del(const stringy & a)
{
    delete [] a.str;
}
