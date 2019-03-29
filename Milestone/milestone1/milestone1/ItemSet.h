// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#ifndef ItemSet_h
#define ItemSet_h

#include <iostream>
#include <iomanip>
#include "Utilities.h"

namespace sict {
    class ItemSet {
        std::string name;
        unsigned int serial_num;
        unsigned int quantity;
        std::string desc;
        static size_t field_width;
    public:
        ItemSet(const std::string&);
        const std::string getName() const;
        const unsigned int getSerialNumber() const;
        const unsigned int getQuantity() const;
        ItemSet& operator--();
        void display(std::ostream&, bool);
    };
}
#endif
