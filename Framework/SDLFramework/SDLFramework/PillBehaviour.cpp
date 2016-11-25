#include "PillBehaviour.h"
#include "AEntity.h"
#include "WanderingState.h"
#include "Cow.h"
#include "IdleState.h"

void PillBehaviour::Perform(AEntity* entity) const
{
	Cow* cow = dynamic_cast<Cow*>(entity);

	//NOTE: if is rabbit, be idle.
	if (cow == nullptr)
		entity->SetState(new IdleState);
	//NOTE: if is cow, wander.
	else
		entity->SetState(new WanderingState);
}
