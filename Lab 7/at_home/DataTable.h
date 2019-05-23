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
#include <algorithm>

extern int FW;
extern int ND;

namespace sict {
    template<typename T>
    class DataTable {
        std::vector<T> x_values;
        std::vector<T> y_values;
        
        T mean() const {
            T total = 0;
            total += std::accumulate(y_values.begin(), y_values.end(), 0.0000);
            
            /*
            std::cout << "\n\n\n\n\n Y VALUES\n -------------\n";
            std::cout << total << std::endl;
            std::cout << y_values.size() << std::endl;
            for (auto i : y_values)
                std::cout << i << ' ';
            std::cout << std::endl; */
            
            return total/y_values.size();
        }
        
        T sigma() const {
            T sigma = 0;
            T avg = mean();
            std::vector<T> n(y_values.size());
            
            //subtract each y-value by the mean and square them. then store inside vector 'n'
            std::transform(y_values.begin(), y_values.end(), n.begin(), [&](auto i){ return pow(i-avg,2); });
            
            //sum the numbers in vector 'n', divide by number of y_values-1 then square root it
            sigma += std::accumulate(n.begin(), n.end(), 0.0000);
            
            return sqrt(sigma/(y_values.size()-1));
        }
        
        T median() const {
            std::vector<T> y = y_values;
            std::sort(y.begin(), y.end());
            
            //when even number of items: (n/2 + (n/2)+1)/2
            if (y.size() % 2 == 0)
                return y[(y.size()/2 + (y.size()/2)+1)/2];
            //when odd number of items: (n+1)/2
            else
                return y[(y.size()+1)/2];
        }
        
        T slope() const {
            /* values needed:
                -number of values
                -sum of product of x*y
                -sum of x_values
                -sum of y_values
                -sum of x_values^2
             */
            
            size_t n = x_values.size();
            std::vector<T> xy(n);
            T xy_total = 0;
            T x_sum = 0;
            T y_sum = mean() * y_values.size();    //mean is sum of y_values/size. *size to cancel it out
            T x2_sum = 0;
            
            //product of x*y stored in a vector
            std::transform(x_values.begin(), x_values.end(), y_values.begin(), xy.begin(), [](auto x, auto y){ return x*y; });
            
            //sum of product of x*y stored in xy_total
            xy_total += std::accumulate(xy.begin(), xy.end(), 0.0000);
            
            //sum of x_values
            x_sum += std::accumulate(x_values.begin(), x_values.end(), 0.0000);
            
            //sum of x_values^2
            std::for_each(x_values.begin(), x_values.end(), [&](auto x){ x2_sum += pow(x,2); });
            
            //following the formula
            return (n*xy_total - x_sum*y_sum) / ((n*x2_sum) - pow(x_sum,2));
        }
        
        T intercept() const {
            //recreating another x_sum
            T x_sum = 0;
            x_sum += std::accumulate(x_values.begin(), x_values.end(), 0.0000);
            
            T y_sum = mean() * y_values.size(); //same concept as above
            
            //following the formula
            return (y_sum - slope()*x_sum)/x_values.size();
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
            os << "  y mean    =  " << std::setw(FW) << mean() << std::endl;
            os << "  y sigma   =  " << std::setw(FW) << sigma() << std::endl;
            os << "  y median  =  " << std::setw(FW) << median() << std::endl;
            os << "  slope     =  " << std::setw(FW) << slope() << std::endl;
            os << "  intercept =  " << std::setw(FW) << intercept() << std::endl;
        }
    };
}
#endif
