#pragma once
#include <iostream>
class GameMenus
{
public:
	GameMenus();
	void PrintMainMenu();
	std::string InterpretInput(std::string input);
	std::string GetMainMenuInput();
public:
	bool GetIsValid() { return isValid; }
	void SetIsValid(bool b) { isValid = b; }
protected:

private:
	bool isValid;
};