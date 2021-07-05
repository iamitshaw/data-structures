#include "doubly-list.h"

int32_t main(int32_t argc,char* argv[]) {
    DoublyLinkedList<ssize_t> doublyLinkedList;
    doublyLinkedList.addElementAtHead(45);
    doublyLinkedList.addElementAtTail(-45);
    doublyLinkedList.addElementAtHead(67);
    doublyLinkedList.addElementAtTail(-67);
    doublyLinkedList.addElementAtHead(52);
    doublyLinkedList.addElementAtTail(-52);
    doublyLinkedList.printList();

    doublyLinkedList.insertElementAt(-62, 4);
    std::cout << "Length: " << doublyLinkedList.linkedListSize() << std::endl;

    DoublyLinkedList<ssize_t> second_list(doublyLinkedList.getHead());
    second_list.printList();

    second_list.deleteNodeFromHead();
    second_list.printList();

    second_list.deleteNodeFromTail();
    second_list.printList();

    second_list.deleteNodeAt(2);
    second_list.printList();

    second_list.deleteNodeFromHead();
    second_list.deleteNodeFromHead();
    second_list.printList();

    second_list.deleteNodeFromHead();
    second_list.deleteNodeFromHead();
    second_list.printList();

    second_list.deleteNodeFromHead();
    second_list.deleteNodeFromTail();

    doublyLinkedList.deleteList();
    doublyLinkedList.printList();

    return 0;
}