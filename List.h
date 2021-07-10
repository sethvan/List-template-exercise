#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Node.h"
#include "Iterator.h"
#include <utility>

template <typename T>
class List
{
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const List<U> &rhs);

private:
    Node<T> *head;
    Node<T> *tail;

public:
    List();
    List(T _data);
    List(const List& rhs);
    List(List&& rhs) noexcept;
    List& operator=(const List& rhs);
    List& operator=(List&& rhs) noexcept;
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
    void remove(Iterator<T> &it);
};
template <typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
    //std::cout << "Default constructor called" << std::endl;
}

template <typename T>
List<T>::List(T _data)
    : head{new Node<T>{std::move(_data), nullptr, nullptr}}
{
    tail = head;
    tail->next = new Node<T>;
    tail->next->previous = tail;
    tail->next->next = nullptr;
    std::cout << "Modified Default constructor called" << std::endl;
}

template <typename T>
List<T>::List(const List& rhs) : List{}
{
    *this = rhs;
    std::cout << "Copy constructed " << size() << " elements" << std::endl;
}

template <typename T>
List<T>::List(List&& rhs) noexcept : List{}
{
    swap(rhs);
    std::cout << "Move constructed " << size() << " elements" << std::endl;
}

template <typename T>
List<T>& List<T>::operator=(const List& rhs)
{
    List copy {};
    Node<T>* current = rhs.head;
    while(current->next != nullptr)
    {
        copy.push_back(current->data);
        current = current->next;
    }
    current = nullptr;
    
    swap(copy);
    std::cout << "Copy assigned " << size() << " elements" << std::endl;
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& rhs) noexcept
{
    swap(rhs);
    std::cout << "Move assigned " << size() << " elements" << std::endl;
    return *this;
}

template <typename T>
List<T>::~List()
{
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
        head = new Node<T>(std::move(_data), nullptr, nullptr);
        tail = head;
        tail->next = new Node<T>;
        tail->next->previous = tail;
        tail->next->next = nullptr;
    }
    else
    {
        Node<T> *node = new Node<T>(std::move(_data), nullptr, head);
        head->previous = node;
        head = node;
    }
}

template <typename T>
void List<T>::push_back(T _data)
{
    if (tail == nullptr)
    {
        tail = new Node<T>(std::move(_data), nullptr, nullptr);
        head = tail;
        tail->next = new Node<T>;
        tail->next->previous = tail;
        tail->next->next = nullptr;
    }
    else
    {
        Node<T> *node = new Node<T>(std::move(_data), tail, tail->next);
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
    printf("after -1\n");
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
    Node<T> *p;

    while (current->next != nullptr)
    {
        Node<T> *node = new Node<T>{current->data, nullptr, nullptr};
        p = sorted.head;
        if (node->data > p->data)
        {
            while (p->data < node->data && p->next->next != nullptr)
            {
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
                node->previous = p->previous;
                p->previous->next = node;
                p->previous = node; 
            }
        }
        else
        {
            node->next = sorted.head;
            sorted.head->previous = node;
            sorted.head = node;
        }
        current = current->next;
    }
    swap(sorted);
}

template <typename T>
void List<T>::swap(List &rhs) noexcept
{
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);   
}

template <typename T>
void swap(List<T> &one, List<T> &other) noexcept
{
    one.swap(other);
}

template <typename T>
void List<T>::remove(Iterator<T> &it)
{
    Node<T>* node = it.get_p();
    if(node->previous != nullptr && node->next!=nullptr)
    {
        node->next->previous = node->previous;
        node->previous->next = node->next;
        delete node;
    }
    else
       pop_front();
    
}
#endif