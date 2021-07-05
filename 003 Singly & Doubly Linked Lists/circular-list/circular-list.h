
/* Include Guard */

#ifndef _CIRCULAR_LINKED_LIST_H_
#define _CIRCULAR_LINKED_LIST_H_

#include "node.h"

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    size_t size_of_list;
public:
    CircularLinkedList();
    explicit CircularLinkedList(Node<T>* headNodePointer);
    ~CircularLinkedList();
    Node<T> *getHead() const;
    size_t getSizeOfList() const;
    void deleteList();
    size_t linkedListSize();
    void printList();
    void addElementAtHead(Node<T>* nodePointer);
    void addElementAtHead(T data);
    void addElementAtTail(Node<T>* nodePointer);
    void addElementAtTail(T data);
    void insertElementAt(Node<T>* nodePointer, size_t position);
    void insertElementAt(T data, size_t position);
    Node<T>* getNthNode(ssize_t position);
    void deleteNodeFromHead();
    void deleteNodeFromTail();
    void deleteNodeAt(size_t position);
    void deleteElement(T keyValue);
    Node<T>* searchList(T keyValue);
};

/* default constructor */
template <typename T>
CircularLinkedList<T>::CircularLinkedList()
        : head{nullptr}, size_of_list{0} {

}

/* overloaded constructor */
template <typename T>
CircularLinkedList<T>::CircularLinkedList(Node<T>* headNodePointer)
        :head{nullptr}, size_of_list{0} {

    if (headNodePointer) {

        /* if their exist at-least single
         * node in circular-linked-list */
        auto* nodePointer {headNodePointer};

        /* since, head of the linked-list is pointing nowhere */
        auto* tempNodePointer = new Node<T>(nodePointer->getData());

        /* field initialization */
        this->head = tempNodePointer;
        this->size_of_list += 1;

        Node<T>* tailNodePointer {tempNodePointer};

        /* make circular-linked-list by pointing tail
         * node's next to head node of the linked-list */
        tailNodePointer->setNext(this->getHead());

        /* move to next node*/
        nodePointer = nodePointer->getNext();

        /* now, head of the linked-list is set */
        while (nodePointer != headNodePointer) {
            this->size_of_list += 1;
            tempNodePointer = new Node<T>(nodePointer->getData());

            tempNodePointer->setNext(this->getHead());
            tailNodePointer->setNext(tempNodePointer);

            /* update the tailNodePointer */
            tailNodePointer = tailNodePointer->getNext();

            /* move to next node */
            nodePointer = nodePointer->getNext();
        }
    }
}

/* destructor */
template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {

    /* set the initial node Pointer */
    Node<T>* initialNodePointer{this->getHead()};

    /* whether their exist nodes in circular-linked-list */
    if (initialNodePointer) {
        Node<T>* middleNodePointer{initialNodePointer->getNext()};

        /* check whether last node exist in circular-linked-list */
        if (initialNodePointer != middleNodePointer) {

            /* whether middle nodes exist in circular-linked-list */
            while (middleNodePointer->getNext() != this->getHead()) {

                /* de-attach the middleNodePointer */
                initialNodePointer->setNext(middleNodePointer->getNext());
                middleNodePointer->setNext(nullptr);

                /* de-allocate the heap memory */
                delete middleNodePointer;

                /* re-set the middleNodePointer */
                middleNodePointer = initialNodePointer->getNext();
            }

            /* de-attach the last node of list */
            initialNodePointer->setNext(initialNodePointer);
            middleNodePointer->setNext(nullptr);

            /* de-allocate the heap memory */
            delete middleNodePointer;
        }

        /* delete the first node in circular-linked-list */
        this->head = nullptr;
        initialNodePointer->setNext(nullptr);

        /* de-allocate the heap memory */
        delete initialNodePointer;
    }
}

/* getter */
template<typename T>
Node<T> *CircularLinkedList<T>::getHead() const {
    return CircularLinkedList::head;
}

/* setter */
template<typename T>
size_t CircularLinkedList<T>::getSizeOfList() const {
    return CircularLinkedList::size_of_list;
}

