// Workshop 4 - Containers
// w4.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Feb 11, 2019

#include "Notifications.h"

namespace sict {
    Notifications::Notifications() {
        message = nullptr;
        no_msgs = 0;
        max_msgs = 0;
    }
    
    Notifications::Notifications(int max) {
        if (max > 0) {
            max_msgs = max;
            message = new const Message*[max];
            no_msgs = 0;
        }
        else {
            Notifications();
        }
    }
    
    Notifications& Notifications::operator+=(const Message& msg) {
        if (!msg.empty() && no_msgs < max_msgs) {
            message[no_msgs++] = &msg;
        }
        return *this;
    }
    
    Notifications& Notifications::operator-=(const Message& msg) {
        bool found = false;
        int i = 0;
        
        for (; i < no_msgs && !found; ++i) {
            if (message[i] == &msg) {
                found = true;
            }
            
            if (found) {
                for (; i < no_msgs-1; ++i) {
                    message[i] = message[i+1];
                }
            }
            message[i] = nullptr;
            no_msgs--;
        }
        return *this;
    }
    
    void Notifications::display(std::ostream& os) const {
        for (size_t i = 0; i < no_msgs; i++) {
            (*message[i]).display(os);
        }
    }
    
    size_t Notifications::size() const {
        return no_msgs;
    }
    
    Notifications::~Notifications() {
        delete[] message;
        message = nullptr;
    }
    
    Notifications::Notifications(const Notifications& n) {
        *this = n;
    }
    
    Notifications& Notifications::operator=(const Notifications& n) {
        if (&n != this) {
            no_msgs = n.no_msgs;
            max_msgs = n.max_msgs;
            delete[] message;
            message = *new const Message**[max_msgs];
            
            for (size_t i = 0; i < max_msgs; i++) {
                message[i] = n.message[i];
            }
        }
        return *this;
    }
    
    Notifications::Notifications(Notifications&& n) {
        *this = std::move(n);
    }
    
    Notifications& Notifications::operator=(Notifications&& n) {
        if (&n != this) {
            delete[] message;
            no_msgs = n.no_msgs;
            max_msgs = n.max_msgs;
            message = n.message;
            
            n.no_msgs = 0;
            n.max_msgs = 0;
            n.message = nullptr;
        }
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& os, const Notifications& n) {
        n.display(os);
        return os;
    }
}
