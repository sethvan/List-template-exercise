#ifndef NODE_H_
#define NODE_H_

template <typename T>
struct Node
{
    T data;
    Node *previous;
    Node *next;
};

#endif