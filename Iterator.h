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
    List<T> list;

public:
    Iterator();
    Iterator(Node<T> *_p);
    ~Iterator();
    Iterator &operator=(Node<T> *&rhs);
    Node<T> *operator++();
    Node<T> *operator--();
    bool operator!=(Node<T> *&rhs);
    bool operator==(Node<T> *&rhs);
    T &operator*();
};
template <typename T>
Iterator<T>::Iterator() : p{nullptr} {}

template <typename T>
Iterator<T>::Iterator(Node<T> *_p) : p{_p} {}

template <typename T>
Iterator<T> &Iterator<T>::operator=(Node<T> *&rhs)
{
    p = rhs;
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
    else if (p == List<T>::tail->next)
        p = List<T>::tail;
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
        throw std::out_of_range{"List is empty!"};
}

template <typename T>
bool Iterator<T>::operator!=(Node<T> *&rhs)
{
    return (p != rhs);
}

template <typename T>
bool Iterator<T>::operator==(Node<T> *&rhs)
{
    return (p == rhs);
}

#endif