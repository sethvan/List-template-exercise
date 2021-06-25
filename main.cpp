#include <iostream>
#include <iomanip>
#include "List.h"
#include "Iterator.h"

template <typename T>
Node<T> *find(const List<T> &list, T value)
{
    Node<T> *current = list.begin();
    while (current != list.end() && current->data != value)
    {
        current = current->next;
    }
    return current;
}

int main()
{
    List<std::string> list;

    std::cout << std::boolalpha;
    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    list.push_back("eleventh");
    list.push_back("fifth");
    list.push_front("third");
    list.push_back("sixth");
    list.push_front("second");
    list.push_back("seventh");
    list.push_back("eigth");
    list.push_front("first");
    list.push_back("ninth");

    Iterator<std::string> it2 = find(list, std::string("eleventh"));
    *it2 = "fourth";

    Iterator<std::string> it = list.begin();
    Iterator<std::string> it1 = list.end();

    --it1;
    std::cout << "Element at iterator0 = " << *it << std::endl;
    ++it;
    std::cout << "Element at iterator1 = " << *it1 << std::endl;
    *it1 = "eigth and a half";
    std::cout << "Element at iterator0 = " << *it << std::endl;
    ++it;
    --it1;
    std::cout << "Element at iterator1 = " << *it1 << std::endl;
    std::cout << "Element at iterator0 = " << *it << std::endl;
    --it1;
    std::cout << "Element at iterator1 = " << *it1 << std::endl;

    std::string str = "fourth";

    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;
    std::cout << "list.size() = " << list.size() << std::endl;
    list.display_all();

    list.clear();

    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    return 0;
}