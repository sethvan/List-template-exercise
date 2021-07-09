#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Node.h"
#include <iterator>
#include <cassert>
#include "List.h"


template <typename T>
struct Iterator
{
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*; 
    using reference = T&;
    using iterator_category = std::bidirectional_iterator_tag;
    

private:
    Node<T> *p;

public:
    Iterator(Node<T> *_p = nullptr);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator!=(const Iterator<T> &rhs) const;
    bool operator==(const Iterator<T> &rhs) const;
    T &operator*() const;
    Node<T>* get_p(){return p;}

   
};

template <typename T>
Iterator<T>::Iterator(Node<T> *_p) : p{_p} {}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    assert(p->next != nullptr);   
    p = p->next;
    return *this;           
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    auto temp = *this;
    p = p->next;
    return temp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
    assert(p->previous != nullptr);
    p = p->previous;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    auto temp = *this;
    p = p->previous;
    return temp;
}

template <typename T>
T &Iterator<T>::operator*() const
{
    assert(p != nullptr && p->next != nullptr);
    return p->data;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) const
{
    return p != rhs.p;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) const
{
    return p == rhs.p;
}


#endif