// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#include "Utilities.h"

namespace sict {
    char Utilities::delimiter;
    Utilities::Utilities() : field_width{1} {}
    
    const std::string Utilities::extractToken(const std::string str, size_t& next_pos) {
        std::string token;
        
        if (next_pos <= str.length()) {
            size_t pos_delimit = str.find(getDelimiter(), next_pos);
            
            token = str.substr(next_pos, pos_delimit);
            next_pos = pos_delimit+1;
            
            if (next_pos == std::string::npos)
                next_pos = str.length()+1;
            
            if(field_width > token.length())
                field_width = token.length();
            
            if(token.length() == 0)
                throw "Exception: There is no token.";
        }
        return token;
    }
    
    const char Utilities::getDelimiter() const {
        return delimiter;
    }
    
    size_t Utilities::getFieldWidth() const {
        return field_width;
    }
    
    void Utilities::setDelimiter(const char d) {
        delimiter = d;
    }
    
    void Utilities::setFieldWidth(size_t fw) {
        field_width = fw;
    }
}
