#include "Cow.h"
#include <SDL_render.h>
#include <ctime>
#include "Edge.h"

Cow::Cow(vtx_ptr vertex) :
	vertex {vertex}
{
	texture = mApplication->LoadTexture("lemmling_Cartoon_cow.png");
	SetTexture(texture);
	SetSize(50, 50);
}

Cow::~Cow()
{
	SDL_DestroyTexture(texture);
}

void Cow::Update(float deltaTime)
{
	SetOffset(vertex->GetX(), vertex->GetY());
}

void Cow::NextVertex()
{
	vertex = vertex->NextRandom();
}

vtx_ptr Cow::GetVertex() const
{
	return vertex;
}
