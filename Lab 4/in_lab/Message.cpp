// Workshop 4 - Containers
// w4.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Feb 7, 2019

#include "Message.h"

namespace sict {
    Message::Message() {
        user = "";
        reply = "";
        tweet = "";
    }
    
    Message::Message(const std::string& str) {
        size_t end = std::string::npos;         //string end checker

        //looking for first space position and using that to find name
        size_t pos_name = str.find(' ') ;
        user = str.substr(0, pos_name);
        //if there's no msg, it sets the object to a safe empty state
        if (pos_name == end) {
            *this = Message();
        }
        
        //looking for @ to see if the msg is a reply
        size_t pos_at = str.find('@');
        
        //if there is an '@'
        if (pos_at != end) {
            at = true;
            
            //find position of first space start after the '@'
            size_t pos_replyto = str.find(' ', pos_at);
            
            //position of @ until space is the recipient
            reply = str.substr(pos_at+1, pos_replyto-pos_at-1);
            
            //position from space until end is the tweet
            tweet = str.substr(pos_replyto+1, end);
        }
        else {                  //if there's no '@'
            at = false;
            
            //position from first space until the end is the tweet
            tweet = str.substr(pos_name+1, end);
        }
    }
    
    //if user is empty then object is in an empty state
    bool Message::empty() const {
        return user == "" ? true : false;
    }
    
    void Message::display(std::ostream& os) const {
        
        //if object ISNT empty, then display
        if (!empty()) {
            os << ">User  : " << user << std::endl;
            
            //if 'at' boolean is true then add a reply section
            if (at) {
                os << " Reply : " << reply << std::endl;
            }
            os << " Tweet : " << tweet << std::endl;
        }
    }
}
