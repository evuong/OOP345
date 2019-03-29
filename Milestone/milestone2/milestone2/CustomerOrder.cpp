// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#include "CustomerOrder.h"

namespace sict {
    unsigned int CustomerOrder::field_width;
    CustomerOrder::CustomerOrder() : customer{""}, product{""}, items{nullptr}, count{0} {}
    
    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities obj;
        size_t delimit = 0;
        count = std::count(str.begin(), str.end(), obj.getDelimiter()) - 1;  //count # of items in str
        
        //The first extracted token holds the customer’s name. The second token holds the name of the product being assembled.
        customer = obj.extractToken(str, delimit);
        product = obj.extractToken(str, delimit);
        
        if (delimit != std::string::npos && delimit < str.length()) {
            items = new ItemInfo*[count];
            
            //The remaining tokens hold the names of the items to be added to the product throughout the assembly process.
            for (size_t i = 0; i < count; i++)
                items[i] = new ItemInfo(obj.extractToken(str, delimit));
        }
        else
            throw "No items have been requested to be added; that is, there are less than 3 token in the string";
        
        //This constructor determines the field width to be used in displaying customer names for all orders managed by this class.
        if (customer.length() > field_width)
            field_width = static_cast<int>(customer.length()+1);
    }
    
    //• A destructor that deallocates any memory that the object has allocated.
    CustomerOrder::~CustomerOrder() {
        delete[] items;
        items = nullptr;
    }
    
    void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
        for (size_t i = 0; i < count; i++) {
            if (item.getName() == items[i]->name) {
                if (item.getQuantity() > 0 && !items[i]->filled) {
                    items[i]->serial_num = item.getSerialNumber();
                    items[i]->filled = true;
                    os << "Filled " << this->getProductName() << "[" << items[i]->name << "][" << items[i]->serial_num << "]\n";
                     --item;    //and decrements the item stock by one
                }
                else if (items[i]->filled) {    //If the item request has already been filled
                    os << "Unable to fill " << this->getProductName() << "[" << items[i]->name << "][" << items[i]->serial_num << "] already filled\n";
                }
                else if (item.getQuantity() == 0) {     //or if the item is out of stock
                    os << "Unable to fill " << this->getProductName() << "[" << items[i]->name << "][" << items[i]->serial_num << "] out of stock\n";
                }
            }
        }
    }
    
    //a query that searches the list of items requested and returns true if all have been filled; false otherwise.
    bool CustomerOrder::isFilled() const {  //
        bool check = true;
        for (size_t i = 0; i < count; i++) {
            if (!items[i]->filled)
                check = false;
        }
        return check;
    }
    
    //a query that receives the name of an item, search the item request list for that item and returns true if all requests for that item have been filled; false, otherwise. If the item is not in the request list, this function returns true.
    bool CustomerOrder::isItemFilled(const std::string& item) const {
        bool check = true;
        for (size_t i = 0; i < count; i++) {
            if (items[i]->name == item && !items[i]->filled) {
                check = false;
            }
        }
        return check;
    }
    
    //a query that returns the name of the customer and their product
    std::string CustomerOrder::getProductName() const {
        return customer + "[" + product + "]";
    }
    
    void CustomerOrder::display(std::ostream& os, bool showDetail) const {
        
        //If the Boolean is false the data consists of the name of the customer, the product being assembled, and the list of items on the order.
        if (!showDetail) {
            os << std::setw(field_width) << customer << "[" << product << "]\n";
            
            for (size_t i = 0; i < count; i++) {
                os << std::setw(field_width) << " " << items[i]->name << std::endl;
            }
        }
        
        //Otherwise, the data consists of the name of the customer, the product being assembled, and the list of items with detail information on the order.
        if (showDetail) {
            os << std::setw(field_width) << customer << "[" << product << "]\n";
            
            for (size_t i = 0; i < count; i++) {
                os << std::setw(field_width) << " "
                << "[" << items[i]->serial_num << "] "
                << items[i]->name << " – ";
                
                if (items[i]->filled) os << "filled";
                else os << "not filled";
                
                os << std::endl;
            }
        }
    }
    
    CustomerOrder::CustomerOrder(CustomerOrder&& co) {
        *this = std::move(co);
    }
    
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) {
        if (this != &co) {
            
            customer = co.customer;
            product = co.product;
            items = co.items;
            count = co.count;
            
            co.customer = "";
            co.product = "";
            co.items = nullptr;
            co.count = 0;
        }
        return *this;
    }
}
