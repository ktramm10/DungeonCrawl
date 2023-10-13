#pragma once
#include "MapSite.h"
class Wall : public Mapsite
{
public:
	Wall();

	virtual void Enter(Explorer* e) override;
	virtual bool IsDoor() override;
};