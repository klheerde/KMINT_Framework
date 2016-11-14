#include "Cow.h"
#include <SDL_render.h>
#include <ctime>
#include "Edge.h"

Cow::Cow(vtx_ptr vertex, Rabbit const* target) :
	vertex {vertex},
	target {target}
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

void Cow::StepRandom()
{
	vertex = vertex->NextRandom();
}

void Cow::StepSearch()
{
	//TODO first not include this
	auto temp = vertex->PathTo(target->GetVertex());
	vertex = temp[1];
}

vtx_ptr Cow::GetVertex() const
{
	return vertex;
}
