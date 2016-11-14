#pragma once

#include <memory>
#include <vector>
//#include "Edge.h"

class Edge;
typedef std::shared_ptr<Edge> edg_ptr;

class Vertex;
typedef std::shared_ptr<Vertex> vtx_ptr;

class Vertex
{
private:
	int x;
	int y;

	std::vector<edg_ptr> edges;

public:

	Vertex(int x, int y);
	~Vertex();

	vtx_ptr NextRandom() const;

	void AddEdge(edg_ptr edge);

	int GetX() const;
	int GetY() const;
	std::vector<edg_ptr> GetEdges() const;
};