/* delete circular-linked-list */
template<typename T>
void CircularLinkedList<T>::deleteList() {

    /* set the initial node Pointer */
    Node<T>* initialNodePointer{this->getHead()};

    /* whether their exist nodes in circular-linked-list */
    if (initialNodePointer) {
        Node<T>* middleNodePointer{initialNodePointer->getNext()};

        /* check whether last node exist in circular-linked-list */
        if (initialNodePointer != middleNodePointer) {

            /* whether middle nodes exist in circular-linked-list */
            while (middleNodePointer->getNext() != this->getHead()) {

                /* de-attach the middleNodePointer */
                initialNodePointer->setNext(middleNodePointer->getNext());
                middleNodePointer->setNext(nullptr);

                /* de-allocate the heap memory */
                delete middleNodePointer;

                /* decrease the size of circular-linked-list */
                this->size_of_list -= 1;

                /* re-set the middleNodePointer */
                middleNodePointer = initialNodePointer->getNext();
            }

            /* de-attach the last node of list */
            initialNodePointer->setNext(initialNodePointer);
            middleNodePointer->setNext(nullptr);

            /* de-allocate the heap memory */
            delete middleNodePointer;

            /* decrease the size of circular-linked-list */
            this->size_of_list -= 1;
        }

        /* delete the first node in circular-linked-list */
        this->head = nullptr;
        initialNodePointer->setNext(nullptr);

        /* de-allocate the heap memory */
        delete initialNodePointer;

        this->size_of_list -= 1;
    }
}

/* length of circular-linked-list */
template <typename T>
size_t CircularLinkedList<T>::linkedListSize() {
    Node<T>* tempNodePointer{this->getHead()};

    /* initialize the count of
     * circular-linked-list node */
    size_t listSize{0};

    /* whether circular-linked-list have node */
    if (tempNodePointer) {
        listSize += 1;

        while (tempNodePointer->getNext() != this->getHead()) {

            /* traverse to next node */
            tempNodePointer = tempNodePointer->getNext();
            listSize += 1;
        }
    }

    return listSize;
}

template<typename T>
void CircularLinkedList<T>::printList() {
    Node<T>* tempNodePointer{this->getHead()};

    if (tempNodePointer) {
        std::cout << tempNodePointer->getData() << " ";

        while (tempNodePointer->getNext() != this->getHead()) {
            tempNodePointer = tempNodePointer->getNext();
            std::cout << tempNodePointer->getData() << " ";
        }
    }

    /* traverse the cursor to the next line */
    std::cout << std::endl;
}

/* add element */

template<typename T>
void CircularLinkedList<T>::addElementAtHead(Node<T> *nodePointer) {
    insertElementAt(nodePointer, 1);
}

template<typename T>
void CircularLinkedList<T>::addElementAtHead(T data) {
    /* node creation from the given data */
    auto* nodePointer = new Node<T>(data);

    addElementAtHead(nodePointer);
}

template<typename T>
void CircularLinkedList<T>::addElementAtTail(Node<T> *nodePointer) {
    insertElementAt(nodePointer, this->getSizeOfList() + 1);
}

template<typename T>
void CircularLinkedList<T>::addElementAtTail(T data) {
    /* node creation from the given data */
    auto* nodePointer = new Node<T>(data);

    addElementAtTail(nodePointer);
}

template <typename T>
void CircularLinkedList<T>::insertElementAt(T data, size_t position) {
    /* node creation from the given data */
    auto* nodePointer = new Node<T>(data);

    insertElementAt(nodePointer, position);
}

template<typename T>
void CircularLinkedList<T>::insertElementAt(Node<T> *nodePointer, size_t position) {
    if (position >= 1 && position <= this->getSizeOfList() + 1) {
        /* increase the size_of_list */
        this->size_of_list += 1;

        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->getHead()};

        if(position == 1){
            /* head pointer variable will get modified
             * if insertion get performed at first node */
            nodePointer->setNext(tempNodePointer);
            this->head = nodePointer;

            /* get the tailNodePointer */
            Node<T>* tailNodePointer{getNthNode(this->getSizeOfList())};

            /* set the tailNode such that it
             * starts pointing to headNode */
            tailNodePointer->setNext(nodePointer);

        } else {
            size_t countOfNode = 1;

            /* navigate through the required position */
            while(countOfNode < (position - 1)){
                tempNodePointer = tempNodePointer->getNext();
                countOfNode++;
            }

            nodePointer->setNext(tempNodePointer->getNext());
            tempNodePointer->setNext(nodePointer);
        }
    } else {
        std::cout << "insertion can't be performed!" << std::endl;
    }
}

template<typename T>
Node<T> *CircularLinkedList<T>::getNthNode(ssize_t position) {
    if (position >= 1 && position <= this->getSizeOfList()) {
        size_t countOfNode{1};
        Node<T>* nodePointer{this->getHead()};

        while (countOfNode < position) {
            nodePointer = nodePointer->getNext();
            countOfNode += 1;
        }

        return nodePointer;
    } else {
        /* no such position exist in the circular-linked-list */
        std::cout << "invalid node position!" << std::endl;
    }
    return nullptr;
}

template<typename T>
void CircularLinkedList<T>::deleteNodeFromHead() {
    deleteNodeAt(1);
}

template<typename T>
void CircularLinkedList<T>::deleteNodeFromTail() {
    deleteNodeAt(this->getSizeOfList());
}

