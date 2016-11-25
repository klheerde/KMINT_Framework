#pragma once

#include "Vertex.h"
#include "AEntity.h"

class EntityVertex : public Vertex
{
private:
	std::vector<AEntity*> entities;

public:
	EntityVertex(int x, int y);

	std::vector<AEntity*> GetEntities() const;
	void AddEntity(AEntity* entity);
	void RemoveEntity(AEntity* entity);

public:
	static std::shared_ptr<EntityVertex> Cast(vtx_ptr vertex);
};
