#include "Chest.h"
#include <iostream>
#include "RNG.h"
#include <chrono>
#include "Sword.h"
#include "Axe.h"
#include "Mace.h"

Chest::Chest()
{
	rng = new RNG();
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
	switch (rng->GetNumInRange(1, 3))
	{
	case 1:
		loot = new Sword();
		break;
	case 2:
		loot = new Mace();
		break;
	case 3:
		loot = new Axe();
		break;
	}
}
void Chest::Interact(Explorer* e)
{
	std::string input;
	bool isValid = false;
	while (!isValid)
	{
		system("cls");
		std::cout << "         __________" << std::endl;
		std::cout << "        /\\____;;___\\" << std::endl;
		std::cout << "       | /         /" << std::endl;
		std::cout << "       `. ())oo() ." << std::endl;
		std::cout << "        |\\(%()*^^()^\\" << std::endl;
		std::cout << "       %| |-%-------|" << std::endl;
		std::cout << "      % \\ | %  ))   |" << std::endl;
		std::cout << "      %  \\|%________|" << std::endl;
		std::cout << "       %%%%" << std::endl;

		std::cout << "You come across a chest in this room. Would you like to open it?" << std::endl;
		std::cout << "Type \"Y\" for yes, \"N\" for no." << std::endl;

		std::cin >> input;
		if (ValidateInput(input))
		{
			isValid = ValidateInput(input);
		}
		else
		{
			std::cout << "Input was invalid" << std::endl;
			
		}
	}
	if (input._Equal("Y") || input._Equal("y"))
	{
		OpenChest(e);
	}
	
}

void Chest::OpenChest(Explorer* e)
{
	if (isLocked)
	{
		if (e->GetKeys() > 0)
		{
			int currentKeys = e->GetKeys();
			e->SetKeys(currentKeys -= 1);
			std::cout << "You open the chest and find a " << loot->GetItemName() << ". You add it to your inventory." << std::endl;
		}
		else
		{
			std::cout << "This chest is locked and you do not have a key." << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "You open the chest and find a " << loot->GetItemName() << ". You add it to your inventory." << std::endl;
		e->AddToInventory(loot);
	}
}

bool Chest::ValidateInput(std::string str)
{
	if (str._Equal("Y") || str._Equal("y") || str._Equal("N") || str._Equal("n"))
	{
		return true;
	}
	else
	{
		return false;
	}
}
