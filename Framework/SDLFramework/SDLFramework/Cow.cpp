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
//	std::vector<edg_ptr> edges = vertex->GetEdges();
//	//NOTE: seed the time for random number.
//	srand(time(NULL));
//	//NOTE: get random edge index.
//	int index = rand() % (edges.size());
//
//	edg_ptr edge = edges[index];
//	for (int i = 0; i < edge->GetAmount(); ++i)
//	{
//		vtx_ptr current = edge->GetVertex(i);
//		if (current != vertex)
//		{
//			vertex = current;
//			break;
//		}
//	}
}

vtx_ptr Cow::GetVertex() const
{
	return vertex;
}
