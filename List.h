#ifndef LIST_H_
#define LIST_H_

#include <iostream>

template <typename T>
class List
{
    struct Node
    {
        T data;
        Node *previous;
        Node *next;
    };

private:
    Node *head;
    Node *tail;

public:
    List();
    List(T _data);
    ~List();
    void push_front(T _data);
    void push_back(T _data);
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
List<T>::List(T _data) : head{new Node{_data, nullptr, nullptr}} { tail = head; }

template <typename T>
List<T>::~List()
{
    std::cout << "In Destructor" << std::endl;
    if (head != nullptr)
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *previous = current;
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
        head = new Node(_data, nullptr, nullptr);
        tail = head;
    }
    else
    {
        Node *node = new Node(_data, nullptr, head);
        head->previous = node;
        head = node;
    }
}

template <typename T>
void List<T>::push_back(T _data)
{
    if (tail == nullptr)
    {
        tail = new Node(_data, nullptr, nullptr);
        head = tail;
    }
    else
    {
        Node *node = new Node(_data, tail, nullptr);
        tail->next = node;
        tail = node;
    }
}

template <typename T>
void List<T>::clear()
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *previous = current;
        current = current->next;
        delete previous;
    }
    head = nullptr;
    tail = nullptr;
    std::cout << "Cleared!" << std::endl;
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
        Node *current = head;

        while (current != nullptr)
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
        Node *current = head;
        printf("List = [ ");
        while (current != nullptr)
        {
            std::cout << current->data << (current->next == nullptr ? " ]" : ", ");
            current = current->next;
        }
        std::cout << std::endl;
    }
}
#endif