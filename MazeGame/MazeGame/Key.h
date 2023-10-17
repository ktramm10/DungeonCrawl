#pragma once
#include "Interactables.h"
#include "Explorer.h"
class Key : public Interactables
{
public:
	Key();
	virtual void Interact(Explorer* e) override;
protected:
private:

};