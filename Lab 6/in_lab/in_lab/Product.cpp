// Workshop 6 - STL Containers
// w6.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// 2019/03/03

#include "Product.h"

extern int FW;

namespace sict {
    Product::Product(size_t num, double pbt) : prod_id {num}, prod_price {pbt} {}
    
    double Product::price() const {
        return prod_price;
    }
    
    void Product::display(std::ostream& os) const {
        os << std::right << std::setw(FW) << prod_id
        << std::right << std::setw(FW) << prod_price << std::endl;
    }
    
    iProduct* readRecord (std::ifstream& file) {
        static int count {0};
        static std::string* records;
        long num;
        double pbt;
        
        if (file.is_open() && count == 0) {         //makes sure that this only runs once
            std::string empty;
            size_t num_records {0};
            
            //seek to beginning
            file.clear();
            file.seekg(0, file.beg);
            
            //counts # of lines in file
             while (getline(file, empty)) {
                 num_records++;
            }
            
            //seek to beginning
            file.clear();
            file.seekg(0, file.beg);
            
            //allocates memory for number of lines in file
            records = new std::string[num_records];
            
            //puts file, line by line, into records
            for (size_t i = 0; i < num_records; i++) {
                getline(file, records[i], '\n');
            }
        }
        
        size_t space = records[count].find(' ');

        //num is from beginning of line to space
        num = std::stol(records[count].substr(0, space));
        
        //pricebeforetax is from space until end of line
        pbt = std::stod(records[count].substr(space, std::string::npos));
        
        count++;
        
        return new Product(num, pbt);
    }
    
    std::ostream& operator<<(std::ostream& os, const iProduct& p) {
        p.display(os);
        return os;
    }
}
