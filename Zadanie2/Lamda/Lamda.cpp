// Lamda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>


int main()
{
    std::vector<int> v;
    size_t displacement = 0;
    // Init Randome Value with time in seconds
    time_t t = time(NULL);
    std::cout << "Intt Randome Value " << t << std::endl;
    srand(t);

    // init vector
    for (int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 10);
    }
    //Lambda for printing
    auto printValue = [](int n) { std::cout << n << ' '; };
    

    // print array
    std::for_each(v.begin(), v.end(), printValue);
    std::cout << std::endl;

    //Lambda for sorting
    auto sorting = [&displacement](int a, int b)
    {
        if (a < b)
        {
            displacement++;
            return true;
        }
        return false;
    };

    std::sort(v.begin(), v.end(), sorting);
    std::cout << std::endl;

    // print the sorted array
    // print array
    std::for_each(v.begin(), v.end(), printValue);
    std::cout << std::endl;
  
    // print number of displacements
    std::cout << "There " << ((displacement != 1) ? "where " : "was " ) << displacement << ((displacement != 1) ? " displacements" : " displacement") << std::endl;
}
