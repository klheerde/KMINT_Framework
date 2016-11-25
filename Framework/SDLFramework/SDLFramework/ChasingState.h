#pragma once

#include "WanderingState.h"

class ChasingState : public WanderingState
{
protected:
	AEntity* target;

public:
	ChasingState(AEntity* target);

	void Perform(AEntity* entity) const override;
};

