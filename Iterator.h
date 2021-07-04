#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Node.h"
#include <stdexcept>
#include <iterator>
#include <list>

template <typename T>
struct Iterator
{
    using value_type = T;
    using difference_type = std::iter_difference_t<std::list<T>>;
    using pointer = Node<T>*; 
    using reference = T&;
    using iterator_category = std::bidirectional_iterator_tag;
    

private:
    Node<T> *p;

public:
    Iterator();
    Iterator(Node<T> *_p);
    ~Iterator() = default;
    
    Iterator<T>& operator++();
    Iterator<T> operator++(int);
    Iterator<T>& operator--();
    Iterator<T> operator--(int);
    bool operator!=(const Iterator<T> &rhs) const;
    bool operator==(const Iterator<T> &rhs) const;
    T &operator*() const;

   
};

template <typename T>
Iterator<T>::Iterator() : p{nullptr} {}

template <typename T>
Iterator<T>::Iterator(Node<T> *_p) : p{_p} {}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if (p->next != nullptr)
    {  
        p = p->next;
        return (*this);       
    }
    else
        throw std::out_of_range{"Iterator past .end()!"};
        
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    auto temp = (*this);
    p = p->next;
    return temp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
    if (p->previous == nullptr)
        throw std::out_of_range{"Iterator out of bounds!"};
    else
        p = p->previous;
    return (*this);
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    auto temp = (*this);
    p = p->previous;
    return temp;
}

template <typename T>
T &Iterator<T>::operator*() const
{
    if (p != nullptr && p->next != nullptr)
        return p->data;
    else
        throw std::out_of_range{"No value to dereference!"};
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) const
{
    return (p != rhs.p);
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) const
{
    return (p == rhs.p);
}


#endif