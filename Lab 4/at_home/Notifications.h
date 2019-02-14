// Workshop 4 - Containers
// w4.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Feb 11, 2019

#ifndef Notifications_h
#define Notifications_h

#include <iostream>
#include "Message.h"

namespace sict {
    class Notifications {
        const Message** message;
        int max_msgs;
        int no_msgs;
    public:
        Notifications();
        Notifications(int);
        Notifications& operator+=(const Message& msg);
        Notifications& operator-=(const Message& msg);
        void display(std::ostream&) const;
        size_t size() const;
        ~Notifications();
        
        Notifications(const Notifications&);            //copy constructor
        Notifications& operator=(const Notifications&); //copy assignment operator
        Notifications(Notifications&&);                 //move constructor
        Notifications& operator=(Notifications&&);      //move assignment operator
    };
    std::ostream& operator<<(std::ostream&, const Notifications&);
}

#endif
