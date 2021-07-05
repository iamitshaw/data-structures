
/* Include Guard */

#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "node.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    size_t size_of_list;
public:
    DoublyLinkedList();
    explicit DoublyLinkedList(Node<T>* nodePointer);
    Node<T>* getHead();
    size_t getSizeOfList();
    ~DoublyLinkedList();
    void deleteList();
    size_t linkedListSize();
    void printList();
    void addElementAtHead(Node<T>* nodePointer);
    void addElementAtHead(T data);
    void addElementAtTail(Node<T>* nodePointer);
    void addElementAtTail(T data);
    void insertElementAt(Node<T>* nodePointer, size_t position);
    void insertElementAt(T data, size_t position);
    void deleteNodeFromHead();
    void deleteNodeFromTail();
    void deleteNodeAt(size_t position);

};

/* default constructor */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
        : head{nullptr}, size_of_list{0} {

}

/* overloaded constructor */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* nodePointer)
        : head{nullptr}, size_of_list{0} {
    if (nodePointer) {

        /* since, doubly-linked-list hasn't node attached */
        auto* tempNodePointer = new Node<T>(nodePointer->getData());

        /* field initialization */
        this->head = tempNodePointer;
        this->size_of_list += 1;

        Node<T>* tailNodePointer {tempNodePointer};

        /* move to next node */
        nodePointer = nodePointer->getNext();

        /* now, head of the linked-list is set */
        while (nodePointer) {
            this->size_of_list += 1;
            tempNodePointer = new Node<T>(nodePointer->getData());

            tailNodePointer->setNext(tempNodePointer);
            tempNodePointer->setPrev(tailNodePointer);

            /* update the tail node pointer */
            tailNodePointer = tailNodePointer->getNext();

            /* move to next node */
            nodePointer = nodePointer->getNext();
        }
    }
}

/* getter */
template<typename T>
Node<T> *DoublyLinkedList<T>::getHead() {
    return DoublyLinkedList::head;
}

template<typename T>
size_t DoublyLinkedList<T>::getSizeOfList() {
    return DoublyLinkedList::size_of_list;
}

/* destructor */
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DoublyLinkedList::deleteList();
}

/* delete doubly-linked-list */
template<typename T>
void DoublyLinkedList<T>::deleteList() {
    Node<T>* tempNodePointer{this->getHead()};

    while (tempNodePointer) {
        this->head = tempNodePointer->getNext();

        /* if head attribute has an address
         * of a doubly-linked-list node */
        if (this->getHead()) {
            this->head->setPrev(nullptr);
        }

        /* de-attach the nodeToBeDeleted */
        tempNodePointer->setNext(nullptr);

        /* de-allocate the heap memory */
        delete tempNodePointer;

        /* move to next doubly-linked-list node */
        tempNodePointer = this->getHead();

        /* decrease the size of doubly-linked-list */
        this->size_of_list -= 1;
    }
}

/* length of doubly-linked-list */
template<typename T>
size_t DoublyLinkedList<T>::linkedListSize() {
    Node<T>* tempNodePointer {this->getHead()};
    size_t countOfNode{0};

    /* navigate through doubly-linked-list */
    while (tempNodePointer) {
        countOfNode += 1;
        tempNodePointer = tempNodePointer->getNext();
    }

    /* return the number of nodes
     * in the doubly-linked-list */
    return countOfNode;
}

/* display doubly-linked-list */
template<typename T>
void DoublyLinkedList<T>::printList() {
    Node<T>* tempNodePointer{this->getHead()};

    /* navigate through doubly-linked-list */
    while (tempNodePointer) {
        std::cout << tempNodePointer->getData() << " ";
        tempNodePointer = tempNodePointer->getNext();
    }

    /* traverse the cursor to
     * the start of next line */
    std::cout << std::endl;
}

/* add element */
template<typename T>
void DoublyLinkedList<T>::addElementAtHead(Node<T> *nodePointer) {
    insertElementAt(nodePointer, 1);
}

template<typename T>
void DoublyLinkedList<T>::addElementAtHead(T data) {
    /* node creation from given data */
    auto* nodePointer = new Node<T>(data);

    addElementAtHead(nodePointer);
}

