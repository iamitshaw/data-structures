#include "queue.h"

int main(int argc, char* argv[]) {
    Queue<size_t> queue01;
    queue01.EnQueue(34);
    queue01.EnQueue(44);
    queue01.EnQueue(54);
    queue01.EnQueue(64);
    queue01.EnQueue(74);
    queue01.EnQueue(84);

    queue01.displayQueue();
    queue01.displayQueue();

    std::cout << "Queue Size: " << queue01.getQueueSize() << std::endl;

    Queue<std::string> queue02;
    std::cout << "Queue Size: " << queue02.getQueueSize() << std::endl;

    queue02.EnQueue(new Node<std::string>("michael"));
    queue02.EnQueue(new Node<std::string>("john"));
    queue02.EnQueue(new Node<std::string>("bob"));
    queue02.EnQueue(new Node<std::string>("sam"));
    queue02.EnQueue(new Node<std::string>("alice"));
    queue02.EnQueue(new Node<std::string>("peter"));
    queue02.displayQueue();
    queue02.deQueue();
    queue02.deQueue();
    queue02.deQueue();
    queue02.displayQueue();
    std::cout << "Front Element: "  << queue02.getFrontElement() << std::endl;
    std::cout << "Rear Element: "  << queue02.getRearElement() << std::endl;
    std::cout << "Queue Size: " << queue02.getQueueSize() << std::endl;

    queue02.deleteQueue();
    return 0;
}