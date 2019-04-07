// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08


#ifndef Station_h
#define Station_h

#include <iostream>
#include <deque>
#include "CustomerOrder.h"

namespace sict {
    class Station {
        
        //Each Station contains a CustomerOrder queue and an ItemSet sub-object.
        std::deque<CustomerOrder> queue;
        ItemSet* item;
    public:
        Station(const std::string&);
        void display(std::ostream&) const;
        void fill(std::ostream&);
        const std::string& getName() const;
        bool hasAnOrderToRelease() const;
        Station& operator--();
        Station& operator+=(CustomerOrder&&);
        bool pop(CustomerOrder&);
        void validate(std::ostream&) const;
        
        //Each station object is unique and hence neither copyable, moveable, copy-assignable nor move-assignable.
        Station(const Station&) = delete;
        Station(Station&&) = delete;
        Station& operator=(const Station&) = delete;
        Station& operator=(Station&&) = delete;
    };
}

#endif
