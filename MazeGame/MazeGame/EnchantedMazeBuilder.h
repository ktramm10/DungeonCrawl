#pragma once
#include "StandardMazeBuilder.h"


class EnchantedMazeBuilder : public StandardMazeBuilder
{
public:
	EnchantedMazeBuilder();
	virtual void BuildRoom(int roomNo) override;

protected:

};