#pragma once
#include "AEntityState.h"

class IdleState : public AEntityState
{
public:
	void Perform(AEntity*) const override;
};

