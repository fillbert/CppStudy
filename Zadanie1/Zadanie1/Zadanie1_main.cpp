// Zadanie1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include <algorithm>
#include <array>

bool compare(Person& a, Person& b)
{
    return (a.getAssestmentScore() < b.getAssestmentScore());
}

template<size_t N>
void printPersons( std::array<Person, N> &ppp)
{
    for (size_t i = 0; i < ppp.size(); i++)
    {
        ppp[i].printPerson();
    }
}

template<size_t N>
double averageAge(std::array<Person, N>& ppp)
{
    double average = 0;

    for (size_t i = 0; i < ppp.size(); i++)
    {
        average += (double)ppp[i].getAge();
    }

    return (average /= ppp.size());
}

int main()
{
    std::array<Person, 5> prr;

    // init array
    prr[0] = Person("Vaya", "Pupkin", 24, 50);
    prr[1] = Person("Petya", "Pipkin", 25, 10);
    prr[2] = Person("Grisha", "Petrov", 20, 30);
    prr[3] = Person("Misha", "Sidorov", 21, 90);
    prr[4] = Person("Ivan", "Ivanov", 28, 100);

    //
    std::cout << "List of Persons:" << std::endl;
    printPersons(prr);
    std::cout <<  std::endl;
    //
    std::cout << "Sorting of the Array:" << std::endl;
    std::sort(prr.begin(), prr.end(), compare);
    printPersons(prr);
    std::cout << std::endl;
    //
    std::cout << "The average age is: " << averageAge(prr) << " years!" << std::endl;
}

