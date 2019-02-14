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
}



#endif
