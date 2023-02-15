// strctptr.cpp -- функции с аргументами-указателями на структуры
#include <iostream>
#include <cmath>

//объявление структур

struct polar
{
    double distance;
    double angle;
};
struct rect
{
    double x;
    double y;
};

//прототипы
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar(const polar * pda);
int main()
{
    using namespace std;
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while(cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);   //передача адресов
        show_polar(&pplace);
        cout << "Next two numbers(q to quit): ";
    }
    cout << "Done!\n";
    return 0;
}

//отображение полярных координат с преобразованием радиан в градусы
void show_polar(const polar * pda)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    cout << "Distance = " << pda -> distance << ", angle = " << pda -> angle * Rad_to_deg << " degrees.\n";
}

// преобразование прямоугольных координат в полярные
void rect_to_polar(const rect * pxy, polar * pda)
{
    using namespace std;
    pda -> distance = sqrt(pxy -> x * pxy -> x + pxy -> y * pxy -> y);
    pda -> angle = atan2(pxy -> y, pxy -> x);
}
