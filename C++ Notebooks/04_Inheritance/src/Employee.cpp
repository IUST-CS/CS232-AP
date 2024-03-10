#include <iostream>
using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    string ssn;
    double netPay;
public:
    Employee() : name("No name"), ssn("No number"), netPay(0) {}
    Employee(string theName, string theSSN) : name(theName), ssn(theSSN), netPay(0) {}
    void setName(string newName) { name = newName; }
    void setSSN(string newSSN) { ssn = newSSN; }
    void setNetPay(double newNetPay) { netPay = newNetPay; }
    string getName() const { return name; }
    string getSSN() const { return ssn; }
    double getNetPay() const { return netPay; }
    virtual void printCheck() const = 0; // Pure virtual function
};

// Derived class HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double wageRate;
    double hours;
public:
    HourlyEmployee() : Employee(), wageRate(0), hours(0) {}
    HourlyEmployee(string theName, string theSSN, double theWageRate, double theHours)
        : Employee(theName, theSSN), wageRate(theWageRate), hours(theHours) {}
    void setRate(double newWageRate) { wageRate = newWageRate; }
    void setHours(double hoursWorked) { hours = hoursWorked; }
    double getRate() const { return wageRate; }
    double getHours() const { return hours; }
    void printCheck() const override { // Corrected to include const
        cout << "\n______________________________________\n";
        cout << "Pay to the order of " << getName() << endl;
        cout << "The sum of " << hours * wageRate << " Dollars\n"; // Modified to show calculation directly
        cout << "______________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSSN() << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
             << " Rate: " << wageRate << " Pay: " << hours * wageRate << endl; // Direct calculation
        cout << "________________________________________\n";
    }
};

// Derived class SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double salary; // weekly salary
public:
    SalariedEmployee() : Employee(), salary(0) {}
    SalariedEmployee(string theName, string theSSN, double theWeeklySalary)
        : Employee(theName, theSSN), salary(theWeeklySalary) {}
    void setSalary(double newSalary) { salary = newSalary; }
    double getSalary() const { return salary; }
    void printCheck() const override { // Corrected to include const
        cout << "\n______________________________________\n";
        cout << "Pay to the order of " << getName() << endl;
        cout << "The sum of " << salary << " Dollars\n";
        cout << "______________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSSN() << endl;
        cout << "Salaried Employee. Regular Pay: " << salary << endl;
        cout << "________________________________________\n";
    }
};

int main() {
    HourlyEmployee joe("Mighty Joe", "123-45-6789", 20.50, 40);
    cout << "Check for " << joe.getName() << " for " << joe.getHours() << " hours." << endl;
    joe.printCheck();
    cout << endl;

    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
    cout << "Check for " << boss.getName() << endl;
    boss.printCheck();
}