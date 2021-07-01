#include <iostream>
#include <iomanip>
#include "List.h"
#include "Iterator.h"
#include <algorithm>

template <typename T>
Iterator<T> find(Iterator<T> begin, Iterator<T> end, T value)
{
    Iterator<T> it = begin;
    while (it != end && *it != value)
        ++it;

    return it;
}

int main()
{
    std::string word = "word";
    List<std::string> list;

    std::cout << std::boolalpha;
    std::cout << "\n\nlist.is_empty() = " << list.is_empty() << std::endl;

    std::cout << "\nPushing one element to back..." << std::endl;
    list.push_back("eleventh");

    std::cout << "\nDisplaying list..." << std::endl;
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

    std::cout << "\nDisplaying list..." << std::endl;
    list.display_all();

    std::cout << "\nList.front() = " << list.front() << std::endl;
    std::cout << "List.back() = " << list.back() << std::endl;

    std::cout << "\nSetting iterator it to find element \"eleventh\"..." << std::endl;
    Iterator<std::string> it = find(list.begin(), list.end(), std::string("eleventh"));
    std::cout << "Changing value of element at it : *it = \"fourth\"\n"
              << std::endl;
    *it = "fourth";

    std::cout << "Setting iterator it1 to list.begin()..." << std::endl;
    Iterator<std::string> it1 = list.begin();
    std::cout << "Element at it1 = \"" << *it1 << "\"" << std::endl;
    ++it1;
    std::cout << "Incrementing it1 and displaying new element: \"" << *it1 << "\"" << std::endl;
    ++it1;
    std::cout << "Incrementing it1 and displaying new element: \"" << *it1 << "\"" << std::endl;

    std::cout << "\nSetting iterator it2 to list.end()..." << std::endl;
    Iterator<std::string> it2 = list.end();
    --it2;
    std::cout << "\nDecrementing it2 and displaying new element: \"" << *it2 << "\"" << std::endl;
    std::cout << "Changing *it2 to \"eight and a half\"" << std::endl;
    *it2 = "eigth and a half";
    --it2;
    std::cout << "Decrementing it2 and displaying new element: \"" << *it2 << "\"" << std::endl;
    --it2;
    std::cout << "Decrementing it2 and displaying new element: \"" << *it2 << "\"" << std::endl;

    while (it1 != it2)
        ++it1;
    std::cout << "\nPerforming: while (it1 != it2) ++it1; ..." << std::endl;
    std::cout << "(it1 == it2) = " << (it1 == it2) << std::endl;

    std::cout << "\nlist.size() = " << list.size() << "\n"
              << std::endl;

    list.display_all();

    std::cout
        << "\nExecuting pop_back() method once..." << std::endl;
    list.pop_back();
    list.display_all();

    std::cout << "\nUsing std::transform to add the words \" and main\" to each element..." << std::endl;
    std::transform(list.begin(), list.end(), list.begin(), [](std::string str)
                   { return str + " and Main"; });
    list.display_all();

    std::cout << "\nUsing std::transform to delete the words \" and main\" from each element..." << std::endl;
    std::transform(list.begin(), list.end(), list.begin(), [](std::string str)
                   { return str.erase(str.length() - 9); });
    list.display_all();

    std::cout << "\nSorting list(alphabetically in this case)..." << std::endl;
    list.sort();
    list.display_all();

    std::cout << "\nExecuting pop_back() method twice more..." << std::endl;
    list.pop_back();
    list.pop_back();
    list.display_all();

    std::cout << "\nlist.size() = " << list.size() << std::endl;

    std::cout << "\nExecuting pop_front() method once and displaying list..." << std::endl;
    list.pop_front();
    list.display_all();

    std::cout << "\nExecuting pop_front() method twice more and displaying list..." << std::endl;
    list.pop_front();
    list.pop_front();
    list.display_all();

    std::cout << "\nClearing list..." << std::endl;
    list.clear();

    std::cout << "\nlist.is_empty() = " << list.is_empty() << std::endl;

    return 0;
}