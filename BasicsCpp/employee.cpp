#include <string>
#include <iostream>
using namespace std;

class Employee {
    private:
        string empId;
        string name;
        double basicSalary;
        
    public:
        Employee(string empId, string name, double basicSalary) :
            empId(empId),
            name(name),
            basicSalary(basicSalary) 
        {}

        void display(){
            cout << "Employee details\n";
            cout << "Employee Id : " << empId << endl;
            cout << "Employee name : " << name << endl;
            cout << "Employee basic salary : " << basicSalary << endl;
        }
        virtual double calculateSalary() const {
            return this->basicSalary;
        }
};

class Manager : public Employee {
    private:
        double performanceBonus;
        double teamSize;
    public:
        Manager(string empId, string name, double basicSalary, double performanceBonus, double teamSize) : 
            Employee(empId, name, basicSalary),
            performanceBonus(performanceBonus),
            teamSize(teamSize)
        {}

        double calculateSalary() const override {
            return Employee::calculateSalary() + this->performanceBonus;
        }
};
class Developer : public Employee {
    private:
        double overtimeHours;
        double hourlyRate;
    public:
        Developer(string empId, string name, double basicSalary, double overtimehrs, double rate) : 
            Employee(empId, name, basicSalary),
            overtimeHours(overtimehrs),
            hourlyRate(rate)
        {}

        double calculateSalary() const override {
            return Employee::calculateSalary() + (this->hourlyRate * this->overtimeHours);
        }
};