// Workshop 7 - STL Algorithms
// w7.cpp
// Edward Vuong - 120246186
// evuong1@myseneca.ca
// Section: SEE
// Mar 20, 2019

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <fstream>
#include <numeric>
#include <cmath>


extern int FW;
extern int ND;

namespace sict {
    template<typename T>
    class DataTable {
        std::vector<T> x_values;
        std::vector<T> y_values;
        
        T mean() const {
            size_t total = 0;
            total += std::accumulate(y_values.begin(), y_values.end(), 0);
            return total/y_values.size();
        }
        
        T sigma() const {
            T sigma = 0;
            T avg = mean();
            std::vector<T> n;
            n.resize(y_values.size());
            
            //subtract each y-value by the mean and square them. then store inside vector 'n'
            std::transform(y_values.begin(), y_values.end(), n.begin(), [&](int i){ return pow(i-avg,2); });
            
            //sum the numbers in vector 'n', divide by number of y_values-1 then square root it
            sigma += std::accumulate(n.begin(), n.end(), 0);
            sigma /= y_values.size()-1;
            
            return sqrt(sigma);
        }
        
    public:
        DataTable(std::ifstream& file) {
            if (file.is_open()) {
                T x, y;
                bool more = true;
                
                do {
                    if (file >> x >> y) {           //if readable then populate vectors x and y
                        x_values.push_back(x);
                        y_values.push_back(y);
                    }
                    else more = false;              //if not readable then end loop
                } while (more);
            }
        }
        
        void displayData(std::ostream& os) const {
            os << "Data Values\n------------\n";
            os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;
            
            for (int i = 0; i < x_values.size(); i++) {
                os << std::setw(FW) << std::fixed << std::setprecision(ND) << x_values[i]
                << std::setw(FW) << std::fixed << std::setprecision(ND) << y_values[i] << std::endl;
            }
        }
        
        void displayStatistics(std::ostream& os) const {
            os << "\nStatistics\n----------\n";
            os << std::setw(FW) << "y mean" << "    =  " << mean() << std::endl;
            os << std::setw(FW+1) << "y sigma" << "   =   " << sigma() << std::endl;
        }
    };
}
#endif
