#include "queue.h"

int main(int argc, char* argv[]) {
    Queue<std::string> queue01(2);
    queue01.enQueue("john");
    queue01.enQueue("michael");
    queue01.enQueue("bob");
    queue01.enQueue("alice");
    queue01.enQueue("samuel");
    queue01.displayQueue();
    queue01.deleteQueue();

    std::cout << "Queue Size: " << queue01.getQueueSize() << std::endl;
    std::cout << "Queue Capacity: " << queue01.getCapacity() << std::endl;

    Queue<size_t> queue02;
    queue02.enQueue(56);
    queue02.enQueue(78);
    std::cout << "Queue Capacity: " << queue02.getCapacity() << std::endl;
    queue02.deQueue();
    std::cout << "Queue Capacity: " << queue02.getCapacity() << std::endl;

    std::cout << "Front Element: " << queue02.getFrontElement() << std::endl;
    std::cout << "Rear Element: " << queue02.getRearElement() << std::endl;
    for (size_t i{0};i < queue02.getQueueSize();i++) {
        queue02.displayQueue();
        queue02.deQueue();
        std::cout << "Front Index: " << queue02.getFront() << std::endl;
        std::cout << "Rear Index: " << queue02.getRear() << std::endl;
    }

    std::cout << std::boolalpha ;
    std::cout << "is queue empty? " << queue02.isEmptyQueue() << std::endl;
    return 0;
}