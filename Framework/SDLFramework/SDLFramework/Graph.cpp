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
