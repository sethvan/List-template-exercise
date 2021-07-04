#include <iostream>
#include "List.h"
#include <algorithm>

int main()
{
    static_assert(std::bidirectional_iterator<Iterator<int>>, "Does not pass");
    std::cout << std::boolalpha;
    List<int> myList;
    for(int i{1}; i <= 100; ++i)
    {
        myList.push_back(i);
    }

    auto it = std::find(myList.begin(), myList.end(), 52);

    std::cout << "it = " << *it << std::endl;

    auto max_element = std::ranges::max_element(myList.begin(), myList.end());

    std::cout << "Max element = " <<  *max_element-- << std::endl;
    std::cout << "Max element = " <<  *max_element << std::endl;


    std::cout << std::ranges::is_sorted(myList.begin(), myList.end()) << std:: endl;

    std::for_each(myList.begin(), myList.end(), [](int &n){
        return n += 1;
    });

    myList.display_all();

    auto testIt = myList.end();
    //std::cout << *testIt << std::endl;
    //++testIt;

    // auto testIt1 = myList.begin();
    // --testIt1;
    

    return 0;
}