// Workshop 5 - Functions
// w5.cpp
// Edward Vuong
// 120246186
// Section SEEE
// 2019/02/10

#ifndef Taxable_h
#define Taxable_h

#include <iostream>

namespace sict {
    class Taxable {
        const float tax;
    public:
        Taxable(float t) : tax{t} {}
        
        float operator()(float price) {
            return 1*tax+price;
        }
    };
}
#endif
