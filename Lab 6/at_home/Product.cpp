// Workshop 6 - STL Containers
// w6.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// 2019/03/03

#include "Product.h"
extern int FW;

namespace sict {
    Product::Product(size_t num, double pbt) : prod_id {num}, prod_price {pbt} {}
    
    double Product::price() const {
        return prod_price;
    }
    
    void Product::display(std::ostream& os) const {
        os << std::right << std::setw(FW) << prod_id
        << std::right << std::setw(FW) << prod_price;
    }
    
    std::ostream& operator<<(std::ostream& os, const iProduct& p) {
        p.display(os);
        return os;
    }
}
