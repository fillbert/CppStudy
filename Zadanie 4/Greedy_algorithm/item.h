#pragma once
#include <stdint.h>
#include <math.h> 

class item
{
public:
	item(uint32_t weight, uint32_t cost, bool cabBeSplited = false) :weight(weight), cost(cost), refCostWeight((double)cost / (double)weight), cabBeSplited(cabBeSplited = false)
	{

	}

	uint32_t getCost()		{ return cost; }
	uint32_t getWeight()	{ return weight; }
	double   getRef()		{ return refCostWeight; }

	item operator=(const item& lhs)
	{
		return *this;
	};

	friend bool operator< (  item& a,  item& b)
	{
		return a.getRef() < b.getRef();
	};

	//friend bool operator> (item& a, item& b)
	//{
	//	return a.getRef() > b.getRef();
	//};
	//friend bool operator== (item& a, item& b)
	//{
	//	return a.getRef() == b.getRef();
	//};
	
private:
	const uint32_t weight;
	const uint32_t cost;
	const double refCostWeight;
	const bool cabBeSplited;
};

