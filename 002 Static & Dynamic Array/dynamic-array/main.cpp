#include "dynamic-array.h"

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    DynamicArray<int32_t> dynamicArray(8);
    std::cout << dynamicArray.getCapacity() << std::endl;
    std::cout << dynamicArray.getArraySize() << std::endl;
    dynamicArray.add(-89);
    dynamicArray.add(98);
    dynamicArray.add(9);
    dynamicArray.add(-7);
    dynamicArray.display_array();

    dynamicArray.remove(98);
    dynamicArray.display_array();

    dynamicArray.clear();
    dynamicArray.display_array();

    std::cout << std::boolalpha << dynamicArray.isEmpty() << std::endl;

    dynamicArray.add(32);
    dynamicArray.add(-15);
    dynamicArray.add(5);
    dynamicArray.add(86);
    dynamicArray.add(12);
    dynamicArray.add(15);
    dynamicArray.add(2);
    dynamicArray.add(20);
    dynamicArray.add(75);
    dynamicArray.display_array();
    std::cout << std::boolalpha << dynamicArray.contains(5) << std::endl;
    std::cout << std::boolalpha << dynamicArray.contains(-5) << std::endl;
    std::cout << dynamicArray.getCapacity() << std::endl;
    std::cout << dynamicArray.getArraySize() << std::endl;
    return 0;
}