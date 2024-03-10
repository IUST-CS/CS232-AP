// Program to demonstrate the class Money. (This is an improved version of
// the class Money that we gave in Display 11.3 and rewrote in Display 11.4.)
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

// Class for amounts of money in U.S. currency.
class Money
{
public:
    friend Money operator+(const Money &amount1, const Money &amount2);
    // Precondition: amount1 and amount2 have been given values.
    // Returns the sum of the values of amount1 and amount2.
    friend bool operator==(const Money &amount1, const Money &amount2);
    // Precondition: amount1 and amount2 have been given values.
    // Returns true if amount1 and amount2 have the same value;
    // otherwise, returns false.
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double getValue() const;
    void input(istream &ins);
    void output(ostream &outs);

private:
    long allCents;
};
int main()
{
    Money cost(1, 50), tax(0, 15), total;
    total = cost + tax;
    cout << "cost = ";
    cost.output(cout);
    cout << endl;
    cout << "tax = ";
    tax.output(cout);
    cout << endl;
    cout << "total bill = ";
    total.output(cout);
    cout << endl;
    if (cost == tax)
        cout << "Move to another state.\n";
    else
        cout << "Things seem normal.\n";
    return 0;
}

int digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

Money operator+(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents == amount2.allCents);
}

void Money::output(ostream& outs)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    
    if (cents < 10)
        outs << '0';
    outs << cents;
}


Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    allCents = dollars * 100 + cents;
}

Money::Money(): allCents(0){}

Money::Money(long dollars): allCents(dollars*100){}
void Money::input(istream& ins){
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> oneChar;
    if (oneChar == ' '){
        negative = true;
        ins >> oneChar; //read $
    }else
        negative = false;
    ins >> dollars >> decimalPoint >> digit1 >> digit2;
    if ( oneChar != '$' || decimalPoint != '.' ||
        !isdigit(digit1) || !isdigit(digit2)){
        cout << "Error illegal form from money input\n";
        exit(1);
    }

    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
    allCents = dollars * 100 + cents;
    if(negative)
        allCents = - allCents;
}