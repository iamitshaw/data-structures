
/* Include Guard */

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "node.h"

template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;
    int32_t size_of_tree;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    Node<T>* getRoot();
    int32_t getSizeOfTree();
    void deleteTree();
    std::pair<bool, Node<T>*> searchElement(T key_value);
    void insertElement(T data);
    void insertElement(Node<T>* node);
    void treeSort();
    void deleteElement(T key_value);
    Node<T>* findMaximum();
    Node<T>* findMinimum();
    bool isEmpty();

private:
    void deleteTree(Node<T>* root_val);
    Node<T>* findMaximum(Node<T>* root_val);
    Node<T>* findMinimum(Node<T>* root_val);
    void treeSort(Node<T>* root_val);
    void deleteElement(T key_value, Node<T>* root_val);
};

/* constructor */
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
:root{nullptr}, size_of_tree{0} {

}

/* destructor */
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    deleteTree(BinarySearchTree<T>::getRoot());
}

/* delete binary-search-tree */
template<typename T>
void BinarySearchTree<T>::deleteTree() {
    deleteTree(BinarySearchTree<T>::getRoot());

    /* initial state of binary-search-tree */
    BinarySearchTree<T>::root = {nullptr};
    BinarySearchTree<T>::size_of_tree = {0};
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T> *root_val) {
    if (root_val) {
        /* delete left-sub-tree */
        deleteTree(root_val->getLeft());

        /* delete right-sub-tree */
        deleteTree(root_val->getRight());

        delete root_val;
    }
}

/* get root_of_binary_search_tree */
template<typename T>
Node<T> *BinarySearchTree<T>::getRoot() {
    return BinarySearchTree<T>::root;
}

/* get size_of_binary_search_tree */
template<typename T>
int32_t BinarySearchTree<T>::getSizeOfTree() {
    return BinarySearchTree<T>::size_of_tree;
}

/* check whether binary-search-tree has elements */
template<typename T>
bool BinarySearchTree<T>::isEmpty() {
    return BinarySearchTree<T>::size_of_tree == 0;
}

/* search an element */
template<typename T>
std::pair<bool, Node<T>*> BinarySearchTree<T>::searchElement(T key_value) {
    Node<T>* tempNodePointer{BinarySearchTree<T>::getRoot()};
    while (tempNodePointer) {
        if (tempNodePointer->getData() > key_value) {
            tempNodePointer = tempNodePointer->getLeft();
        } else if (tempNodePointer->getData() < key_value) {
            tempNodePointer = tempNodePointer->getRight();
        } else {
            /* if key_value has been found */
            return {true, tempNodePointer};
        }
    }
    /* indicator to represent that
     * key_value doesn't exist */
    return {false, nullptr};
}

/* get maximum element */
template<typename T>
Node<T> *BinarySearchTree<T>::findMaximum() {
    return findMaximum(BinarySearchTree<T>::getRoot());
}

template<typename T>
Node<T> *BinarySearchTree<T>::findMaximum(Node<T> *root_val) {
    Node<T>* tempNodePointer{BinarySearchTree<T>::getRoot()};
    if (tempNodePointer) {
        while (tempNodePointer->getRight()) {
            tempNodePointer = tempNodePointer->getRight();
        }
    }
    return tempNodePointer;
}

/* get minimum element */
template<typename T>
Node<T> *BinarySearchTree<T>::findMinimum() {
    return findMinimum(BinarySearchTree<T>::getRoot());
}

template<typename T>
Node<T> *BinarySearchTree<T>::findMinimum(Node<T> *root_val) {
    Node<T>* tempNodePointer{BinarySearchTree<T>::getRoot()};
    if (tempNodePointer) {
        while (tempNodePointer->getLeft()) {
            tempNodePointer = tempNodePointer->getLeft();
        }
    }
    return tempNodePointer;
}

