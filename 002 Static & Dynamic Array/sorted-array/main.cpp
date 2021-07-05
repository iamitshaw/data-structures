#include "sorted-array.h"

int32_t main(int32_t argc, char* argv[]) {
    int32_t array_size{6};
    SortedArray<int32_t> sortedArray(array_size);

    sortedArray.insertElement(45);
    sortedArray.insertElement(56);
    sortedArray.insertElement(73);
    sortedArray.displayElement();

    sortedArray.deleteElement(56);
    sortedArray.displayElement();

    std::cout << "Capacity: " << sortedArray.getCapacity() << std::endl;
    std::cout << "Number of Element: " << sortedArray.getNumberOfElement() << std::endl;

    std::cout << "Array elements: " << std::endl;
    for (int32_t i{0}; i < sortedArray.getNumberOfElement(); i++) {
        std::cout << sortedArray.elementAt(i) << " ";
    }std::cout << std::endl;

    sortedArray.insertElement(12);
    sortedArray.insertElement(32);
    sortedArray.insertElement(58);
    sortedArray.insertElement(7);

    sortedArray.displayElement();
    return 0;
}