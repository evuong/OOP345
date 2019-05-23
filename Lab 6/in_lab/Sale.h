// Workshop 6 - STL Containers
// w6.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// 2019/03/03

#ifndef Sale_h
#define Sale_h

#include <iostream>
#include "iProduct.h"

namespace sict {
    class Sale {
        std::vector<iProduct*> iprods;
        size_t num_records {0};
    public:
        Sale(const char*);
        void display(std::ostream&) const;
    };
}

#endif
