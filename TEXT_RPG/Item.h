#pragma once
#include <string>
using namespace std;

class Item
{
public:	
	virtual ~Item() = default; //key point
	virtual string GetName() const = 0;
	virtual void Use() = 0;
};