#pragma once
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Item;

class Character
{
public:
	Character(const Character& other) = delete;
	Character& operator= (const Character&) = delete;	
	~Character();
	static unique_ptr<Character>& GetInstance(string name);
	void UseItem();
	void AddItemToInventory(unique_ptr<Item> item);
	void ShowItems();

private:
	Character(string name);

	static unique_ptr<Character> instance;
	string mName;
	vector<unique_ptr<Item>> mItems;
};