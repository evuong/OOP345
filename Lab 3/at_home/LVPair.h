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
        
        virtual void display(std::ostream& os) const {
            os << l << " : " << v << endl;
        }
        
        L returnL() const { return l; }
        V returnV() const { return v; }
    };

    template<typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
        pair.display(os);
        return os;
    }
    
    template<typename L, typename V>
    class SummableLVPair : public LVPair<L, V> {
        static V initial;                       //needs to be static for template spacialization
        static size_t width;                    //needs to be static for template spacialization
    public:
        SummableLVPair() {}
        
        //if width is smaller than label size, change width to label size
        SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
            if (width < label.size()) {
                width = label.size();
            }
        }
        
        //returns 'initial' data member
        static const V& getInitialValue() {
            return initial;
        }
        
        //returns current value + sum
        V sum(const L& label, const V& sum) const {
            return LVPair<L,V>::returnV() + sum;
        }
        
        //set left, set width then outputs 'label : value'
        void display(std::ostream& os) const {
            os.setf(ios::left);
            os.width(static_cast<int>(width));
            os << LVPair<L,V>::returnL() << " : " << LVPair<L,V>::returnV() << endl;
        }
    };
    
    //A templated declaration that initializes the field width class variable to 0.
    template<typename L, typename V>
    size_t SummableLVPair<L, V>::width = 0u;
    
    //A template specialization that initializes the starting value for an LVPair<std::string, int> type to 0.
    template<>
    int SummableLVPair<string, int>::initial = 0;
    
    //A template specialization that initializes the starting value for an LVPair<std::string, std::string> type to an empty string.
    template<>
    string SummableLVPair<string, string>::initial = "";

    //A template specialization of the sum() query for LVPair<std::string, std::string> types that inserts a single space between concatenating strings.
    template<>
    string SummableLVPair<string, string>::sum(const string& l, const string& v) const {
        return v + " " + LVPair<string,string>::returnV();
    }
}
#endif
