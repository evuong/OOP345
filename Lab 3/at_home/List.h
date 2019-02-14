// Workshop 3 - Templates
// w3.cpp
// Edward Vuong
// 120246186
// Section: SEE
// Jan 31, 2019

#ifndef List_hpp
#define List_hpp
#include <iostream>

namespace sict{
    template<typename T, int N>     //T is type of element, N is max num of elements
    class List {
        T arr[N];
        size_t num = 0;
    public:
        
        //returns the num stored in the array
        size_t size() const {
            return num;
        }
        
        //returns array at the position that is received
        const T& operator[](size_t i) const {
            return arr[i];
        }
        
        //checks if array is full, if not then set array at current num to received T
        void operator+=(const T& t) {
            if (num < N) {
                arr[num] = t;
                num++;
            }
        }
    };
    
    template<typename T, typename L, typename V, int N>
    class LVList : public List <T, N> {
    public:
        V accumulate (const L& label) const {
            List<T,N>& temp = (List<T, N>&)*this;
            V result = SummableLVPair<L,V>::getInitialValue();
            
            for (size_t i = 0; i < temp.size(); i++) {
                if (label == temp[i].LVPair<L,V>::returnL())
                    result = temp[i].sum(label, result);
            }
            return result;
        }
    };
}
#endif
