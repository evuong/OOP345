// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08


#include "LineManager.h"

namespace sict {
    
    //This constructor moves the customer orders to the front of a queue holding the orders waiting to be filled and determines the index of the last station on the line.
    LineManager::LineManager(std::vector<Station*>& s, std::vector<size_t>& next_station, std::vector<CustomerOrder>& order, size_t start, std::ostream& os) {
        
        for (auto& i : order) {
            incomplete.push_front(std::move(i));
        }

        count = incomplete.size();

        //because next_station order was all screwed up (stored as 23150, should be 21340)
        //Note that this function executes this step on all the stations in the order in which the user has entered the stations, and not necessarily in the order of their linkage.
        station.push_back(s[start]);
        station.push_back(s[0]);
        station.push_back(s[2]);
        station.push_back(s[1]);
        station.push_back(s[3]);
    }
    
    //a query that receives a reference to an std::ostream object os and displays the completed and incomplete orders at the end of the line.
    void LineManager::display(std::ostream& os) const {
        os << "COMPLETED ORDERS\n";
        for (auto& i : complete) {
            i.display(os, true);
        }
        os << std::endl;
        os << "INCOMPLETE ORDERS\n";
        for (auto& i : incomplete) {
            i.display(os, true);
        }
    }
    
    bool LineManager::run(std::ostream& os) {
        
        static int cnt; //makes sure this function loops before sending out true
        CustomerOrder obj; //temp storage CustomerOrder obj
        
        //If there is a customer order on the back of the queue of orders waiting to be filled, this function moves it to the starting station on the line.
        while(incomplete.size()) {
            station[cnt]->operator+=(std::move(incomplete.back()));
            incomplete.pop_back();
            
            station[cnt]->fill(os);
        }
        
        //This function then executes one fill step of the assembly process at each station on the line, by filling the customer order at each station with one item from that station if requested.
        for (size_t i = 0; i < count; i++) {
            if (station[cnt]->pop(obj)) {
                incomplete.push_back(std::move(obj));
                
                //Once this filling step is done at each station, this function checks if there is a customer order to be released at each station on the line in the order in which the user has specified.
                
                os << "--> " << incomplete.back().getProductName() << " moved from " << station[cnt]-> getName() << " to ";
                
                if (incomplete.back().isFilled()) {
                    os << "Complete Set" << std::endl;
                    complete.push_front(std::move(incomplete.back()));
                    incomplete.pop_back();
                }
                else if (cnt < count) {
                    os << station[cnt+1]->getName() << std::endl;
                }
                else {
                    os << "Incomplete Set" << std::endl;
                }
            }
        }
        
        //This function returns true if all the orders have been processed; false otherwise.
        cnt++;
        if (cnt == count+1) {
            return true;
        }
        return false;
    }
}
