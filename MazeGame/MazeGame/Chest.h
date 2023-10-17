#pragma once
#include "Interactables.h"
#include <iostream>

class Chest : public Interactables
{
public:
	virtual void Interact(Explorer* e) override;
	void OpenChest(Explorer* e);
	bool ValidateInput(std::string str);

public:
	bool GetIsLocked() { return isLocked; }
	void SetIsLocked(bool b) { isLocked = b; }
protected:
private:
	bool isLocked;
};