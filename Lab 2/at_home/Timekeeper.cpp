// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Edward Vuong
// 120246186
// Section SEE

#include <iostream>
#include <string>
#include <chrono>
#include <cstring>
#include <iomanip>
#include "Timekeeper.h"
#include "Text.h"
using namespace std;

namespace sict {
    Timekeeper::Timekeeper() {
    }
    
    void Timekeeper::start() {
        begin = std::chrono::steady_clock::now();
    }
    
    void Timekeeper::stop() {
        end = std::chrono::steady_clock::now();
    }
    
    void Timekeeper::recordEvent(const char* event) {
        const char* units = "seconds";          //no other way to set seconds from parameters passed
        records[num].time = units;
        records[num].message = event;
        
        records[num].duration = (end - begin);
        num++;
    }
    
    void Timekeeper::report(std::ostream& os) const {
        os << "\nExecution Times:" << endl;
        for (int i = 0; i < num; i++) {
            os << records[i].message << setw(10) << records[i].duration.count()
            << " " << records[i].time << endl;
        }
    }
}

