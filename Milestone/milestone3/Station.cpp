// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08


#include "Station.h"

namespace sict {
    
    //passes that reference to the ItemSet sub-object of the current object.
    Station::Station(const std::string& name) {
        item = new ItemSet(name);
    }
    
    void Station::display(std::ostream& os) const {
        item->display(os, true);
    }
    
    void Station::fill(std::ostream& os) {
        if (queue.size() != 0) {
            if (!queue.back().isItemFilled(getName())) {
                queue.back().fillItem(*item, os);
            }
        }
    }
    
    const std::string& Station::getName() const {
        return item->getName();
    }
    
    //a query that returns the release state of the current object. This function returns true if the station has filled the item request(s) for the customer order at the front of the queue or the station has no items left; otherwise, it returns false.
    
    bool Station::hasAnOrderToRelease() const {
        
        //If there are no orders in the queue, this function returns false.
        if (queue.size() == 0) {
            return false;
        }
        else if (queue.front().isFilled() || item->getQuantity() == 0) {
            return true;
        }
        else return false;
    }
    
    // a modifier that decrements the number of items in the ItemSet, increments the serial number for the next item, and returns a reference to the current object.
    Station& Station::operator--() {
        item->operator--();
        return *this;
    }
    
    Station& Station::operator+=(CustomerOrder&& order) {
        //moves that order to the back of the station’s queue and returns a reference to the current object.
        queue.push_back(std::move(order));
        return *this;
    }
    
    bool Station::pop(CustomerOrder& ready) {
        //If there are no orders in the queue, this function returns false.
        if (queue.size() == 0) {
            return false;
        }
         //removes the order at the front of the queue and moves it to the calling function through the parameter list
        else {
            ready = std::move(queue.front());
            queue.pop_front();
            return true;
        }
    }
    
    void Station::validate(std::ostream& os) const {
        os << "getName(): " << item->getName() << std::endl;
        os << "getSerialNumber(): " << item->getSerialNumber() << std::endl;
        os << "getQuantity(): " << item->getQuantity() << std::endl;
    }
}
