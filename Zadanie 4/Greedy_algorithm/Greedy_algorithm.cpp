// Greedy_algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "item.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>


#define BACKPACK_CAPASITY   2000
#define CAN_BE_SPLEETED     true

typedef std::pair<std::string, item> mpair;

int main()
{
    // create items
    std::map<std::string, item> items{  
        {"Paints", item(500, 1800)},
        {"Books", item(2000, 500)},
        {"Penal", item(400, 2000)}, 
        {"SideTrip", item(500, 1000, CAN_BE_SPLEETED)},
    };

    //Lambda for printing
    auto printValue = [](mpair n) { std::cout << n.second.getRef() << ' '; };

    //Lambda for sorting
    auto sorting = []( mpair&a,   mpair& b)
    {
        bool ret;
        ret = a.second < b.second;
        std::cout << a.first << ((ret)?" < ":" > ") << b.first << std::endl;
        return ret;
    };

    // print items list
    for (auto& it : items)
    {
        item * p = &it.second;
        std::cout 
            << std::left << std::setw(10)  << "Object - " 
            << std::left << std::setw(10) << it.first
            << std::left << std::setw(10) << "| Cost: " 
            << std::left << std::setw(10)  << p->getCost()
            << std::left << std::setw(10) << "| Weight: " 
            << std::left << std::setw(10)  << p->getWeight()
            << std::left << std::setw(10) << "| Ref: "
            << std::left << std::setw(10)  << p->getRef()
            << std::endl;
    }

    // convert to vector
    std::vector<mpair> vec;
    std::copy(items.begin(),items.end(),
        std::back_inserter<std::vector<mpair>>(vec));

    // befo sorting 
    std::for_each(vec.begin(), vec.end(), printValue);

    // sort map
    std::sort(vec.begin(), vec.end(), sorting);

    //after sorting
    std::for_each(vec.begin(), vec.end(), printValue);
      
}