template<typename T>
void DoublyLinkedList<T>::addElementAtTail(Node<T> *nodePointer) {
    insertElementAt(nodePointer, this->getSizeOfList()+1);
}

template<typename T>
void DoublyLinkedList<T>::addElementAtTail(T data) {
    /* node creation from given data */
    auto* nodePointer = new Node<T>(data);

    addElementAtTail(nodePointer);
}

template<typename T>
void DoublyLinkedList<T>::insertElementAt(T data, size_t position) {
    /* node creation from given data */
    auto* nodePointer = new Node<T>(data);

    insertElementAt(nodePointer, position);
}

template<typename T>
void DoublyLinkedList<T>::insertElementAt(Node<T> *nodePointer, size_t position) {
    if(position >= 1 && position <= (this->size_of_list + 1)){

        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->getHead()};

        if(position == 1){
            /* head pointer variable will get modified
             * if insertion get performed at first node */
            nodePointer->setNext(tempNodePointer);

            /* if tempNodePointer is pointing to some node */
            if (tempNodePointer) {
                tempNodePointer->setPrev(nodePointer);
            }
            this->head = nodePointer;
        } else {
            size_t countOfNode{1};

            /* navigate through the required position */
            while(countOfNode < (position - 1)){
                tempNodePointer = tempNodePointer->getNext();
                countOfNode++;
            }

            /* set newNode's pointer field */
            nodePointer->setNext(tempNodePointer->getNext());
            nodePointer->setPrev(tempNodePointer);

            Node<T>* nextOfTempNodePointer{tempNodePointer->getNext()};

            /* if nextOfTempNodePointer is pointing
             * to some node in doubly-linked-list */
            if (nextOfTempNodePointer) {
                nextOfTempNodePointer->setPrev(nodePointer);
            }

            tempNodePointer->setNext(nodePointer);
        }

        /* increase the size_of_list */
        this->size_of_list += 1;
    } else {
        std::cout << "insertion can't be performed!" << std::endl;
    }
}

/* delete element */
template<typename T>
void DoublyLinkedList<T>::deleteNodeFromHead() {
    deleteNodeAt(1);
}

template<typename T>
void DoublyLinkedList<T>::deleteNodeFromTail() {
    deleteNodeAt(this->getSizeOfList());
}

template<typename T>
void DoublyLinkedList<T>::deleteNodeAt(size_t position) {

    /* deletion can be performed only when
    * their exist node at that position */
    if(position >= 1 && position <= this->size_of_list){
        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->getHead()};

        if(position == 1){
            /* head pointer variable will get modified if
             * first node of linked list is being deleted */
            this->head = tempNodePointer->getNext();

            /* if tempNodePointer is pointing to some node */
            if (this->getHead()) {
                this->head->setPrev(nullptr);
            }

            tempNodePointer->setNext(nullptr);

            /* de-allocate the heap memory */
            delete tempNodePointer;
        } else {
            size_t countOfNode = 1;

            /* for deleting position-th node, access to
             * (position - 1)-th node has to obtained */
            while(countOfNode < (position - 1)){
                tempNodePointer = tempNodePointer->getNext();
                countOfNode += 1;
            }

            /* declare a node pointer that will point to deleted node */
            Node<T>* nodeToBeDeleted{tempNodePointer->getNext()};

            /* detach the node to be deleted from list */
            tempNodePointer->setNext(nodeToBeDeleted->getNext());

            /* if nextOfTempNodePointer is pointing
             * to some node in doubly-linked-list */
            if (nodeToBeDeleted->getNext()) {
                nodeToBeDeleted->getNext()->setPrev(tempNodePointer);
            }

            /* de-attach nodeToBeDeleted from doubly-linked-list */
            nodeToBeDeleted->setNext(nullptr);
            nodeToBeDeleted->setPrev(nullptr);

            /* de-allocate the heap memory */
            delete nodeToBeDeleted;
        }

        /* decrease the size_of_list */
        this->size_of_list -= 1 ;

    } else {
        std::cout << "deletion can't be performed!" << std::endl;
    }
}

#endif