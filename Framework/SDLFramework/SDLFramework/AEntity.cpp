#include "AEntity.h"
#include "WanderingState.h"

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

void AEntity::StepRandom()
{
	vertex = vertex->NextRandom();
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
	this->vertex = vertex;
}

AEntityState const& AEntity::GetState() const
{
	return *state;
}

vtx_ptr AEntity::GetVertex() const
{
	return vertex;
}
