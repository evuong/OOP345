// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Edward Vuong
// 120246186
// Section SEE

#ifndef Text_h
#define Text_h

#include <iostream>

namespace sict {
    class Text {
        size_t records;
        std::string* str;
    public:
        Text();                         //default constructor
        Text(const char*);
        Text(Text&);                    //copy constructor
        Text& operator=(const Text&);         //copy assignment operator
        ~Text();                        //destructor
        size_t size() const;
    };
}

#endif
