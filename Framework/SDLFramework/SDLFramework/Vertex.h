#pragma once

#include <memory>
#include <vector>
#include <map>
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

	std::vector<vtx_ptr> PathTo(vtx_ptr vertex) const;

	void AddEdge(edg_ptr edge);

	int GetX() const;
	int GetY() const;

	std::vector<edg_ptr> GetEdges() const;

private:
	static std::vector<vtx_ptr> MapToVector(std::map<vtx_ptr, vtx_ptr> const& map, vtx_ptr main);
};

