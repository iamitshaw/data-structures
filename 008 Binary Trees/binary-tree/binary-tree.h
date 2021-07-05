
/* Include Guard */

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include "node.h"

template <typename T>
class BinaryTree {
private:
    Node<T>* root;
    int32_t size_of_tree;
public:
    BinaryTree();
    ~BinaryTree();

    void deleteTree();
    bool isEmpty();
    int32_t getSizeOfTree();
    Node<T>* getRoot();
    void insertElement(T data);
    void insertElement(Node<T>* node);
    void deleteElement(T keyValue);
    void preOrder();
    void inOrder();
    void postOrder();
    void levelOrder();
    int32_t heightOfBinaryTree();
    std::pair<bool, Node<T>*> searchElement(T key_value);

private:
    void deleteTree(Node<T>* root);
    void emptyStack(std::stack<Node<T>*>& s1, std::stack<Node<T>*>& s2);
};

/* constructor */
template<typename T>
BinaryTree<T>::BinaryTree()
:root{nullptr}, size_of_tree{0} {

}

/* destructor */
template<typename T>
BinaryTree<T>::~BinaryTree() {
    deleteTree(BinaryTree<T>::getRoot());
}

/* delete binary_tree */
template<typename T>
void BinaryTree<T>::deleteTree() {

    deleteTree(BinaryTree<T>::getRoot());

    /* initial state of binary_tree */
    BinaryTree<T>::root = {nullptr};
    BinaryTree<T>::size_of_tree = {0};
}

template<typename T>
void BinaryTree<T>::deleteTree(Node<T> *root_val) {
    if (root_val) {
        /* delete left-subtree */
        deleteTree(root_val->getLeft());

        /* delete right-sub-tree */
        deleteTree(root_val->getRight());

        /* delete current node only
         * after deleting subtrees */
        delete root_val;
    }
}

template<typename T>
bool BinaryTree<T>::isEmpty() {
    return (BinaryTree<T>::size_of_tree == 0);
}

template<typename T>
int32_t BinaryTree<T>::getSizeOfTree() {
    return BinaryTree<T>::size_of_tree;
}

template<typename T>
Node<T> *BinaryTree<T>::getRoot() {
    return BinaryTree<T>::root;
}

/* insert data into binary_tree */
template<typename T>
void BinaryTree<T>::insertElement(T data) {
    /* create node */
    auto* node = new Node<T>(data);
    insertElement(node);
}

template<typename T>
void BinaryTree<T>::insertElement(Node<T> *node) {
    std::queue<Node<T>*> q;

    /* create tempNodePointer */
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};

    if (tempNodePointer) {
        /* if binary_tree isn't empty */
        q.push(tempNodePointer);
        while (!q.empty()) {
            tempNodePointer = {q.front()};
            /* for left-subtree */
            if (tempNodePointer->getLeft()) {
                q.push(tempNodePointer->getLeft());
            } else {
                tempNodePointer->setLeft(node);
                node->setParent(tempNodePointer);
                break;
            }

            /* for right-subtree */
            if (tempNodePointer->getRight()) {
                q.push(tempNodePointer->getRight());
            } else {
                tempNodePointer->setRight(node);
                node->setParent(tempNodePointer);
                break;
            }
            q.pop();
        }
    } else {
        /* if binary_tree is empty */
        BinaryTree<T>::root = node;
        node->setParent(node);
    }

    /* update size_of_binary_tree */
    BinaryTree<T>::size_of_tree += 1;
}

template<typename T>
void BinaryTree<T>::deleteElement(T keyValue) {
    std::queue<Node<T>*> q;bool is_found{false};
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};
    Node<T>* nodeToBeDeleted{nullptr};

    if (tempNodePointer) {
        q.push(tempNodePointer);
        while (!q.empty()) {
            tempNodePointer = {q.front()};
            if (!is_found && tempNodePointer->getData()==keyValue) {
                /* if nodeToBeDeleted has been found */
                nodeToBeDeleted = tempNodePointer;
                is_found = {true};
            }

            /* for left-subtree */
            if (tempNodePointer->getLeft()) {
                q.push(tempNodePointer->getLeft());
            }

            /* for right sub-tree */
            if (tempNodePointer->getRight()) {
                q.push(tempNodePointer->getRight());
            }
            q.pop();
        }

        /* if nodeToBeDeleted isn't nullptr */
        if (nodeToBeDeleted) {
            nodeToBeDeleted->setData(tempNodePointer->getData());

            Node<T>* parent_node{tempNodePointer->getParent()};
            if (parent_node->getLeft() == tempNodePointer) {
                parent_node->setLeft(nullptr);
            } else  {
                parent_node->setRight(nullptr);
            }

            /* de-attach deepest node */
            tempNodePointer->setParent(nullptr);

            /* update size_of_binary_tree */
            BinaryTree<T>::size_of_tree -= 1;

            /* de-allocate heap memory */
            delete tempNodePointer;
        }
    }
}

