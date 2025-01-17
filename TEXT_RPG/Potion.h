#pragma once
#include "Item.h"

class Potion : public Item
{
public:
	Potion(string name);
	string GetName() const override;
	void Use() override;

private:
	string mName;
};