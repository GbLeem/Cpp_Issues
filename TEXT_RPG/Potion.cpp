#include <iostream>
#include "Potion.h"
#include "Character.h"

Potion::Potion(string name)
    :mName(name)
{

}

string Potion::GetName() const
{
    return mName;
}

void Potion::Use()
{
    cout << mName << " potion 사용\n";
}
