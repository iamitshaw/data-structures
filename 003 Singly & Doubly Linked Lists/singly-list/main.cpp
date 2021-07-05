#include "singly-list.h"

int main() {
    SinglyLinkedList<size_t> singlyLinkedList;
    auto* object = new Object<size_t>(20);

    singlyLinkedList.addElementAtHead(new Node<size_t>(object));
    singlyLinkedList.addElementAtHead(new Node<size_t>(45));
    singlyLinkedList.addElementAtTail(new Node<size_t>(33));
    singlyLinkedList.addElementAtHead(new Node<size_t>(89));
    singlyLinkedList.addElementAtTail(new Node<size_t>(16));
    singlyLinkedList.addElementAtTail(new Node<size_t>(91));
    singlyLinkedList.addElementAtHead(new Node<size_t>(38));

    Node<size_t>* node = singlyLinkedList.searchList(78);
    Node<size_t>* node_ = singlyLinkedList.searchLinkedList(33);
    if (node) {
        std::cout << node->getData() << std::endl;
    } else {
        std::cout << "element isn't found!" << std::endl;
    }
    if (node_) {
        std::cout << node_->getData() << std::endl;
    } else {
        std::cout << "element isn't found!" << std::endl;
    }


    singlyLinkedList.printList();
    singlyLinkedList.deleteElement(40);
    singlyLinkedList.deleteElement(45);
    singlyLinkedList.printList();

    singlyLinkedList.reverseListDisplay();
    singlyLinkedList.deleteElement(50);
    singlyLinkedList.printList();

    singlyLinkedList.deleteNodeFromHead();
    singlyLinkedList.deleteNodeFromTail();
    singlyLinkedList.printList();

    singlyLinkedList.deleteNodeFromHead();
    singlyLinkedList.deleteNodeFromTail();

    singlyLinkedList.deleteNodeFromHead();
    singlyLinkedList.deleteNodeFromTail();

    singlyLinkedList.printList();
    singlyLinkedList.addElementAtHead(45);
    singlyLinkedList.addElementAtHead(55);
    singlyLinkedList.addElementAtHead(65);
    singlyLinkedList.addElementAtHead(75);
    singlyLinkedList.addElementAtHead(85);
    singlyLinkedList.printList();
    std::cout << "Length of List: " << singlyLinkedList.getLinkedListLength() << std::endl;
    singlyLinkedList.reverseListDisplay();
    singlyLinkedList.deleteList();

    std::cout << "Length of List: " << singlyLinkedList.getLinkedListLength() << std::endl;
    singlyLinkedList.printList();

    singlyLinkedList.addElementAtHead(new Node<size_t>(60));
    singlyLinkedList.addElementAtTail(new Node<size_t>(70));
    singlyLinkedList.addElementAtHead(new Node<size_t>(80));
    singlyLinkedList.addElementAtTail(new Node<size_t>(90));
    singlyLinkedList.addElementAtHead(76);
    singlyLinkedList.addElementAtTail(67);

    SinglyLinkedList<size_t> linkedList(singlyLinkedList.getHead());

    std::cout << "first linked-list: " << std::endl;
    singlyLinkedList.printList();

    std::cout << "second linked list: " << std::endl;
    linkedList.printList();

    singlyLinkedList.deleteList();
    singlyLinkedList.printList();

    std::cout << "Head: " << singlyLinkedList.getHead() << std::endl;
    std::cout << "Size Of List: " << singlyLinkedList.getListSize() << std::endl;

    auto* node_t = new Node<size_t>(object);
    node_t->setObject(object);
    size_t data{38};
    node_t->setData(data);
    std::cout << node_t->getObject()->getData() << std::endl;

    return 0;
}