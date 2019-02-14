// Workshop 4 - Containers
// w4.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Feb 11, 2019

#ifndef MessagePack_h
#define MessagePack_h

#include <iostream>
#include "Message.h"

namespace sict {
    class MessagePack {
        Message* message;
        size_t no_msg;
    public:
        MessagePack();
        MessagePack(Message*[], int);
        void display(std::ostream&) const;
        size_t size() const;
        ~MessagePack();
        
        MessagePack(const MessagePack&);            //copy constructor
        MessagePack& operator=(const MessagePack&); //copy assignment operator
        MessagePack(MessagePack&&);                 //move constructor
        MessagePack& operator=(MessagePack&&);      //move assignment operator
    };
    std::ostream& operator<<(std::ostream&, const MessagePack&);
}
#endif
