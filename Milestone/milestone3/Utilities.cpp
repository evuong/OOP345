// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#include "Utilities.h"

namespace sict {
    char Utilities::delimiter;
    Utilities::Utilities() : field_width{0} {}
    
    const std::string Utilities::extractToken(const std::string str, size_t& next_pos) {
        std::string token;
        
        if (next_pos <= str.length()) {
            size_t pos_delimit = str.find(getDelimiter(), next_pos);
            
            if (pos_delimit != std::string::npos) {
                token = str.substr(next_pos, (pos_delimit-next_pos));
                next_pos = pos_delimit+1;
            }
            else {
                token = str.substr(next_pos);
                next_pos = str.length()+1;
            }
            
            if (token.length() == 0)
                throw "Exception: There is no token.";
            
            if (field_width > token.length())
                field_width = static_cast<int>(token.length());
            
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
        field_width = static_cast<int>(fw);
    }
}