template<typename T>
void CircularLinkedList<T>::deleteNodeAt(size_t position) {
    /* deletion can be performed only when
     * their exist node at that position */
    if(position >= 1 && position <= this->size_of_list){

        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->getHead()};

        if(position == 1){
            if (this->size_of_list > 1) {
                /* get tailNodePointer of circular-linked-list */
                Node<T>* tailNodePointer{this->getNthNode(this->getSizeOfList())};

                /* head pointer variable will get modified if
                 * first node of linked list is being deleted */
                this->head = tempNodePointer->getNext();

                /* update the tailNode's pointer such that it
                 * point to headNode of circular-linked-list */
                tailNodePointer->setNext(this->getHead());

                /* de-attach the nodeToBeDeleted */
                tempNodePointer->setNext(nullptr);

            } else {
                /* if circular-linked-list has exactly single node */
                this->head = {nullptr};
                tempNodePointer->setNext(nullptr);
            }

            /* de-allocate the heap memory */
            delete tempNodePointer;

        } else {
            size_t countOfNode{1};

            /* for deleting position-th node, access to
             * (position - 1)-th node has to obtained */
            while(countOfNode < (position - 1)){
                tempNodePointer = tempNodePointer->getNext();
                countOfNode++;
            }

            /* declare a node pointer that will point to deleted node */
            Node<T>* nodeToBeDeleted{tempNodePointer->getNext()};

            /* detach the node to be deleted from list */
            tempNodePointer->setNext(nodeToBeDeleted->getNext());
            nodeToBeDeleted->setNext(nullptr);

            /* de-allocate the heap memory */
            delete nodeToBeDeleted;
        }

        /* decrease the size_of_list */
        this->size_of_list -= 1 ;

    } else {
        std::cout << "deletion can't be performed!" << std::endl;
    }
}

/* delete first occurrence of this
 * keyValue from the linked-list */
template<typename T>
void CircularLinkedList<T>::deleteElement(T keyValue) {
    if (this -> getSizeOfList() >= 1) {
        Node<T> *tempNodePointer{this->getHead()};
        Node<T> *previousNode{tempNodePointer};

        /* is_found is an indicator for presence
         * of keyValue in circular-linked-list */
        bool is_found{false};

        /* navigate through the list */
        do {
            /* if keyValue is found then further
             * traversal of list isn't required */
            if (tempNodePointer->getData() == keyValue) {
                is_found = {true};
                break;
            } else {
                previousNode = tempNodePointer;
                tempNodePointer = tempNodePointer->getNext();
            }
        } while (tempNodePointer != this->getHead());

        /* if keyValue has been found */
        if (is_found) {

            /* if first occurrence of keyValue is
             * the first node of the linked-list */
            if (tempNodePointer == this->getHead()) {

                if (this->getSizeOfList() > 1) {
                    /* get tailNodePointer */
                    Node<T>* tailNodePointer{this->getNthNode(this->getSizeOfList())};

                    /* detach the first node from linked-list */
                    this->head = tempNodePointer->getNext();
                    tempNodePointer->setNext(nullptr);

                    /* update the tailNode's pointer such that it
                     * point to headNode of circular-linked-list */
                    tailNodePointer->setNext(this->getHead());
                } else {
                    this->head = nullptr;
                    tempNodePointer->setNext(nullptr);
                }

            } else {
                /* detach the node to be deleted from list */
                previousNode->setNext(tempNodePointer->getNext());
                tempNodePointer->setNext(nullptr);

            }

            /* decrease the list size */
            this->size_of_list -= 1;

            /* de-allocate the heap-memory */
            delete tempNodePointer;

        } else {
            /* if element isn't found in the list */
            std::cout << "element isn't found!" << std::endl;
        }
    } else {
        /* when circular linked list hasn't any node */
        std::cout << "circular linked list is empty!" << std::endl;
    }
}

template<typename T>
Node<T> *CircularLinkedList<T>::searchList(T keyValue) {
    /* search operation can be performed
     * only if linked list contain nodes */
    if(this->size_of_list >= 1) {
        Node<T>* tempNodePointer{this->head};

        /* navigate through the list nodes */
        do {
            /* if keyValue is found inside the list
             * then no further traversal is required */
            if(tempNodePointer->getData() == keyValue) {
                return tempNodePointer;
            } else {
                tempNodePointer = tempNodePointer->getNext();
            }
        } while(tempNodePointer != this->getHead());
    } else {

        /* nullptr is a sentinel used to indicate that
         * keyValue can't be found in an empty list */
        return nullptr;
    }

    /* nullptr is a sentinel used to indicate that keyValue
     * hasn't been found in the circular-linked-list */
    return nullptr;
}

#endif