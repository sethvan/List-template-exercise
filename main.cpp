#include <iostream>
#include <iomanip>
#include "List.h"
#include "Iterator.h"

int main()
{
    List<std::string> list;

    std::cout << std::boolalpha;
    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    list.push_back("first");
    list.push_back("second");
    list.push_front("third");
    list.push_back("fourth");
    list.push_front("fifth");
    list.push_back("sixth");
    list.push_back("seventh");
    list.push_front("eighth");
    list.push_back("ninth");

    Iterator<std::string> it = list.begin();
    Iterator<std::string> it1 = list.end();

    --it1;
    std::cout << "Element at iterator0 = " << *it << std::endl;
    ++it;
    std::cout << "Element at iterator1 = " << *it1 << std::endl;
    std::cout << "Element at iterator0 = " << *it << std::endl;
    ++it;
    --it1;
    std::cout << "Element at iterator1 = " << *it1 << std::endl;
    std::cout << "Element at iterator0 = " << *it << std::endl;
    --it1;
    std::cout << "Element at iterator1 = " << *it1 << std::endl;

    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;
    std::cout << "list.size() = " << list.size() << std::endl;
    list.display_all();

    list.clear();

    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    return 0;
}