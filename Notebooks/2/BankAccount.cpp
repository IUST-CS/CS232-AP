#include <iostream>
using namespace std;

class BankAccount
{
public:
    BankAccount(int dollars, int cents, double rate){
        if ((dollars < 0) || (cents < 0) || (rate < 0))
        {
            cout << "Illegal values for money or interest rate.\n";
            exit(1);
        }
        dollarsPart = dollars;
        centsPart = cents;
        interestRate = fraction(rate);
    }
    //Initializes the account balance to $dollars.cents and
    //initializes the interest rate to rate percent.
    BankAccount(int dollars, double rate){
        if ((dollars < 0) || (rate < 0))
        {
            cout << "Illegal values for money or interest rate.\n";
            exit(1);
        }
        dollarsPart = dollars;
        centsPart = 0;
        interestRate = fraction(rate);
    }
    //Initializes the account balance to $dollars.00 and
    //initializes the interest rate to rate percent.
    BankAccount( ) : dollarsPart(0), centsPart(0), interestRate(0.0)
    {
        
    }
    //Initializes the account balance to $0.00 and the
    //interest rate to 0.0%.
    void set(int dollars, int cents, double rate){
        if ((dollars < 0) || (cents < 0) || (rate < 0))
        {
            cout << "Illegal values for money or interest rate.\n";
            return;
        }
        dollarsPart = dollars;
        centsPart = cents;
        interestRate = fraction(rate);
    }
    //Postcondition: The account balance has been set to $dollars.cents;
    //The interest rate has been set to rate percent.
    void set(int dollars, double rate){
    if ((dollars < 0) || (rate < 0))
        {
        cout << "Illegal values for money or interest rate.\n";
        return;
        }
    dollarsPart = dollars;
    interestRate = fraction(rate);
    }
    //Postcondition: The account balance has been set to $dollars.00.
    //The interest rate has been set to rate percent.
    double getBalance( ){
        return (dollarsPart + 0.01 * centsPart);
    }
    //Returns the current account balance.
    double getRate( ){
        return percent(interestRate);
    }
    //Returns the current account interest rate as a percentage.
    void output(ostream& outs){
        outs.setf(ios::fixed);
        outs.setf(ios::showpoint);
        outs.precision(2);
        outs << "Account balance $" << getBalance( ) << endl;
        outs << "Interest rate "<< getRate( ) << "%" << endl;
    }
    //Precondition: If outs is a file output stream, then
    //outs has already been connected to a file.
    //Postcondition: Account balance and interest rate
    //have been written to the stream outs.
private:
    int dollarsPart;
    int centsPart;
    double interestRate;
    //Expressed as a fraction, for example, 0.057 for 5.7%
    double fraction(double percentValue){
        return (percentValue/100.0);
    }
    //Converts a percentage to a fraction. For example, fraction(50.3)
    //returns 0.503.
    double percent(double fractionValue){
        return (fractionValue * 100);
    }
    //Converts a fraction to a percentage. For example, percent(0.503)
    //returns 50.3.
};


class SavingsAccount : public BankAccount
{
    public:
    SavingsAccount(int dollars, int cents, double rate)
    {
        BankAccount(dollars, cents, rate);
    }
    //Other constructors would go here
    void deposit(int dollars, int cents)
    {
        double balance = getBalance();
        balance += dollars;
        balance += (static_cast<double>(cents) / 100);
        int newDollars = static_cast<int>(balance);
        int newCents = static_cast<int>((balance - newDollars) * 100);
        set(newDollars, newCents, getRate());
    }
    //Adds $dollars.cents to the account balance
    void withdraw(int dollars, int cents)
    {
        double balance = getBalance();
        balance -= dollars;
        balance -= (static_cast<double>(cents) / 100);
        int newDollars = static_cast<int>(balance);
        int newCents = static_cast<int>((balance - newDollars) * 100);
        set(newDollars, newCents, getRate());
    }
    //Subtracts $dollars.cents from the account balance
private:
};

int main()
{
    SavingsAccount account(100, 50, 5.5);
    account.output(cout);
    cout << endl;
    cout << "Depositing $10.25." << endl;
    account.deposit(10,25);
    account.output(cout);
    cout << endl;
    cout << "Withdrawing $11.80." << endl;
    account.withdraw(11,80);
    account.output(cout);
    cout << endl;
}