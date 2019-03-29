// Workshop 5 - Functions
// w5.cpp
// Edward Vuong
// 120246186
// Section SEEE
// 2019/02/10

#ifndef KVList_h
#define KVList_h

#include <iostream>

namespace sict {
    template<typename T>
    class KVList {
        T* list;
        int max_size;
        int current;
    public:
        KVList() : list{nullptr}, max_size{0}, current{0} {}
        
        KVList(int n) {
            if (n > 0) {
                list = new T[n];
                max_size = n;
                current = 0;
            }
            else {
                list = nullptr;
                max_size = 0;
                current = 0;
            }
        }
        
        KVList(KVList&& kv) {
            if (this != &kv) {
                max_size = kv.max_size;
                current = kv.current;
                list = kv.list;
                
                kv.list = nullptr;
                kv.max_size = 0;
                kv.current = 0;
            }
        }
        
        ~KVList() {
            delete[] list;
            list = nullptr;
        }
        
        const T& operator[](size_t i) const {
            return list[i];
        }
        
        template<typename F>
        void display(std::ostream& os, F f) const {
            for (int i = 0; i <= max_size; i++) {
                list[i].display(os, f);
            }
        }
        
        void push_back(const T& t) {
            if (current <= max_size) {
                list[current++] = t;
            }
        }
        
        //Your design disables copy and move assignment operations and copy construction of the list.
        KVList(const KVList&) = delete;
        KVList& operator=(const KVList&) = delete;
        KVList& operator=(KVList&&) = delete;

    };
}
#endif
