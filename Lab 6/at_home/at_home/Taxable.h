//
//  Taxable.hpp
//  at_home
//
//  Created by e on 2019-03-06.
//  Copyright © 2019 e. All rights reserved.
//

#ifndef Taxable_h
#define Taxable_h

#include <iostream>
#include "Product.h"

namespace sict {

    class Taxable : public Product {
        std::string tax_status;
        double tax_rate;
        enum Tax { HST, PST };
    public:
        Taxable(size_t, double, char);
        double price() const;
        void display(std::ostream&) const;
    };
}

#endif
