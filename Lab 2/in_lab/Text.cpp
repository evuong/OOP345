// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Edward Vuong
// 120246186
// Section SEE

#include "Text.h"
#include <fstream>
using namespace std;

namespace sict {
    Text::Text() {
        str = nullptr;
    }
    
    Text::Text(const char* poem) {
        ifstream in(poem);
        string extra;       //random string to hold lines
        
        if (in.is_open()) {
            while (getline(in,extra,'\n')) {        //because while(!in.eof()) is wrong
                records++;
            }
            
            in.clear();
            in.seekg(0, in.beg);            //restart at the beginning of file
            str = new string[records];      //allocate memory for string
            
            for (size_t i = 0; i < records; i++) {  //using size_t to match records type of size_t
                getline(in, str[i]);
            }
        }
        else {
            Text();
        }
    }
    
    //copy constructor
    Text::Text(Text& t) {
        *this = t;
    }
    
    //copy assignment operator
    Text& Text::operator=(const Text& t) {
        if (this != &t) {
            records = t.records;
            delete[] str;
            str = new string [records];
            str = t.str;
        }
        return *this;
    }
    
    Text::~Text() {
    }
    
    size_t Text::size() const {
        return records;
    }
}
