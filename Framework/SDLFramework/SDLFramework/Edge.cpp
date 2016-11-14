#include "Edge.h"

Edge::Edge(vtx_ptr one, vtx_ptr two, int weight) :
	weight {weight}
{
	vertices.push_back(one);
	vertices.push_back(two);

	edg_ptr self {this};
	one->AddEdge(self);
	two->AddEdge(self);
}

Edge::~Edge()
{ }

vtx_ptr Edge::GetVertex(int index) const
{
	try
	{
		return vertices.at(index);
	}
	catch (std::out_of_range&)
	{
		return nullptr;
	}
}

std::vector<vtx_ptr> Edge::GetVertices() const
{
	return std::vector<vtx_ptr> {vertices};
}

int Edge::GetWeight() const
{
	return weight;
}
