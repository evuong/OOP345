// Workshop 6 - STL Containers
// w6.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// 2019/03/03

#include "Sale.h"

extern int FW;

namespace sict {
    Sale::Sale(const char* f) {
        try {
            std::ifstream file(f);
            std::string empty;
            
            if (file.is_open()) {
                
                //counts # of lines in file
                while (getline(file, empty)) {
                    num_records++;
                }
                
                for (size_t i = 0; i < num_records; i++) {
                    iprods.push_back(readRecord(file));
                }
            }
            else {
                throw "Exception: File could not be opened.";
            }
        } catch (const char* msg) {
            std::cout << msg << std::endl;
        }
        
    }
    
    void Sale::display(std::ostream& os) const {
        double total {0};
        
        os << std::setw(FW) << "Product No"
        << std::right << std::setw(FW) << "Cost" << std::endl;
        
        for (auto i : iprods) {
            total += i->price();
            
            os << std::right << std::setw(FW) << std::fixed << std::setprecision(2);
            i->display(os);
        }
        
        os << std::right << std::setw(FW) << "Total"
        << std::right << std::setw(FW) << std::fixed << std::setprecision(2) << total << std::endl;
    }
}
