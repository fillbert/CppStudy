// Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T, typename D>
std::vector<T>* addVector(std::vector<T>& vec1, std::vector<D>& vec2)
{
    std::vector<T>* v = new std::vector<T>;
    size_t size = (vec1.size() > vec2.size() ? vec1.size() : vec2.size());
    for (size_t i = 0; i < size; i++)
    {
        v->push_back(((vec1.size() > i) ? vec1[i] : 0) + ((vec2.size() > i) ? vec2[i] : 0));
    }
    return v;
}

template <typename T>
void initVector(std::vector<T>& vec, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        vec.push_back(rand());
    }
}


int main()
{
    std::vector<int> v1;
    std::vector<float> v2;

    initVector(v1, 10);
    initVector(v2, 20);

    auto printValue = [](auto x) { std::cout << x << ' '; };

    // Init Randome Value with time in seconds
    time_t t = time(NULL);
    std::cout << "Intt Randome Value " << t << std::endl;
    srand(t);

    std::for_each(v1.begin(), v1.end(), printValue);
    std::cout << std::endl;
    std::for_each(v2.begin(), v2.end(), printValue);
    std::cout << std::endl;

    std::vector<int>* p = addVector(v1, v2);

    std::for_each((*p).begin(), (*p).end(), printValue);
    std::cout << std::endl;

    std::cout << "Hello World!\n";
    delete(p);
}
