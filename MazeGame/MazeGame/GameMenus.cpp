#include "GameMenus.h"

GameMenus::GameMenus()
{
	isValid = false;
}

void GameMenus::PrintMainMenu()
{
	std::cout << "//////////////////////////////////////" << std::endl;
	std::cout << "/ WELCOME TO DUNGEON CRAWL!!!        /" << std::endl;
	std::cout << "/ To Start Your Adventure Press \"S\". /" << std::endl; 
	std::cout << "/ To Quit Game Press Q.              /" << std::endl;
	std::cout << "//////////////////////////////////////" << std::endl;
	std::cout << std::endl;
}
std::string GameMenus::InterpretInput(std::string input)
{
	if (input._Equal("S") || input._Equal("s"))
	{
		SetIsValid(true);
		return "start";
	}
	else if (input._Equal("Q") || input._Equal("q"))
	{
		SetIsValid(true);
		return "quit";
	}
	else
	{
		return "invalid";
	}
}

std::string GameMenus::GetMainMenuInput()
{
	std::string input;
	std::cout << "Enter Your Input." << std::endl;
	std::cin >> input;
	return input;
}

