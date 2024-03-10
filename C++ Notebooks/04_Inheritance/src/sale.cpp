//This is the implementation file: sale.cpp
//This is the implementation for the class Sale.
//The interface for the class Sale is in
// the header file sale.h.
#include "sale.h"
#include <iostream>
#include "discountsale.h"

namespace salesavitch
{
    Sale::Sale() : price(0)
    {}

    Sale::Sale(double thePrice) : price(thePrice)
    {}

        double Sale::bill() const
        {
            return price;
        }

        double Sale::savings(const Sale& other) const
        {
            return (bill() - other.bill() );
        }

        bool operator <(const Sale& first, const Sale& second)
        {
            return (first.bill() < second.bill());
        }
        
}//salesavitch


//Demonstrates the performance of the virtual function bill.
using namespace std;
using namespace slaesavitch;

int main()
{
    Sale simple (10.00); //One item at $10.00.
    DiscountSale discount(11.00, 10); //One item at $11.00 with a 10% discount.

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision (2);

if (discount < simple)
{
    cout << "Discounted item is cheaper.\n";
    cout << "Savings is $" << simple.savings(discount) << endl;
}
else
    cout << "Discounted item is not cheaper.\n";
return 0;
}
