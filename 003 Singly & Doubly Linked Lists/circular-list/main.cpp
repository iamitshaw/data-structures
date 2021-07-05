#include "circular-list.h"

int main(int argc, char* argv[]) {
    CircularLinkedList<ssize_t> linkedList;
    linkedList.addElementAtTail(-45);
    linkedList.addElementAtHead(-90);
    CircularLinkedList<ssize_t> second_list(linkedList.getHead());
    linkedList.printList();
    std::cout << "List Size: " << linkedList.linkedListSize() << std::endl;
    std::cout << "List Size: " << linkedList.getSizeOfList() << std::endl;
    linkedList.deleteList();
    linkedList.printList();
    std::cout << "List Size: " << linkedList.getSizeOfList() << std::endl;
    second_list.printList();

    auto* object = new Object<ssize_t>(-75);
    auto* node = new Node<ssize_t>(object);
    second_list.addElementAtHead(node);
    node->setData(-85);
    std::cout << "Object: " << node->getObject()->getData() << std::endl;
    auto* obj = new Object<ssize_t>(-65);
    node->setObject(obj);
    second_list.printList();
    second_list.deleteList();
    second_list.printList();

    CircularLinkedList<std::string> third_list;
    third_list.addElementAtHead("Amit");
    third_list.addElementAtTail("Sumit");
    third_list.addElementAtHead("Ajit");
    third_list.insertElementAt("Ranjit", 2);
    third_list.printList();

    third_list.deleteElement("Ajeet");
    third_list.printList();

    std::string name{"Ajit"};
    auto* nodePointer = third_list.searchList(name);
    if (nodePointer) {
        std::cout << "\""<< name ;
        std::cout << "\" exist in circular-linked-list!" << std::endl;
    } else {
        std::cout << "\""<< name ;
        std::cout << "\" doesn't exist in circular-linked-list!" << std::endl;
    }

    third_list.deleteNodeFromHead();
    third_list.printList();

    third_list.deleteNodeFromTail();
    third_list.printList();

    third_list.deleteElement("Amit");
    third_list.deleteNodeAt(1);
    third_list.printList();

    third_list.deleteList();
    third_list.printList();

    return 0;
}