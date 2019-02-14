// Workshop 4 - Containers
// w4.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Feb 7, 2019

#ifndef Message_h
#define Message_h

#include <iostream>
#include <string.h>

namespace sict {
    class Message {
        std::string user;
        std::string reply;
        std::string tweet;
        bool at;
    public:
        Message ();
        Message (const std::string&);
        bool empty() const;
        void display(std::ostream&) const;
    };
}

#endif
