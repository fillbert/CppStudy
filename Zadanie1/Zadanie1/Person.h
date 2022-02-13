#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

class Person
{
public:

	Person() {};
	Person(std::string name, std::string surname, int adge, int score) : name(name), surname(surname), age(age), score(score)
	{
	}

	int getAssestmentScore();
	int  getAge();
	void printPerson();


private:
	std::string name;
	std::string surname;
	int age;
	int score;
};

