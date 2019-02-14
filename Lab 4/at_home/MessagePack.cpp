// Workshop 4 - Containers
// w4.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Feb 11, 2019

#include "MessagePack.h"

namespace sict {
    MessagePack::MessagePack() {
        message = nullptr;
        no_msg = 0;
    }
    
    MessagePack::~MessagePack() {
        delete[] message;
        message = nullptr;
    }
    
    MessagePack::MessagePack(Message* msg[], int max) {
        if (max > 0 && msg != nullptr) {
            this->message = new Message[max];
            no_msg = 0;
            for (size_t i = 0; i < max; ++i) {
                if (!msg[i]->empty()) {
                    this->message[no_msg++] = *msg[i];
                }
            }
        }
    }
    
    void MessagePack::display(std::ostream& os) const {
        for (size_t i = 0; i < no_msg; i++) {
            if (!message[i].empty()) {
                message[i].display(os);
            }
        }
    }
    
    size_t MessagePack::size() const {
        return no_msg;
    }
    
    MessagePack::MessagePack(const MessagePack& msgp) {
        *this = msgp;
    }
    
    MessagePack& MessagePack::operator=(const MessagePack& msgp) {
        if (&msgp != this) {
            no_msg = msgp.no_msg;
            delete[] message;
            
            message = new Message[no_msg];
            for (size_t i = 0; i < no_msg; i++) {
                message[i] = msgp.message[i];
            }
        }
        return *this;
    }
    
    MessagePack::MessagePack(MessagePack&& msgp) {
        *this = std::move(msgp);
    }
    
    MessagePack& MessagePack::operator=(MessagePack&& msgp) {
        if (&msgp != this) {
            
            delete[] message;
            no_msg = msgp.no_msg;
            message = msgp.message;
            
            msgp.no_msg = 0;
            msgp.message = nullptr;
        }
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& os, const MessagePack& msgp) {
        msgp.display(os);
        return os;
    }
}
