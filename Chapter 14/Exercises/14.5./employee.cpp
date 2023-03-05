#include  "employee.h"

//friends
std::ostream & operator<<(std::ostream & os, const abstr_emp & emp)
{
    os << "Full name: " << emp.fname << ", " << emp.lname << "\n";
    return os;
    
}


//class abstr_emp
abstr_emp::~abstr_emp() 
{

}

void abstr_emp::ShowAll() const
{
    std::cout << "First name: " << fname << "\n";
    std::cout << "Last name: " << lname << "\n";
    std::cout << "Job: " << job << "\n";
}

void abstr_emp::SetAll()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

//class employee
void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

//class manager
void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << InChargeOf() << std:: endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    int temp;
    std::cout << "Enter how many people in charge: ";
    std::cin >> temp;
    InChargeOf() = temp; 
}

manager::manager(const manager & m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

//class fink
void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << ReportsTo() << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter full name to whom reports: ";
    std::string temp;
    std::getline(std::cin, temp);
    ReportsTo() = temp;
}

fink::fink(const fink & f) : abstr_emp(f)
{
    reportsto = f.reportsto;
}

//class highfink
highfink::highfink(const highfink & hf) : abstr_emp(hf), manager(hf), fink(hf)
{

}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "In charge of " << manager::InChargeOf() << " people.\n";
    std::cout << "Reports to " << fink::ReportsTo() << "\n";
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter full name to whom reports: ";
    std::string tempstr;
    std::getline(std::cin, tempstr);
    fink::ReportsTo() = tempstr;
    int temp;
    std::cout << "Enter how many people in charge: ";
    std::cin >> temp;
    manager::InChargeOf() = temp; 
}
