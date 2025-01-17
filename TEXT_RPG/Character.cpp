#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "Character.h"
#include "Item.h"
using namespace std;

#ifdef _DEBUG
    #define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

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

    Item* useItem = mItems.back(); 
    mItems.pop_back();
    useItem->Use();

    delete useItem;
}

void Character::AddItemToInventory(Item* item)
{
    mItems.push_back(item);
}

void Character::ShowItems()
{
    for (const Item* item : mItems)
    {
        cout << item->GetName() << "\n";
    }
}

void Character::DestroyItems()
{
    for (Item* item : mItems)
    {
        delete item;
    }
    mItems.clear();
}

Character::Character(string name)
    :mName(name)
{

}