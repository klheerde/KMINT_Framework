#include "Rabbit.h"
#include <SDL_render.h>
#include <ctime>
#include "Edge.h"

Rabbit::Rabbit(vtx_ptr vertex) :
	vertex {vertex}
{
	texture = mApplication->LoadTexture("rabbit-3.png");
	SetTexture(texture);
	SetSize(50, 50);
}

Rabbit::~Rabbit()
{
	SDL_DestroyTexture(texture);
}

void Rabbit::Update(float deltaTime)
{
	SetOffset(vertex->GetX(), vertex->GetY());
}

void Rabbit::NextVertex()
{
	vertex = vertex->NextRandom();
}

vtx_ptr Rabbit::GetVertex() const
{
	return vertex;
}
