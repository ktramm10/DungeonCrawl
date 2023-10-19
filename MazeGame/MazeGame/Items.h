#pragma once
#include "ItemTypes.h"
#include "Explorer.h"
#include <string>

class Items
{
public:
	virtual void EquipItem(Explorer* e) {}
	virtual void AddToInventory(Explorer* e) {}
	EItemTypes GetItemID() { return ItemID; }
	void SetItemID(EItemTypes type) { ItemID = type; }
	std::string GetItemName() { return ItemName; }
	void SetItemName(std::string str) { ItemName = str; }
protected:

private:
	EItemTypes ItemID;
	std::string ItemName;
};