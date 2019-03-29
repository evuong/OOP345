// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        
        for (unsigned int i = 0; i < desc.size(); i++) {
            for (unsigned int n = 0; n < price.size(); n++) {
                if (desc[i].code == price[n].code) {
                    auto match = new Product(desc[i].desc,price[n].price);
                    match->validate();
                    priceList+=match;
                    delete match;
                }
            }
        }
        
        return priceList;
    }
}
