// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#ifndef Utilities_h
#define Utilities_h

#include <iostream>

namespace sict {
    class Utilities {
        size_t field_width;
        static char delimiter;
    public:
        Utilities();
        const std::string extractToken (const std::string, size_t&);
        const char getDelimiter() const;
        size_t getFieldWidth() const;
        static void setDelimiter(const char);
        void setFieldWidth(size_t);
        
        //Your design disables copy and move assignment operations and copy construction of the list.
        Utilities(const Utilities&) = delete;
        Utilities& operator=(const Utilities&) = delete;
        Utilities& operator=(Utilities&&) = delete;
    };
}
#endif
