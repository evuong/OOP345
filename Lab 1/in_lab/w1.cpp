// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Edward Vuong 120246186
// evuong1@myseneca.ca
// OOP345 - SEE

#include <iostream>
#include <cstring>
#include "process.h"
#include "String.h"

using namespace std;
extern const int initial;

int main(int argc, const char * argv[]) {

    //if no arguments are being passed, run this code
    if (argc < 2) {
        cout << endl << "***Insufficient number of arguments***" << endl;
        return 1;
    }
    
    cout << "Command Line : ";
    
    //lists out the arguments
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << " ";
    }
    cout << endl;
    
    for (int i = 1; i < argc; i++) {
        sict::process(argv[i]);
    }
    
    return 0;
}
