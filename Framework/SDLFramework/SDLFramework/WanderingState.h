#pragma once

#include "AEntityState.h"

class WanderingState : public AEntityState
{
public:
	void Perform(AEntity* entity) const override;

protected:
	void CheckForDrop(AEntity* entity) const;
};

