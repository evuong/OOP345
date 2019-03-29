// Workshop 5 - Functions
// w5.cpp
// Edward Vuong
// 120246186
// Section SEEE
// 2019/02/10

#ifndef KVPair_h
#define KVPair_h

#include <iostream>
extern int fieldWidth;

namespace sict {
    template<typename K, typename V>
    class KVPair {
        K k;
        V v;
    public:
        KVPair() : k{}, v{} {}
        
        KVPair(const K& key, const V& value) : k{key}, v{value} {}

        template<typename F>
        void display(std::ostream& os, F f) const {
            os << std::left << std::setw(fieldWidth) << k << " : "
            << std::right << std::setw(fieldWidth) << v
            << std::setw(fieldWidth) << f(v) << std::endl;
        }
    };
}
#endif
