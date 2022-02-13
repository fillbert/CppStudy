#include "Person.h"

int Person::getAssestmentScore(void)
{
	return score;
}

int  Person::getAge(void)
{
	return age;
}

void Person::printPerson(void)
{
	std::cout << name << " " << surname << " " << " age: " << age << " Assestment Score: " << score << std::endl;
}