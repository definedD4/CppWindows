//
// Created by Dima on 28.05.2016.
//

#ifndef CPPWINDOWS_AREATREEUTILS_H
#define CPPWINDOWS_AREATREEUTILS_H

#include <iostream>
#include "../st/Area.h"

namespace cw {
    namespace ut{

        void printAreaTree(st::Area* area, int indent){
            for(int i = 0; i < indent; ++i)
                std::cout << "| ";

            if(area->isNode())
                std::cout << "Node";
            else if(area->isLeaf())
                std::cout << "Leaf";
            else if(area->isRoot())
                std::cout << "Root";

            std::cout << " Size: " << area->getSize() << " Pos: " << area->getPos()
                << " Global pos: " << area->getGlobalPos() << "\n";

            for(st::Area* child : area->getChildren()){
                printAreaTree(child, indent + 1);
            }
        }

    }
}

#endif //CPPWINDOWS_AREATREEUTILS_H
