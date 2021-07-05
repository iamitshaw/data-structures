#include "unsorted-array.h"

int32_t main(int32_t argc, char* argv[]) {
    int32_t array_size{6};
    UnsortedArray<int32_t> unsortedArray(array_size);

    unsortedArray.insertElement(45);
    unsortedArray.insertElement(56);
    unsortedArray.insertElement(73);
    unsortedArray.displayElement();

    unsortedArray.deleteElement(56);
    unsortedArray.displayElement();

    std::cout << "Capacity: " << unsortedArray.getCapacity() << std::endl;
    std::cout << "Number of Element: " << unsortedArray.getNumberOfElement() << std::endl;

    std::cout << "Array elements: " << std::endl;
    for (int32_t i{0};i < unsortedArray.getNumberOfElement();i++) {
        std::cout << unsortedArray.elementAt(i) << " ";
    }std::cout << std::endl;

    unsortedArray.insertElement(12);
    unsortedArray.insertElement(32);
    unsortedArray.insertElement(58);

    unsortedArray.displayElement();
    return 0;
}