#include <iostream>
using namespace std;
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo(student pstudent[], int a);
void display1(student st);
void display2(const student * pstudent);
void display3(const student pstudent[], int a);
int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];  //динамическая структура
    int entered = getinfo(ptr_stu, class_size);
    for(int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done!\n";
    return 0;
}
int getinfo(student pstudent[], int a)
{
    int count = 0;
    for(int i = 0; i < a; i++)
    {
        cout << "Enter the name of the student:";
        cin.get(pstudent[i].fullname, SLEN);
        if(!cin)
            {
                cin.clear();
                while(cin.get() != '\n')
                    continue;
                cout << "Bad input. Input process terminated.\n";
                break;
            }
        cin.get();
        cout << "What's his hobby? ";
        cin.get(pstudent[i].hobby, SLEN);
        cin.get();
        cout << "What's his oop level(from 1 - 5):";
        cin >> pstudent[i].ooplevel;
        cin.get();
        cout << endl;;
        count++;
    }
    return count;
}
void display1(student st)
{
    cout << "==================\n";
    cout << "Function\" display1 \".\n";
    cout << "Name: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "OOP level: " << st.ooplevel << endl;
}
void display2(const student * pstudent)
{
    cout << "==================\n";
    cout << "Function\" display2 \".\n";
    cout << "Name: " << pstudent -> fullname << endl;
    cout << "Hobby: " << pstudent -> hobby << endl;
    cout << "OOP level: " << pstudent -> ooplevel << endl; 
}
void display3(const student pstudent[], int a)
{
    cout << "==================\n";
    cout << "Function\" display3 \".\n";
    for(int i = 0; i < a; i++)
    {
        cout << "Name: " << pstudent[i].fullname << endl;
        cout << "Hobby: " << pstudent[i].hobby << endl;
        cout << "OOP level: " << pstudent[i].ooplevel << endl; 
        cout <<  endl;
    }
}
