#include <iostream>
#include "List.h"
#include <algorithm>

int main()
{
    std::cout << std::boolalpha;
    List<int> myList;
    for(int i{1}; i <= 100; ++i)
    {
        myList.push_back(i);
    }

    auto it = std::find(myList.begin(), myList.end(), 52);

    std::cout << "it = " << *it << std::endl;

    auto max_element = std::ranges::max_element(myList.begin(), myList.end());

    std::cout << "Max element = " <<  *max_element << std::endl;

    std::cout << std::ranges::is_sorted(myList.begin(), myList.end()) << std:: endl;

    std::for_each(myList.begin(), myList.end(), [](int &n){
        return n += 1;
    });

    myList.display_all();
    

    return 0;
}