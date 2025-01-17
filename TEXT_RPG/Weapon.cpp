#include <iostream>
#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(string name)
    :mName(name)
{

}

string Weapon::GetName() const
{
    return mName;
}

void Weapon::Use()
{
    cout << mName << " weapon 사용\n";
}
