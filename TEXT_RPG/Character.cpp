#include <iostream>
#include "Character.h"
#include "Item.h"
using namespace std;

unique_ptr<Character> Character::instance = nullptr;

Character::~Character()
{
    cout << "캐릭터는 사라집니다\n";
}

unique_ptr<Character>& Character::GetInstance(string name)
{
    if (!instance)
    {
        instance = unique_ptr<Character>(new Character(name));
    }
    return instance;
}

void Character::UseItem()
{
    if (mItems.empty())
    {
        cout << "인벤토리가 비었습니다\n";
        return;
    }
    
    mItems.back()->Use();
    mItems.pop_back();
}

void Character::AddItemToInventory(unique_ptr<Item> item)
{
    mItems.push_back(move(item));
}

void Character::ShowItems()
{
    for (const unique_ptr<Item>& item : mItems) // 레퍼런스
    {
        cout << item->GetName() << "\n";
    }
}

Character::Character(string name)
    :mName(name)
{

}