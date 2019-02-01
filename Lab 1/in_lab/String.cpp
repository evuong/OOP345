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
            int length = MAX+1;
            
            first = new char[length];
            for (int i = 0; i < length; i++) {
                first[i] = one[i];
            }
            first[MAX] = '\0';
        }
        else {
            first = nullptr;
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

