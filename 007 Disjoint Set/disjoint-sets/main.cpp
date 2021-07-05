#include "disjoint_set.h"

int main(int argc, char* argv[]) {
    DisjointSet disjointSet(7);
    std::cout << disjointSet.getNumberOfComponents() << std::endl;

    /* perform few union operations */
    disjointSet.unionMethod(3, 4);
    std::cout << disjointSet.getNumberOfComponents() << std::endl;
    disjointSet.unionMethod(4, 5);
    std::cout << disjointSet.getNumberOfComponents() << std::endl;
    disjointSet.unionMethod(3, 5);
    std::cout << disjointSet.getNumberOfComponents() << std::endl;

    /* perform find operation */
    std::cout << std::boolalpha << disjointSet.findMethod(3, 5) << std::endl;

    /* get size of component which consist of specified object */
    std::cout << disjointSet.getComponentSize(3) << std::endl;

    /* perform few union operations */
    disjointSet.unionMethod(2, 0);
    disjointSet.unionMethod(0, 1);
    std::cout << disjointSet.getNumberOfComponents() << std::endl;

    /* perform find operation */
    std::cout << std::boolalpha << disjointSet.findMethod(0, 5) << std::endl;

    /* get number of objects */
    std::cout << disjointSet.getNumberOfObjects() << std::endl;

    return 0;
}