/* in-order-traversal of binary-search-tree */
template<typename T>
void BinarySearchTree<T>::treeSort() {
    treeSort(BinarySearchTree<T>::getRoot());
    /* move cursor to next-line */
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::treeSort(Node<T> *root_val) {
    if (root_val) {
        treeSort(root_val->getLeft());
        std::cout << root_val->getData() << " ";
        treeSort(root_val->getRight());
    }
}

template<typename T>
void BinarySearchTree<T>::insertElement(T data) {
    /* create node */
    auto* node = new Node<T>(data);
    insertElement(node);
}

template<typename T>
void BinarySearchTree<T>::insertElement(Node<T> *node) {
    Node<T>* tempNodePointer{BinarySearchTree<T>::getRoot()};
    if (tempNodePointer) {
        while (true) {
            if (tempNodePointer->getData() > node->getData()) {
                if (tempNodePointer->getLeft()){
                    tempNodePointer = tempNodePointer->getLeft();
                } else {
                    tempNodePointer->setLeft(node);
                    node->setParent(tempNodePointer);

                    /* update size_of_binary_search_tree */
                    BinarySearchTree<T>::size_of_tree += 1;
                    break;
                }
            } else if (tempNodePointer->getData() < node->getData()) {
                if (tempNodePointer->getRight()) {
                    tempNodePointer = tempNodePointer->getRight();
                } else {
                    tempNodePointer->setRight(node);
                    node->setParent(tempNodePointer);

                    /* update size_of_binary_search_tree */
                    BinarySearchTree<T>::size_of_tree += 1;
                    break;
                }
            } else {
                /* if duplicate elements aren't allowed */
                break;
            }
        }
    } else {
        /* if binary-search-tree is empty */
        BinarySearchTree<T>::root = node;
        node->setParent(node);

        /* update size_of_binary_search_tree */
        BinarySearchTree<T>::size_of_tree += 1;
    }
}

/* delete an element */
template<typename T>
void BinarySearchTree<T>::deleteElement(T key_value) {
    deleteElement(key_value, BinarySearchTree<T>::getRoot());
}

template<typename T>
void BinarySearchTree<T>::deleteElement(T key_value, Node<T> *root_val) {
    Node<T>* tempNodePointer{root_val};
    while (tempNodePointer) {
        if (tempNodePointer->getData() > key_value) {
            tempNodePointer = tempNodePointer->getLeft();
        } else if (tempNodePointer->getData() < key_value) {
            tempNodePointer = tempNodePointer->getRight();
        } else {
            /* if value has been found */

            if (tempNodePointer->getLeft() && tempNodePointer->getRight()) {
                /* if left-sub-tree & right-sub-tree both is present */
                Node<T>* successorNode{findMinimum(tempNodePointer->getRight())};

                /* swap content of tempNodePointer & successorNode */
                T tempData{tempNodePointer->getData()};
                tempNodePointer->setData(successorNode->getData());
                successorNode->setData(tempData);

                /* delete successorNode */
                deleteElement(key_value, successorNode);
            } else if (tempNodePointer->getLeft() || tempNodePointer->getRight()) {
                /* if either left-sub-tree or right-sub-tree is present */
                Node<T>* parentNode{tempNodePointer->getParent()};
                Node<T>* childNode{nullptr};tempNodePointer->setParent(nullptr);

                if (tempNodePointer->getLeft()) {
                    childNode = tempNodePointer->getLeft();
                    tempNodePointer->setLeft(nullptr);
                } else {
                    childNode = tempNodePointer->getRight();
                    tempNodePointer->setRight(nullptr);
                }

                childNode->setParent(parentNode);
                if (parentNode->getLeft() == tempNodePointer) {
                    parentNode->setLeft(childNode);
                } else {
                    parentNode->setRight(childNode);
                }

                /* de-allocate heap memory */
                delete tempNodePointer;

                /* update size_of_binary_search_tree */
                BinarySearchTree<T>::size_of_tree -= 1;
            } else {
                /* if neither left-sub-tree nor right-sub-tree is present */
                Node<T>* parentNode{tempNodePointer->getParent()};
                tempNodePointer->setParent(nullptr);
                if (parentNode->getLeft() == tempNodePointer) {
                    parentNode->setLeft(nullptr);
                } else {
                    parentNode->setRight(nullptr);
                }

                /* de-allocate heap memory */
                delete tempNodePointer;

                /* update size_of_binary_search_tree */
                BinarySearchTree<T>::size_of_tree -= 1;
            }

            /* if element has been deleted then
             * no further processing is required */
            break;
        }
    }
}

#endif