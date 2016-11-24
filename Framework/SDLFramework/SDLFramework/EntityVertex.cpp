#include "EntityVertex.h"

EntityVertex::EntityVertex(int x, int y) :
	Vertex(x, y)
{ }

std::vector<AEntity*> EntityVertex::GetEntities() const
{
	return std::vector<AEntity*>(entities);
}

void EntityVertex::AddEntity(AEntity* entity)
{
	entities.push_back(entity);
}

void EntityVertex::RemoveEntity(AEntity* entity)
{
	auto end = entities.end();
	auto it = std::find(entities.begin(), end, entity);

	if (it != end)
	{
		using std::swap;
		//NOTE: swap to last element en remove.
		swap(*it, entities.back());
		entities.pop_back();
	}
}
