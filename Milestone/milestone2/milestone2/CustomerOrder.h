// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#ifndef CustomerOrder_h
#define CustomerOrder_h

#include <iostream>
#include <algorithm>
#include "ItemSet.h"

namespace sict {
    
    //Hint: one way to hold this information is in array of ItemInfo sub-objects nested within the object itself. Information that needs to be tracked includes the name of the item, its serial number, and its filled status.
    struct ItemInfo {
        std::string name;
        unsigned int serial_num = 0;
        bool filled = false;

        ItemInfo(std::string str) : name{str} {}
    };
    
    class CustomerOrder {
        std::string customer;
        std::string product;
        static unsigned int field_width;
        size_t count;
        ItemInfo** items;
    public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        ~CustomerOrder();
        void fillItem(ItemSet&, std::ostream& os);
        bool isFilled() const;
        bool isItemFilled(const std::string&) const;
        std::string getProductName() const;
        void display(std::ostream&, bool) const;
        
        //they are both movable and move-assignable.
        CustomerOrder(CustomerOrder&&);
        CustomerOrder& operator=(CustomerOrder&&);
        
        //Customer order objects are unique and hence neither copyable nor copy-assignable.
        CustomerOrder(const CustomerOrder&) = delete;
        CustomerOrder& operator=(const CustomerOrder&) = delete;
    };
}

#endif
