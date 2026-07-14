//StudybarCommentBegin
#include <iostream>
using namespace std;

class Employee {
protected:
    int salary;
public:
    Employee(int s) : salary(s) {}
    virtual int CalculateSalary() = 0;
};
//StudybarCommentEnd
class FullTimeEmployee: public Employee{
    public:
        FullTimeEmployee(int s): Employee(s){}
        int CalculateSalary(){
            return salary;
        }
};
class PartTimeEmployee: public Employee{
    int wage,hour;
    public:
        PartTimeEmployee(int wage=0, int hour=0):wage(wage), hour(hour), Employee(0){}
        int CalculateSalary(){
            return wage*hour;
        }
};
class Intern: public Employee{
    public:
        Intern():Employee(0){}
        int CalculateSalary(){
            return 2000;
        }
};
//StudybarCommentBegin
int main() {
    int hours;
    cin >> hours;

    FullTimeEmployee fte(5000);
    PartTimeEmployee pte(50, hours);
    Intern intern;

    cout << "FullTimeEmployee: " << fte.CalculateSalary() << endl;
    cout << "PartTimeEmployee: " << pte.CalculateSalary() << endl;
    cout << "Intern: " << intern.CalculateSalary() << endl;

    return 0;
}

//StudybarCommentEnd