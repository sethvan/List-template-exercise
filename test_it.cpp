#include <iostream>
#include "List.h"
#include <list>
#include <algorithm>
#include <cstdlib>
#include <array>
#include "Iterator.h"
#include <vector>
#include <string>
#define MAX 9000
#define MIN 1000

List<std::string> makeList(size_t size)
{
    List<std::string> list{};

    for(size_t i{}; i < size; ++i)
    {
        list.push_back("Will this be a copy or a move??");
    }

    return list;
}



int main()
{
    static_assert(std::bidirectional_iterator<Iterator<int>>, "Does not pass");
    std::cout << std::boolalpha;
    List<int> myList;
    std::list<int> yourList;
    std::array<int, MAX> arr;
    srand(time(0));
    int num = 1234;
    for(int i{0}; i < MAX; i++)
    {
        arr[i] = (rand()%(MAX - MIN)) + MIN;   
    }
    
    for(int i{0}; i < MAX; i++)
    {
        myList.push_back(arr[i]);
        yourList.push_back(arr[i]);
    }
    auto it = std::ranges::find(myList, num);
    if(it!=myList.end())
       std::cout << "my find = " << *it << std::endl;
    else
       std::cout << num << " not found in myList" << std::endl;
    
    auto _it = std::ranges::find(yourList, num);
    if(_it!=yourList.end())
       std::cout << "your find = " << *_it << std::endl;
    else
       std::cout << num << " not found in yourList" << std::endl;

    it = std::ranges::min_element(myList);
    _it = std::ranges::min_element(yourList);
    
    std::cout << "my min_element = " << *it << std::endl;
    std::cout << "your min_element = " << *_it << std::endl;

    it = std::ranges::max_element(myList);
    _it = std::ranges::max_element(yourList);
    
    std::cout << "my max_element = " << *it << std::endl;
    std::cout << "your max_element = " << *_it << std::endl;

    std::cout << "myList is sorted = " << std::ranges::is_sorted(myList) << std::endl;
    myList.sort();
    std::cout << "myList is sorted = " << std::ranges::is_sorted(myList) << std::endl;

    
    List<std::string> strList = makeList(100);//due to NRVO, only the default constructors are called in this instance and from within the function
    List<std::string> strList2 {makeList(200)};//due to NRVO, only the default constructors are called in this instance and from within the function
    List<std::string> strList3{};
 
    strList3 = makeList(100);//since already been constrcted, move assignment is called

    strList2 = strList;//copy assigned

    List<std::string> strList4{strList3};//copy constructed using my copy assignment code
    List<std::string> strList5(makeList(300));//NRVO
   
    std::vector<List<std::string>> vec;
    
    vec.push_back(makeList(1000));//move constructed
    vec.push_back(makeList(200)); //move constructed
    vec.push_back(makeList(1000));//move constructed
    vec.push_back(strList5);      //copy constructed using my copy assignment code    
    
    return 0;
}