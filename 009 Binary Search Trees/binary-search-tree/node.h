
/* Include Guard */

#ifndef _NODE_H_
#define _NODE_H_

#include "object.h"

template <typename T>
class Node {
private:
    Object<T>* object;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
public:
    Node();
    explicit Node(T data);
    explicit Node(Object<T>* object);
    void setObject(Object<T>* object_value);
    Object<T>* getObject();
    void setLeft(Node<T>* left_val);
    Node<T>* getLeft();
    Node<T>* getRight() const;
    void setRight(Node<T>* right_val);
    void setParent(Node<T>* parent_val);
    Node<T>* getParent();
    T getData();
    void setData(T data);
    ~Node();
};

/* default constructor */
template<typename T>
Node<T>::Node()
        : left{nullptr}, right{nullptr}, parent{nullptr} {
    object = new Object<T>();
}

/* overloaded constructor */
template <typename T>
Node<T>::Node(T data)
        : left{nullptr}, right{nullptr}, parent{nullptr} {
    object = new Object<T>(data);
}

template<typename T>
Node<T>::Node(Object<T>* object)
        : object{object}, left{nullptr}, right{nullptr}, parent{nullptr} {

}

/* setters */
template<typename T>
void Node<T>::setObject(Object<T>* object_value) {
    Node::object = object_value;
}

template<typename T>
void Node<T>::setLeft(Node<T>* left_val) {
    Node::left = left_val;
}

template<typename T>
void Node<T>::setRight(Node<T> *right_val) {
    Node::right = right_val;
}

template<typename T>
void Node<T>::setData(T data) {
    object->setData(data);
}

template<typename T>
void Node<T>::setParent(Node<T> *parent_val) {
    Node<T>::parent = parent_val;
}

/* getters */
template<typename T>
Object<T>* Node<T>::getObject() {
    return Node::object;
}

template<typename T>
Node<T>* Node<T>::getLeft() {
    return Node::left;
}

template<typename T>
Node<T> *Node<T>::getRight() const {
    return Node::right;
}

template<typename T>
T Node<T>::getData() {
    return object->getData();
}

template<typename T>
Node<T> *Node<T>::getParent() {
    return Node<T>::parent;
}

/* destructor */
template<typename T>
Node<T>::~Node() {
    /* de-allocate heap memory */
    delete object;
}
#endif