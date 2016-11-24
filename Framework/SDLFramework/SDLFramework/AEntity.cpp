#include "AEntity.h"
#include "WanderingState.h"
#include "EntityVertex.h"
#include <memory>

AEntity::AEntity(vtx_ptr vertex, std::string const texturePath) :
	vertex {vertex}
{
	texture = mApplication->LoadTexture(texturePath);
	SetState(new WanderingState);
	SetTexture(texture);
	SetSize(50, 50);
}

AEntity::~AEntity()
{
	SetState(nullptr);
	mApplication->RemoveTexture(texture);
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
	RemoveEntity(this->vertex, this);
	this->vertex = vertex;
	AddEntity(vertex, this);
}

AEntityState const& AEntity::GetState() const
{
	return *state;
}

vtx_ptr AEntity::GetVertex() const
{
	return vertex;
}

//TODO repeat code
void AEntity::AddEntity(vtx_ptr vertex, AEntity* entity)
{
	std::shared_ptr<EntityVertex> entityVertex = std::static_pointer_cast<EntityVertex>(vertex);
	if (entityVertex != nullptr)
		entityVertex->AddEntity(entity);
}

void AEntity::RemoveEntity(vtx_ptr vertex, AEntity* entity)
{
	std::shared_ptr<EntityVertex> entityVertex = std::static_pointer_cast<EntityVertex>(vertex);
	if (entityVertex != nullptr)
		entityVertex->RemoveEntity(entity);
}

std::vector<AEntity*> AEntity::GetEntities(vtx_ptr vertex)
{
	std::shared_ptr<EntityVertex> entityVertex = std::static_pointer_cast<EntityVertex>(vertex);
	if (entityVertex == nullptr)
		return {};
	return entityVertex->GetEntities();
}
