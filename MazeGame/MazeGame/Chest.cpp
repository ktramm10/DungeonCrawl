#include "Chest.h"
#include <iostream>
void Chest::Interact(Explorer* e)
{
	std::string input;
	bool isValid = false;

	while (!isValid)
	{
		std::cout << "You come across a chest in this room. Would you like to open it?" << std::endl;
		std::cout << "Type \"Y\" for yes, \"N\" for no." << std::endl;
		std::cin >> input;
		
		isValid = ValidateInput(input);
	}
	if (input._Equal("Y") || input._Equal("y"))
	{
		OpenChest(e);
	}
	
}

void Chest::OpenChest(Explorer* e)
{
	if (e->GetKeys() > 0)
	{
		int currentKeys = e->GetKeys();
		e->SetKeys(currentKeys -= 1);
	}
	else
	{
		return;
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
