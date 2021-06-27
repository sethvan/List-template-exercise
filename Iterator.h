#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Node.h"
#include <stdexcept>
#include "List.h"

template <typename T>
class Iterator
{
private:
    Node<T> *p;

public:
    Iterator();
    Iterator(Node<T> *_p);
    ~Iterator();
    Iterator &operator=(const Node<T> *&rhs);
    Iterator &operator=(const Iterator<T> &rhs);
    Node<T> *operator++();
    Node<T> *operator--();
    bool operator!=(const Node<T> *rhs);
    bool operator!=(const Iterator<T> &rhs);
    bool operator==(const Node<T> *rhs);
    bool operator==(const Iterator<T> &rhs);

    T &operator*();
};
template <typename T>
Iterator<T>::Iterator() : p{nullptr} {}

template <typename T>
Iterator<T>::Iterator(Node<T> *_p) : p{_p} {}

template <typename T>
Iterator<T> &Iterator<T>::operator=(const Node<T> *&rhs)
{
    p = rhs;
}

template <typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &rhs)
{
    (*this) = rhs;
    return (*this);
}

template <typename T>
Iterator<T>::~Iterator() {}

template <typename T>
Node<T> *Iterator<T>::operator++()
{
    if (p == nullptr)
        throw std::out_of_range{"Iterator past .end()!"};
    else
        p = p->next;
    return p;
}

template <typename T>
Node<T> *Iterator<T>::operator--()
{
    if (p->previous == nullptr)
        throw std::out_of_range{"Iterator out of bounds!"};
    else
        p = p->previous;
    return p;
}

template <typename T>
T &Iterator<T>::operator*()
{
    if (p != nullptr)
        return p->data;
    else
        throw std::out_of_range{"No value to dereference!"};
}

template <typename T>
bool Iterator<T>::operator!=(const Node<T> *rhs)
{
    return (p != rhs);
}

template <typename T>
bool Iterator<T>::operator==(const Node<T> *rhs)
{
    return (p == rhs);
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T> &rhs)
{
    return (p != rhs.p);
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T> &rhs)
{
    return (p == rhs.p);
}

#endif