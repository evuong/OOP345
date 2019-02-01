// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Edward Vuong
// 120246186
// Section SEE

#ifndef Timekeeper_h
#define Timekeeper_h

#include <iostream>
#include <chrono>

namespace sict {
    class Timekeeper {;
        static const int MAX = 10;
        int num;
        std::chrono::steady_clock::time_point begin;
        std::chrono::steady_clock::time_point end;
        struct record {
            const char* message;
            const char* time;
            std::chrono::steady_clock::duration duration;
        };
        record records[MAX];
    public:
        Timekeeper();
        void start();
        void stop();
        void recordEvent(const char*);
        void report(std::ostream&) const;
    };
}

#endif
