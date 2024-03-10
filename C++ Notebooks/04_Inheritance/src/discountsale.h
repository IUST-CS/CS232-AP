//This is the interdace for the class DiscountSale.
#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H        //This is the file 'discountsale.h'

#include <iostream>
#include "sale.h"
using namespace std;
using namespace salesavitch;

namespace slaesavitch
{
    class DiscountSale : public Sale
    {
    public:
        DiscountSale() : discount(0)
        {
            this->discount = 0;
        }
        DiscountSale(double thePrice, double theDiscount) : discount(theDiscount)
        {

        }
        //Discount is expressed as a percent of the price.
        virtual double bill(){
            return float(this->discount / this->price);
        }
    protected:
        double discount;
    };
}//salesavitch
#endif //DISCOUNTSALE_H