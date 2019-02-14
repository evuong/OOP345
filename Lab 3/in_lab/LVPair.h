// Workshop 3 - Templates
// w3.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Jan 31, 2019

#ifndef LVPair_hpp
#define LVPair_hpp
#include <iostream>

using namespace std;
namespace sict {
    template<typename L, typename V>
    class LVPair {
        L l;
        V v;
    public:
        LVPair() {}
        
        LVPair(const L& label, const V& value) {
            l = label;
            v = value;
        }
        
        void display(std::ostream& os) const {
            os << l << " : " << v << endl;
        }
    
    };
    
    template<typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
        pair.display(os);
        return os;
    }
}
#endif
