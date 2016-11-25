#include "WanderingState.h"
#include "AEntity.h"
#include "EntityVertex.h"
#include "ADropEntity.h"

void WanderingState::Perform(AEntity* entity) const
{
	entity->StepRandom();
	CheckForDrop(entity);
}

void WanderingState::CheckForDrop(AEntity* entity) const
{
	std::shared_ptr<EntityVertex> entityVertex {EntityVertex::Cast(entity->GetVertex())};
	std::vector<AEntity*> entities;

	if ((entities = entityVertex->GetEntities()).size() > 1)
	{
		for (int i = 0; i < entities.size(); ++i)
		{
			AEntity* e = entities[i];
			if (e == entity)
				continue;

			ADropEntity* drop = dynamic_cast<ADropEntity*>(e);
			//NOTE: if is animal replaced earlier.
			if (drop != nullptr)
			{
				if (drop->GetState() != nullptr)
					drop->GetState()->Perform(entity);
				entityVertex->RemoveEntity(drop);
				delete drop;
			}
		}
	}
}
