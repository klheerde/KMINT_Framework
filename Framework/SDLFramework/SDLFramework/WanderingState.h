#pragma once

#include "AEntityState.h"

class WanderingState : public AEntityState
{
public:
	void Perform(AEntity* cow) const override;
};

