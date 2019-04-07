// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08


#ifndef LineManager_h
#define LineManager_h

#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"
#include <vector>
#include <queue>

namespace sict {
    class LineManager {
        std::vector<Station*> station;
        std::deque<CustomerOrder> incomplete;
        std::deque<CustomerOrder> complete;
        size_t count;
    public:
        LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
        void display(std::ostream&) const;
        bool run(std::ostream&);
    };
}

#endif
