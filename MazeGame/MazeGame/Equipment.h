#pragma once
#include "Items.h"

class Equipment : public Items
{
public:
	Equipment();
	virtual void EquipItem(Explorer* e) override;
	virtual void AddToInventory(Explorer* e) override;
protected:

private:
	
};