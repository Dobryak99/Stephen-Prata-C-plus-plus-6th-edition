//smrtptrs.cpp -- использование трех видов интелекутальных указателей
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s) { std::cout << "Object created.\n";}
    ~Report() {std::cout << "Object deleted.\n";}
    void comments() const { std::cout <<str << "\n";}
};

int main()
{
    {
        //std::auto_ptr<Report>ps(new Report("Using auto_prt"));            //удален в С++ 17
        //ps -> comment()
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps ->comments();
    }
    {
        std::shared_ptr<Report> ps(new Report("using ushared_ptr"));
        ps ->comments();
    }
    return 0;
}

