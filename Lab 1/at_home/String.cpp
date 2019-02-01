// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Edward Vuong 120246186
// evuong1@myseneca.ca
// OOP345 - SEE

#include "String.h"
#include <iostream>

namespace sict {
    extern const int initial = 3;      //linking initial from w1
    
    String::String(const char* one) {
        if (one != nullptr) {
            first = new char[sizeof(one)];
            strcpy(first, one);
        }
        else {
            first = new char[1];
            first[0] = '\0';
        }
    }
    
    void String::display(std::ostream& os) const {
        os << first;
    }
    
    std::ostream& operator<<(std::ostream& os, const String& cstrn) {
        static int itemNumber = initial;        //static to keep itemNumber in memory
        os << itemNumber << ": ";
        cstrn.display(os);
        itemNumber++;
        
        return os;
    }
}

