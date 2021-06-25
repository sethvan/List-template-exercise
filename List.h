#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Node.h"
#include "Iterator.h"

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    List();
    List(T _data);
    ~List();
    void push_front(T _data);
    void push_back(T _data);
    Node<T> *begin();
    Node<T> *end();
    T &front();
    T &back();
    void clear();
    bool is_empty();
    size_t size();
    void display_all();
};
template <typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
List<T>::List(T _data) : head{new Node<T>{_data, nullptr, nullptr}} { tail = head; }

template <typename T>
List<T>::~List()
{
    std::cout << "In Destructor" << std::endl;
    if (head != nullptr)
    {
        Node<T> *current = head;

        while (current != nullptr)
        {
            Node<T> *previous = current;
            current = current->next;
            delete previous;
        }
    }
}

template <typename T>
void List<T>::push_front(T _data)
{
    if (head == nullptr)
    {
        head = new Node<T>(_data, nullptr, nullptr);
        tail = head;
        tail->next = new Node<T>;
        tail->next->previous = tail;
        tail->next->next = nullptr;
    }
    else
    {
        Node<T> *node = new Node<T>(_data, nullptr, head);
        head->previous = node;
        head = node;
    }
}

template <typename T>
void List<T>::push_back(T _data)
{
    if (tail == nullptr)
    {
        tail = new Node<T>(_data, nullptr, nullptr);
        head = tail;
        tail->next = new Node<T>;
        tail->next->previous = tail;
        tail->next->next = nullptr;
    }
    else
    {
        Node<T> *node = new Node<T>(_data, tail, tail->next);
        tail->next->previous = node;
        tail->next = node;
        tail = node;
    }
}

template <typename T>
void List<T>::clear()
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *previous = current;
        current = current->next;
        delete previous;
    }
    head = nullptr;
    tail = nullptr;
    std::cout << "List cleared!" << std::endl;
}

template <typename T>
bool List<T>::is_empty()
{
    return (head == nullptr);
}

template <typename T>
size_t List<T>::size()
{
    if (head == nullptr)
        return 0;
    else
    {
        size_t count = 0;
        Node<T> *current = head;

        while (current->next != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
}

template <typename T>
void List<T>::display_all()
{
    if (head != nullptr)
    {
        Node<T> *current = head;
        printf("List = [ ");
        while (current->next != nullptr)
        {
            std::cout << current->data << (current->next->next == nullptr ? " ]" : ", ");
            current = current->next;
        }
        std::cout << std::endl;
    }
}

template <typename T>
Node<T> *List<T>::begin()
{
    return head;
}

template <typename T>
Node<T> *List<T>::end()
{
    return tail->next;
}

template <typename T>
T &List<T>::front()
{
    if (head != nullptr)
        return head->data;
    else
        throw std::out_of_range{"List is empty!"};
}

template <typename T>
T &List<T>::back()
{
    if (head != nullptr)
        return tail->data;
    else
        throw std::out_of_range{"List is empty!"};
}
#endif