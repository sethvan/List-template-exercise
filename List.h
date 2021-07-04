#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Node.h"
#include "Iterator.h"

template <typename T>
class List
{
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const List<U> &rhs);

private:
    Node<T> *head;
    Node<T> *tail;
    void *parent;

public:
    List(void *_parent = nullptr);
    List(T _data, void *_parent = nullptr);
    ~List();
    void push_front(T _data);
    void push_back(T _data);
    void pop_front();
    void pop_back();
    Iterator<T> begin();
    Iterator<T> end();
    T &front();
    T &back();
    void clear();
    bool is_empty();
    size_t size();
    void display_all();
    void swap(List<T> &rhs) noexcept;
    void sort() noexcept;
};
template <typename T>
List<T>::List(void *_parent) : parent{_parent}
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
List<T>::List(T _data, void *_parent)
    : head{new Node<T>{_data, nullptr, nullptr}}, parent{_parent}
{
    tail = head;
    tail->next = new Node<T>;
    tail->next->previous = tail;
    tail->next->next = nullptr;
}

template <typename T>
List<T>::~List()
{
    if (head != nullptr && parent == nullptr)
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
        tail->next = node;
        node->next->previous = node;
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

template <typename T>
void List<T>::pop_front()
{
    if (head != nullptr)
    {
        Node<T> *temp = nullptr;
        head->next->previous = nullptr;
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::pop_back()
{
    if (head != nullptr)
    {
        Node<T> *temp = nullptr;
        tail->previous->next = tail->next;
        tail->next->previous = tail->previous;
        temp = tail;
        tail = tail->previous;
        delete temp;
    }
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const List<U> &rhs)
{
    if (rhs.head != nullptr)
    {
        Node<U> *current = rhs.head;
        printf("[ ");
        while (current->next != nullptr)
        {
            os << current->data << (current->next->next == nullptr ? " ]" : ", ");
            current = current->next;
        }
    }
    return os;
}

template <typename T>
Iterator<T> List<T>::begin()
{
    return Iterator<T>{head};
}

template <typename T>
Iterator<T> List<T>::end()
{
    return Iterator<T>{tail->next};
}

template <typename T>
void List<T>::sort() noexcept
{
    List<T> sorted{head->data};
    Node<T> *current = head->next;

    while (current->next != nullptr)
    {
        Node<T> *node = new Node<T>{current->data, nullptr, nullptr};
        Node<T> *p = sorted.head;
        Node<T> *previous = p;
        if (node->data > p->data)
        {
            while (p->data < node->data && p->next->next != nullptr)
            {
                previous = p;
                p = p->next;
            }
            if (p->next->next == nullptr && p->data < node->data)
            {
                node->next = p->next;
                node->next->previous = node;
                p->next = node;
                node->previous = p;
                sorted.tail = node;
            }
            else
            {
                node->next = p;
                p->previous = node;
                previous->next = node;
                node->previous = previous;
            }
        }
        else
        {
            node->next = sorted.head;
            sorted.head = node;
        }
        current = current->next;
    }
    swap(sorted);
}

template <typename T>
void List<T>::swap(List<T> &rhs) noexcept
{
    Node<T> *tempHead;
    Node<T> *tempTail;
    tempHead = head;
    tempTail = tail;
    head = rhs.head;
    tail = rhs.tail;
    rhs.head = tempHead;
    rhs.tail = tempTail;
    tempHead = nullptr;
    tempTail = nullptr;
}

template <typename T>
void swap(List<T> &one, List<T> &other) noexcept
{
    one.swap(other);
}

#endif