/* pre-order-traversal algorithm */
template<typename T>
void BinaryTree<T>::preOrder() {
    std::stack<Node<T>*> s;
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};
    while (true) {
        while (tempNodePointer) {
            std::cout << tempNodePointer->getData() << " ";
            if (tempNodePointer->getRight()) {
                /* store only right child information */
                s.push(tempNodePointer->getRight());
            }
            tempNodePointer = tempNodePointer->getLeft();
        }

        if (!s.empty()) {
            /* if stack isn't empty */
            tempNodePointer = {s.top()};s.pop();
        } else {
            /* if stack is empty i.e. each node's
             * right child has been processed */
            break;
        }
    }
    /* move cursor to next-line */
    std::cout << std::endl;
}

/* in-order-traversal Algorithm */
template<typename T>
void BinaryTree<T>::inOrder() {
    std::stack<Node<T>*> s;
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};
    while (true) {
        while (tempNodePointer) {
            s.push(tempNodePointer);
            tempNodePointer = tempNodePointer->getLeft();
        }

        if (!s.empty()) {
            /* if stack isn't empty */
            tempNodePointer = {s.top()};s.pop();
            std::cout << tempNodePointer->getData() << " ";
            tempNodePointer = tempNodePointer->getRight();
        } else {
            /* if stack is empty i.e. each node's
             * right child has been processed */
            break;
        }
    }
    /* move cursor to next-line */
    std::cout << std::endl;
}

/* post-order-traversal Algorithm */
template<typename T>
void BinaryTree<T>::postOrder() {
    std::stack<Node<T>*> s;
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};
    while (true) {
        while (tempNodePointer) {
            s.push(tempNodePointer);
            tempNodePointer = tempNodePointer->getLeft();
        }

        if (!s.empty()) {
            /* if stack isn't empty */
            while (!s.top()->getRight() || s.top()->getRight() == tempNodePointer) {
                tempNodePointer = s.top();s.pop();

                /* print node's data */
                std::cout << tempNodePointer->getData() << " ";

                /* if stack is empty then no further
                 * processing is required of tree */
                if (s.empty()) {break;}
            }

            /* if stack isn't empty */
            if (!s.empty()) {
                tempNodePointer=s.top()->getRight();
            } else {
                /* if stack is empty */
                tempNodePointer = {nullptr};
            }
        } else {
            /* if stack is empty */
            break;
        }
    }
    /* move cursor to next-line */
    std::cout << std::endl;
}

/* level-order-traversal Algorithm */
template<typename T>
void BinaryTree<T>::levelOrder() {
    std::queue<Node<T>*> q;
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};
    if (tempNodePointer) {q.push(tempNodePointer);}

    while (!q.empty()) {
        std::cout << tempNodePointer->getData() << " ";
        if (tempNodePointer->getLeft()) {
            q.push(tempNodePointer->getLeft());
        }
        if (tempNodePointer->getRight()) {
            q.push(tempNodePointer->getRight());
        }

        /* update tempNodePointer */
        q.pop();tempNodePointer = (!q.empty()? q.front(): nullptr);
    }
}

/* search an element */
template<typename T>
std::pair<bool, Node<T> *> BinaryTree<T>::searchElement(T key_value) {
    std::queue<Node<T>*> q;
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};
    if (tempNodePointer) {q.push(tempNodePointer);}

    while (!q.empty()) {
        if (tempNodePointer->getData() == key_value) {
            return {true, tempNodePointer};
        }
        if (tempNodePointer->getLeft()) {
            q.push(tempNodePointer->getLeft());
        }
        if (tempNodePointer->getRight()) {
            q.push(tempNodePointer->getRight());
        }

        /* update tempNodePointer */
        q.pop();tempNodePointer = (!q.empty()? q.front(): nullptr);
    }
    return {false, nullptr};
}

template<typename T>
void BinaryTree<T>::emptyStack(std::stack<Node<T> *> &s1, std::stack<Node<T> *> &s2) {
    Node<T>* tempNodePointer{nullptr};
    while (!s1.empty()) {
        tempNodePointer = {s1.top()};
        if (tempNodePointer->getLeft()) {
            s2.push(tempNodePointer->getLeft());
        }
        if (tempNodePointer->getRight()) {
            s2.push(tempNodePointer->getRight());
        }
        /* update stack */s1.pop();
    }
}

/* height of binary tree */
template<typename T>
int32_t BinaryTree<T>::heightOfBinaryTree() {
    std::stack<Node<T>*> s1;std::stack<Node<T>*> s2;
    Node<T>* tempNodePointer{BinaryTree<T>::getRoot()};

    /* if tree isn't empty */int32_t heightOfTree{-1};
    if (tempNodePointer) {s1.push(tempNodePointer);}

    while (!s1.empty() || !s2.empty()) {
        if (!s1.empty()) {
            /* process odd-level which is in s1
             * & put even-level into stack s2 */
            BinaryTree<T>::emptyStack(s1, s2);
        } else {
            /* process even-level which is in s2
             * & put odd-level into stack s1 */
            BinaryTree<T>::emptyStack(s2, s1);
        }

        /* update heightOfBinaryTree */
        heightOfTree += 1;
    }

    return heightOfTree;
}

#endif