// Workshop 6 - STL Containers
// w6.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// 2019/03/03

#ifndef Product_h
#define Product_h

#include <iostream>
#include "iProduct.h"

namespace sict {
    class Product : public iProduct {
        size_t prod_id;
        double prod_price;
    public:
        Product(size_t, double);
        double price() const;
        void display(std::ostream&) const;
    };
}

#endif
