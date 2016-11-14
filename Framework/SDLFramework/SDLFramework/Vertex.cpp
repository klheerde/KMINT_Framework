#include "Vertex.h"
#include <ctime>
#include "Edge.h"

Vertex::Vertex(int x, int y) : 
	x {x}, 
	y {y}
{ }

Vertex::~Vertex()
{ }

vtx_ptr Vertex::NextRandom() const
{
	//NOTE: seed the time for random number.
	srand(time(NULL));
	//NOTE: get random edge index.
	int index = rand() % (edges.size());

	edg_ptr edge = edges[index];
	for (int i = 0; i < edge->GetAmount(); ++i)
	{
		vtx_ptr current = edge->GetVertex(i);
		if (current.get() != this)
			return current;
	}
}

void Vertex::AddEdge(edg_ptr edge)
{
	edges.push_back(edge);
}

int Vertex::GetX() const
{
	return x;
}

int Vertex::GetY() const
{
	return y;
}

std::vector<edg_ptr> Vertex::GetEdges() const
{
	return std::vector<edg_ptr> {edges};
}
