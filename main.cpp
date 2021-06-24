#include <iostream>
#include <iomanip>
#include "List.h"

int main()
{
    List<std::string> list;

    std::cout << std::boolalpha;
    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    list.push_back("first");
    list.push_back("second");
    list.push_front("third");
    list.push_front("fourth");
    list.push_front("fifth");
    list.push_back("sixth");
    list.push_back("seventh");
    list.push_front("eighth");
    list.push_back("ninth");

    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;
    std::cout << "list.size() = " << list.size() << std::endl;
    list.display_all();

    list.clear();

    std::cout << "list.is_empty() = " << list.is_empty() << std::endl;

    return 0;
}