
/* Include Guard */

#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

#include "node.h"

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    size_t size_of_list;
public:
    SinglyLinkedList();
    explicit SinglyLinkedList(Node<T>* nodePointer);
    Node<T>* getHead();
    size_t getListSize();
    size_t getLinkedListLength();
    size_t linkedListLength(Node<T>* nodePointer);
    void addElementAtHead(Node<T>* nodePointer);
    void addElementAtHead(T data);
    void addElementAtTail(Node<T>* nodePointer);
    void addElementAtTail(T data);
    void insertElementAt(Node<T>* nodePointer, size_t position);
    void printList();
    void deleteNodeFromHead();
    void deleteNodeFromTail();
    void deleteNodeAt(size_t position);
    void deleteList();
    void reverseListDisplay();
    void deleteElement(T keyValue);
    Node<T>* searchList(T keyValue);
    Node<T>* searchLinkedList(T keyValue);
    ~SinglyLinkedList();
private:
    void displayListInReverse(Node<T>* nodePointer);
    Node<T>* searchList(Node<T>* nodePointer, T keyValue);
};

/* default constructor */
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
        :head{nullptr}, size_of_list{0}{

}

/* create another linked list having
 * content same as specified list */
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(Node<T>* nodePointer)
        :head{nullptr}, size_of_list{0}{

    if (nodePointer) {
        /* since, head of the linked-list is pointing nowhere */
        auto* tempNodePointer = new Node<T>(nodePointer->getData());

        /* field initialization */
        this->head = tempNodePointer;
        this->size_of_list += 1;

        Node<T>* tailNodePointer {tempNodePointer};

        /* move to next node*/
        nodePointer = nodePointer->getNext();

        /* now, head of the linked-list is set */
        while (nodePointer) {
            this->size_of_list += 1;
            tempNodePointer = new Node<T>(nodePointer->getData());
            tailNodePointer->setNext(tempNodePointer);
            tailNodePointer = tailNodePointer->getNext();

            /* move to next node */
            nodePointer = nodePointer->getNext();
        }
    }
}

/* getter */
template<typename T>
Node<T> *SinglyLinkedList<T>::getHead() {
    return SinglyLinkedList::head;
}

template<typename T>
size_t SinglyLinkedList<T>::getListSize() {
    return SinglyLinkedList::size_of_list;
}

/* destructor */
template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* tempNodePointer{this->head};
    while (this->head){
        this->head = tempNodePointer->getNext();
        tempNodePointer->setNext(nullptr);

        /* de-allocate the heap memory */
        delete tempNodePointer;

        /* store current address of head
         * node for further processing */
        tempNodePointer = this->head;
    }
}

/* add element */

template<typename T>
void SinglyLinkedList<T>::addElementAtHead(Node<T>* nodePointer) {
    insertElementAt(nodePointer, 1);
}

template<typename T>
void SinglyLinkedList<T>::addElementAtHead(T data) {
    /* node creation from the given data */
    auto* node = new Node<T>(data);

    addElementAtHead(node);
}

template<typename T>
void SinglyLinkedList<T>::addElementAtTail(Node<T>* nodePointer) {
    insertElementAt(nodePointer, this->size_of_list + 1);
}

template<typename T>
void SinglyLinkedList<T>::addElementAtTail(T data) {
    /* node creation from the given data */
    auto* node = new Node<T>(data);

    addElementAtTail(node);
}

