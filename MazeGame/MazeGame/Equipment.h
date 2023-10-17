#pragma once
#include "Items.h"

class Equipment : public Items
{
public:
	Equipment();
	virtual void EquipItem() override;
	virtual void AddToInventory(Explorer* e) override;
protected:

private:
	
};