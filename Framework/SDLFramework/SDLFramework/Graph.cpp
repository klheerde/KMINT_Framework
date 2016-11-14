#include "Graph.h"

Graph::Graph()
{ }

Graph::~Graph()
{ }

void Graph::AddVertex(vtx_ptr vertex)
{
	vertices.push_back(vertex);
}

void Graph::AddEdge(edg_ptr edge)
{
	edges.push_back(edge);
}

vtx_ptr Graph::GetRoot() const
{
	try
	{
		return vertices.at(0);
	}
	catch (std::out_of_range&)
	{
		return nullptr;
	}
}

std::vector<vtx_ptr> Graph::GetVertices() const
{
	return std::vector<vtx_ptr> {vertices};
}

std::vector<edg_ptr> Graph::GetEdges() const
{
	return std::vector<edg_ptr> {edges};
}
