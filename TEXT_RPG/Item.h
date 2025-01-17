#pragma once
#include <string>
using namespace std;

class Item
{
public:	
	virtual string GetName() const = 0;
	virtual void Use() = 0;
};