template<typename T>
void SinglyLinkedList<T>::insertElementAt(Node<T>* nodePointer, size_t position) {
    if(position >= 1 && position <= (this->size_of_list + 1)){
        /* increase the size_of_list */
        this->size_of_list += 1;

        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->head};

        if(position == 1){
            /* head pointer variable will get modified
             * if insertion get performed at first node */
            nodePointer->setNext(tempNodePointer);
            this->head = nodePointer;
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

/* delete element */

template<typename T>
void SinglyLinkedList<T>::deleteNodeFromHead() {
    deleteNodeAt(1);
}

template<typename T>
void SinglyLinkedList<T>::deleteNodeFromTail() {
    deleteNodeAt(this->size_of_list);
}

template<typename T>
void SinglyLinkedList<T>::deleteNodeAt(size_t position) {
    /* deletion can be performed only when their exist node at that position */
    if(position >= 1 && position <= this->size_of_list){
        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->getHead()};

        if(position == 1){
            /* head pointer variable will get modified if
             * first node of linked list is being deleted */
            this->head = tempNodePointer->getNext();
            tempNodePointer->setNext(nullptr);

            /* de-allocate the heap memory */
            delete tempNodePointer;
        } else {
            size_t countOfNode = 1;

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
void SinglyLinkedList<T>::deleteElement(T keyValue) {
    if(this->size_of_list >= 1) {
        Node<T>* tempNodePointer{this->head};
        Node<T>* previousNode{tempNodePointer} ;

        /* navigate through the list */
        while (tempNodePointer) {

            /* if keyValue is found then further
             * traversal of list isn't required */
            if(tempNodePointer->getData() == keyValue) {
                break;
            } else {
                previousNode = tempNodePointer;
                tempNodePointer = tempNodePointer->getNext();
            }
        }

        if(tempNodePointer) {

            /* if first occurrence of keyValue is
             * the first node of the linked-list */
            if (tempNodePointer == this->head) {
                /* detach the first node from linked-list */
                this->head = tempNodePointer->getNext();
                tempNodePointer->setNext(nullptr);

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
        /* when singly linked list hasn't any node */
        std::cout << "singly linked list is empty!" << std::endl;
    }
}


/* delete linked-list */
template<typename T>
void SinglyLinkedList<T>::deleteList() {
    Node<T>* tempNodePointer{this->head};
    while (this->head){
        this->head = tempNodePointer->getNext();
        tempNodePointer->setNext(nullptr);

        /* de-allocate the heap memory */
        delete tempNodePointer;
        this->size_of_list -= 1;

        /* store current address of head
         * node for further processing */
        tempNodePointer = this->head;
    }
}


/* iterative solution - (linked-list length) */
template<typename T>
size_t SinglyLinkedList<T>::getLinkedListLength() {
    size_t length_of_list{0};
    Node<T>* tempNodePointer{this->head};

    /* navigate through the linked list */
    while (tempNodePointer) {
        length_of_list += 1;
        tempNodePointer = tempNodePointer->getNext();
    }

    /* return the length of the linked-list */
    return length_of_list;
}

/* recursive solution - (linked-list length) */
template <typename T>
size_t SinglyLinkedList<T>::linkedListLength(Node<T>* nodePointer) {
    if (nodePointer) {
        return 1+linkedListLength(nodePointer->getNext());
    } else {
        return 0;
    }
}

/* display linked-list */
template<typename T>
void SinglyLinkedList<T>::printList() {
    Node<T>* tempNodePointer{this->getHead()};
    while(tempNodePointer){
        std::cout << tempNodePointer->getData() << " ";
        tempNodePointer = tempNodePointer->getNext();
    }std::cout << std::endl;
}

/* display reverse-linked-list */
template<typename T>
void SinglyLinkedList<T>::reverseListDisplay() {
    displayListInReverse(this->head);

    /* traverse the cursor to the next line */
    std::cout << std::endl;
}

template<typename T>
void SinglyLinkedList<T>::displayListInReverse(Node<T> *nodePointer) {
    if(nodePointer) {
        displayListInReverse(nodePointer->getNext());
        std::cout << nodePointer->getData() << " ";
    }
}

/* iterative solution (search linked-list) */
template<typename T>
Node<T> *SinglyLinkedList<T>::searchList(T keyValue) {
    /* search operation can be performed
     * only if linked list contain nodes */
    if(this->size_of_list >= 1){
        Node<T>* tempNodePointer{this->head};

        /* navigate through the list nodes */
        while (tempNodePointer){
            /* if keyValue is found inside the list
             * then no further traversal is required */
            if(tempNodePointer->getData() == keyValue) {
                return tempNodePointer;
            } else {
                tempNodePointer = tempNodePointer->getNext();
            }
        }
    } else {

        /* nullptr is a sentinel used to indicate
         * that keyValue isn't found in the list */
        return nullptr;
    }

    /* nullptr is a sentinel used to indicate that
     * keyValue can't be found in an empty list */
    return nullptr;
}

/* recursive solution (search linked-list) */
template <typename T>
Node<T>* SinglyLinkedList<T>::searchLinkedList(T keyValue) {
    return searchList(this->head, keyValue);
}

template<typename T>
Node<T> *SinglyLinkedList<T>::searchList(Node<T>* nodePointer,T keyValue) {
    if (nodePointer) {
        if (nodePointer->getData() == keyValue) {
            /* if keyValue is found inside the list
             * then no further traversal is required */
            return nodePointer;
        } else {
            /* if keyValue isn't found inside the list
             * then traverse successive list elements */
            return searchList(nodePointer->getNext(), keyValue);
        }
    } else {
        /* nullptr is a sentinel used to indicate
         * that keyValue isn't found in the list */
        return nullptr;
    }
}

#endif