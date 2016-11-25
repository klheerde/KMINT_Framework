#include "AEntity.h"
#include "WanderingState.h"
#include "EntityVertex.h"
#include <memory>

AEntity::AEntity(vtx_ptr vertex, std::string const texturePath) :
	vertex {vertex},
	state {nullptr}
{
	texture = mApplication->LoadTexture(texturePath);
	SetTexture(texture);
	SetSize(50, 50);
}

AEntity::~AEntity()
{
	SetState(nullptr);
	mApplication->RemoveRenderable(this);
//	mApplication->RemoveTexture(texture);
}

void AEntity::StepRandom(int amount)
{
	for (int i = 0; i < amount; ++i)
		SetVertex(vertex->NextRandom());
}

void AEntity::Update(float deltaTime)
{
	SetOffset(vertex->GetX(), vertex->GetY());
}

void AEntity::SetState(AEntityState* state)
{
	delete this->state;
	this->state = state;
}

void AEntity::SetVertex(vtx_ptr vertex)
{
	EntityVertex::Cast(this->vertex)->RemoveEntity(this);
	this->vertex = vertex;
	EntityVertex::Cast(vertex)->AddEntity(this);
}

AEntityState const* AEntity::GetState() const
{
	return state;
}

vtx_ptr AEntity::GetVertex() const
{
	return vertex;
}
