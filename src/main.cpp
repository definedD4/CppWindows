#include "cw/st/Area.h"
#include "cw/ut/AreaTreeUtils.h"

using namespace cw;
using namespace cw::ut;
using namespace cw::st;

Area* generateDemoArea(){
    Area* root = new Area(nullptr);
    Area* node1 = new Area(root);
    node1->setPos(Point(100, 0));
    Area* node11 = new Area(node1);
    Area* leaf111 = new Area(node11);
    Area* leaf112 = new Area(node11);
    Area* node12 = new Area(node1);
    node12->setPos(Point(30, 0));
    Area* leaf121 = new Area(node12);
    Area* node2 = new Area(root);
    Area* leaf21 = new Area(node2);
    Area* leaf22 = new Area(node2);

    return root;
}

int main(int argc, char* argv[]){
    Area* root = generateDemoArea();

    cw::ut::printAreaTree(root, 0);

    delete root;
}
