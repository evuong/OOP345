// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Edward Vuong 120246186
// evuong1@myseneca.ca
// OOP345 - SEE

#ifndef String_h
#define String_h

#include <iostream>
#include <cstring>

namespace sict {
    const int MAX = 3;
    
    class String {
        char* first;
    public:
        String(const char*);
        void display(std::ostream&) const;
    };
    
    std::ostream& operator<<(std::ostream&, const String&);
}


#endif
