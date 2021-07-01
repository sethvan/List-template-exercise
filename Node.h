#ifndef NODE_H_
#define NODE_H_

template <typename T>
struct Node
{
    T data;
    Node *previous;
    Node *next;

    bool operator<(Node<T> &rhs);
    bool operator>(Node<T> &rhs);
    bool operator==(Node<T> &rhs);
};

template <typename T>
bool Node<T>::operator<(Node<T> &rhs)
{
    return data < rhs.data;
}

template <typename T>
bool Node<T>::operator>(Node<T> &rhs)
{
    return data > rhs.data;
}

template <typename T>
bool Node<T>::operator==(Node<T> &rhs)
{
    return data == rhs.data;
}

#endif