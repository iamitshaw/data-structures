#include "stack.h"

int main(int argc, char* argv[]) {
    Stack<std::string> stack01(5);
    stack01.pushElement("john");
    stack01.pushElement("jack");
    stack01.pushElement("jill");

    stack01.deleteStack();
    stack01.pushElement("joey");
    stack01.pushElement("joseph");
    stack01.pushElement("jessy");

    stack01.displayStack();

    std::cout << "Stack Capacity: " << stack01.getCapacity() << std::endl;
    std::cout << "Stack Size: " << stack01.getStackSize() << std::endl;
    std::cout << "Top Index: " << stack01.getTop() << std::endl;
    std::cout << "Top Element: " << stack01.getTopElement() << std::endl;

    stack01.popElement();
    stack01.popElement();

    return 0;
}