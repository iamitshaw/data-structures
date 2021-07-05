
/* Include Guard */

#ifndef _NODE_H_
#define _NODE_H_

#include "object.h"

template <typename T>
class Node {
private:
    Object<T>* object;
    Node<T>* next;
public:
    Node();
    explicit Node(T data);
    explicit Node(Object<T>* object);
    void setObject(Object<T>* object_value);
    Object<T>* getObject();
    void setNext(Node<T>* next_val);
    Node<T>* getNext();
    T getData();
    void setData(T data);

};

/* default constructor */
template<typename T>
Node<T>::Node()
        : next{nullptr} {
    object = new Object<T>();
}

/* overloaded constructor */
template <typename T>
Node<T>::Node(T data)
        : next{nullptr} {
    object = new Object<T>(data);
}

template<typename T>
Node<T>::Node(Object<T>* object)
        : object{object}, next{nullptr} {

}

/* setters */
template<typename T>
void Node<T>::setObject(Object<T>* object_value) {
    Node::object = object_value;
}

template<typename T>
void Node<T>::setNext(Node<T>* next_val) {
    Node::next = next_val;
}

/* getter */
template<typename T>
Object<T>* Node<T>::getObject() {
    return Node::object;
}

template<typename T>
Node<T>* Node<T>::getNext() {
    return Node::next;
}

template<typename T>
T Node<T>::getData() {
    return this->object->getData();
}

template<typename T>
void Node<T>::setData(T data) {
    this->object->setData(data);
}

#endif