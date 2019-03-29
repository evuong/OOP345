//
//  Taxable.cpp
//  at_home
//
//  Created by e on 2019-03-06.
//  Copyright © 2019 e. All rights reserved.
//

#include "Taxable.h"
extern int FW;
namespace sict {
    Taxable::Taxable(size_t num, double price, char tax_char) : Product(num, price), tax_status {tax_char} {}
    
    double Taxable::price() const {
        return tax_status.at(0) == 'H' ? Product::price()*1.13 : Product::price()*1.08;
    }
    
    void Taxable::display(std::ostream& os) const {
        Product::display(os);
        os << std::left << std::setw(FW);
        tax_status.at(0) == 'H' ? os << " HST" : os << " PST";
    }
    
    iProduct* readRecord (std::ifstream& file) {
        /*
        iProduct* product = nullptr;
        unsigned no;
        double price;
        char tax;
        file >> no >> price;
        
        if (file.get() != '\n') {
            file >> tax;
        }
        else {
            tax = ' ';
        }
        
        if (file.good()) {
            if (tax != ' ') {
                product = new Taxable(no, price, tax);
            }
            else {
                product = new Product(no, price);
            }
        }
        return product; */
        
        
        static int count {0};
        static std::string* records;
        long num;
        double pbt;
        std::string tax;
        
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
        size_t space2 = records[count].find(' ', space+1);
        
        //num is from beginning of line to space
        num = std::stol(records[count].substr(0, space));
        
        //pricebeforetax is from space until end of line or space
        pbt = std::stod(records[count].substr(space, space2));
        
        if (space2 != std::string::npos) {
            tax = records[count].substr(space2, std::string::npos);
            count++;
            char tax_status = tax.at(1);
            return new Taxable(num, pbt, tax_status);
        }
        count++;
        return new Product(num, pbt);
    }
}
