#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(string name);
	string GetName() const override;
	void Use() override;

private:
	string mName;
};