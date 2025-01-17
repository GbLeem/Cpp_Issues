#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Potion.h"
using namespace std;

#ifdef _DEBUG
	#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(170);

	cout << "이름 입력: ";
	string name;
	cin >> name;
	Character* playerCharacter = Character::GetInstance(name);
	
	Item* newItem = nullptr;
	
	for (int i = 0; i < 3; ++i)
	{
		string itemName;
		cout << "아이템 이름 입력: ";
		cin >> itemName;
		
		//홀수
		if (i % 2 != 0)
			newItem = new Weapon(itemName);
		else
			newItem = new Potion(itemName);		

		playerCharacter->AddItemToInventory(newItem);
	}		

	int menuIdx = -1;

	while (1)
	{
		cout << "== menu ==\n";
		cout << "1 아이템 사용\n";
		cout << "2 아이템 보기\n";
		cout << "3 ...\n";
		cout << "0 종료\n";
		cout << "\n\n메뉴를 입력하세요: ";

		cin >> menuIdx;

		if (cin.fail() || menuIdx < 0 || menuIdx > 3)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요: ";

			system("cls");
		}
		

		switch (menuIdx)
		{
		case 1:
			system("cls");
			cout << "== 아이템 사용 ==\n";
			playerCharacter->UseItem();
			break;
		case 2:
			system("cls");
			cout << "== 아이템 보기 ==\n";
			playerCharacter->ShowItems();
			break;
		case 3:
			system("cls");
			cout << "...\n";
			break;
		default:
			break;

		case 0:
			system("cls");			
			cout << "게임 종료!\n";	
			playerCharacter->DestroyItems();
			return 0;
		}

		system("pause");
		system("cls");
	}

}