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

typedef std::pair<std::string, my_item> mpair;

struct mySort {
    inline bool operator() (mpair& a, mpair& b) 
    { 
        bool ret = a.second.getWeight() < b.second.getWeight();
        std::cout << std::left << std::setw(10) << a.first << ((ret) ? " < " : " > ") << b.first << std::endl;
        return ret;
    }
}mySortClass;


struct less_than_key
{
    inline bool operator() ( mpair& s1,  mpair& s2)
    {
        return (s1.second.getWeight() < s2.second.getWeight());
    }
}less_than_keyC;

#define CAPASITY            8.9

int main()
{
    // create items
    std::map<std::string, my_item> items{
        {"Paints", my_item(500, 1800)},
        {"Books", my_item(2000, 500)},
        {"Penal", my_item(400, 2000)},
        {"SideTrip", my_item(500, 1000, CAN_BE_SPLEETED)},
    };

    size_t displacement = 0;
    double capacity = CAPASITY;

    //Lambda for printing
    auto printValue = [](mpair n) { std::cout << n.second.refCostWeight << ' '; };


    auto Greedy_full = [&capacity](mpair n)
    {
        //
        if (n.second.canBeSplited == true)  return;
        //
        if (capacity >= n.second.refCostWeight)
        {
            capacity -= n.second.refCostWeight;
            std::cout << "Put Item: " << n.first << std::endl;
            std::cout << "Back has: " << (capacity / CAPASITY * 100) << "%" << " capasity" << std::endl;
        }
    };

    auto Greedy_part = [&capacity](mpair n)
    {
        //
        if (n.second.canBeSplited == false)  return;
        //

        if (capacity >= n.second.refCostWeight)
        {
            capacity -= n.second.refCostWeight;
            std::cout << "Put Item: " << n.first << std::endl;
            std::cout << "Back has: " << (capacity / CAPASITY * 100) << "%" << " capasity" << std::endl;
        }
        else
        {
            if (n.second.canBeSplited)
            {
                double partOfItem = capacity / n.second.refCostWeight;
                capacity -= (n.second.refCostWeight * partOfItem);
                std::cout << "Put Part " << partOfItem << " of the Item: " << n.first << std::endl;
                std::cout << "Back has: " << (capacity / CAPASITY * 100) << "%" << " capasity" << std::endl;
            }
        }
    };

    //Lambda for sorting
    auto sorting = [&displacement]( const mpair&a,   const mpair& b)
    {
        bool ret;
        ret = a.second < b.second;
        displacement++;
        std::cout  << std::left << std::setw(10)  << a.first << ((ret)?" < ":" > ") << b.first << std::endl;
        return ret;
    };

    // print items list
    for (auto& it : items)
    {
        my_item* p = &it.second;
        std::cout 
            << std::left << std::setw(10)  << "Object - " 
            << std::left << std::setw(10) << it.first
            << std::left << std::setw(10) << "| Cost: " 
            << std::left << std::setw(10)  << p->getCost()
            << std::left << std::setw(10) << "| Weight: " 
            << std::left << std::setw(10)  << p->getWeight()
            << std::left << std::setw(10) << "| Ref: "
            << std::left << std::setw(10)  << p->refCostWeight
            << std::left << std::setw(10) << "| Splited?: "
            << std::left << std::setw(10) << p->canBeSplited
            << std::endl;
    }

    // convert to vector
    std::vector<mpair> vec;
    std::copy(items.begin(),items.end(),
        std::back_inserter<std::vector<mpair>>(vec));

    // before sorting 
    std::cout << "Before Sort: " << std::endl;
    std::for_each(vec.begin(), vec.end(), printValue);
    std::cout << std::endl;

    // sort map
    std::sort(vec.begin(), vec.end(), less_than_keyC);

    //after sorting
    std::cout << "After Sort: " << std::endl;
    std::for_each(vec.begin(), vec.end(), printValue);
    std::cout << std::endl;

    // greedy solver
    std::cout << "Back has: " << (capacity / CAPASITY * 100) << "%" << " capasity" << std::endl;
    std::for_each(vec.begin(), vec.end(), Greedy_full);
    std::for_each(vec.begin(), vec.end(), Greedy_part);
    
    //
    return 0;
}




