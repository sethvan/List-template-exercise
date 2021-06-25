#include <iostream>
#include <iomanip>
#include "List.h"
#include "Iterator.h"

template <typename T>
Iterator<T> find(Node<T> *begin, Node<T> *end, T value)
{
    Iterator<T> it = begin;
    while (it != end && *it != value)
        ++it;

    return it;
}

int main()
{
    List<std::string> list;

    std::cout << std::boolalpha;
    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    std::cout << "\nPushing one element to back..." << std::endl;
    list.push_back("eleventh");

    std::cout << "\ndisplaying list..." << std::endl;
    list.display_all();

    std::cout << "\nlist.is_empty() = " << list.is_empty() << std::endl;

    std::cout << "\nPushing eight more elements to both back and front..." << std::endl;
    list.push_back("fifth");
    list.push_front("third");
    list.push_back("sixth");
    list.push_front("second");
    list.push_back("seventh");
    list.push_back("eigth");
    list.push_front("first");
    list.push_back("ninth");

    std::cout << "\ndisplaying list..." << std::endl;
    list.display_all();

    std::cout << "\nsetting iterator it to find element \"eleventh\"..." << std::endl;
    Iterator<std::string> it = find(list.begin(), list.end(), std::string("eleventh"));
    std::cout << "Changing value of element at it : *it = \"fourth\"\n"
              << std::endl;
    *it = "fourth";

    std::cout << "setting iterator it1 to list.begin()..." << std::endl;
    Iterator<std::string> it1 = list.begin();
    std::cout << "element at it1 = \"" << *it1 << "\"" << std::endl;
    ++it1;
    std::cout << "incrementing it1 and displaying new element: \"" << *it1 << "\"" << std::endl;
    ++it1;
    std::cout << "incrementing it1 and displaying new element: \"" << *it1 << "\"" << std::endl;

    std::cout << "\nsetting iterator it2 to list.end()..." << std::endl;
    Iterator<std::string> it2 = list.end();
    --it2;
    std::cout << "\ndecrementing it2 and displaying new element: \"" << *it2 << "\"" << std::endl;
    std::cout << "Changing *it2 to \"eight and a half\"" << std::endl;
    *it2 = "eigth and a half";
    --it2;
    std::cout << "decrementing it2 and displaying new element: \"" << *it2 << "\"" << std::endl;
    --it2;
    std::cout << "decrementing it2 and displaying new element: \"" << *it2 << "\"" << std::endl;

    std::cout << "\nlist.is_empty() = " << list.is_empty() << std::endl;
    std::cout << "\nlist.size() = " << list.size() << std::endl;
    std::cout << "\ndisplaying list..." << std::endl;
    list.display_all();
    std::cout << "\nClearing list..." << std::endl;
    list.clear();

    std::cout << "\nlist.is_empty() = " << list.is_empty() << std::endl;

    return 0;
}