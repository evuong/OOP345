// Workshop 6 - STL Containers
// w6.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// 2019/03/03

#ifndef iProduct_h
#define iProduct_h

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

namespace sict {
    class iProduct {
    public:
        virtual double price() const = 0;
        virtual void display(std::ostream&) const = 0;
    };
    std::ostream& operator<<(std::ostream&, const iProduct&);
    iProduct* readRecord(std::ifstream&);
}

#endif
