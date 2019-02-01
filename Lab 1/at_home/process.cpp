// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Edward Vuong 120246186
// evuong1@myseneca.ca
// OOP345 - SEE

#include <iostream>
#include "String.h"
#include "String.h"

namespace sict {
    void process(const char* str) {
        String a = String(str);
        std::cout << a << std::endl;
    }
}
