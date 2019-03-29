// Assembly Line Project
// Edward Vuong
// 120246186
// Section SEE
// 2019/03/08

#ifndef SICT_ASSEMBLY_LINE_H
#define SICT_ASSEMBLY_LINE_H

#include <iostream>
#include <vector>
#include "ItemSet.h"

namespace sict {
    class AssemblyLine {
        std::vector<ItemSet> inventory;
        const char* fInventory{ nullptr };
    public:
        AssemblyLine(char* filename[], int nfiles);
        void loadInventory(std::ostream& os);
    };
}
#endif