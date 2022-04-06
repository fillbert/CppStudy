#pragma once
#include <stdint.h>
#include <math.h> 

class my_item
{
public:
	my_item(uint32_t weight, uint32_t cost, bool cabBeSplited = false) :weight(weight), cost(cost), refCostWeight((double)cost / (double)weight), canBeSplited(cabBeSplited = false)
	{

	}

	my_item()
	{
		weight = 0;
		cost = 0;
		canBeSplited = 0;
		refCostWeight = 0;
	}

	uint32_t getCost()		{ return cost; }
	uint32_t getWeight()	{ return weight; }
	double	 refCostWeight;

	const my_item& operator=(const my_item& lhs)
	{
		weight = lhs.weight;
		cost   = lhs.weight;
		canBeSplited = lhs.canBeSplited;
		refCostWeight = lhs.refCostWeight;
		return *this;
	};


	bool operator< (const my_item& a) const
	{
		return refCostWeight < a.refCostWeight;
	};

	//bool operator() (const item& a, const item& b)
	//{
	//	return a.refCostWeight < b.refCostWeight;
	//};

	//bool operator< ( item& a,  item& b)
	//{
	//	return a.getRef() < b.getRef();
	//};

	//friend bool operator> (item& a, item& b)
	//{
	//	return a.getRef() > b.getRef();
	//};

	//friend bool operator== (item& a, item& b)
	//{
	//	return a.getRef() == b.getRef();
	//};
	
private:
	uint32_t	weight;
	uint32_t	cost;
	bool		canBeSplited;
};

