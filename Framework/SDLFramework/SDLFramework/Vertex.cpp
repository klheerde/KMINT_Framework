#include "Vertex.h"
#include <ctime>
#include "Edge.h"
#include "Random.h"
#include <map>


Vertex::Vertex(int x, int y) : 
	x {x}, 
	y {y}
{ }

vtx_ptr Vertex::NextRandom() const
{
	int index = Random::GetRandom(edges.size());

	for (vtx_ptr vertex : edges[index]->GetVertices())
	{
		if (vertex.get() != this)
			return vertex;
	}
}

std::vector<vtx_ptr> Vertex::PathTo(vtx_ptr vertex) const
{
	using std::map;
	using std::vector;

	map<vtx_ptr, vtx_ptr> parents;
	map<vtx_ptr, bool> visited;
	map<vtx_ptr, int> weights;
	vector<vtx_ptr> queue;

	//NOTE: hack self pointer.
	for (vtx_ptr v : GetEdges()[0]->GetVertices())
	{
		if (v.get() == this)
		{
			weights[v] = 0;
			queue.push_back(v);
			break;
		}
	}

	while (!queue.empty())
	{
		vtx_ptr current = queue.front();
		
		if (current == vertex)
			return MapToVector(parents, current);

		queue.erase(queue.begin());
		visited[current] = true;

		int currentWeight = weights[current];
		for (edg_ptr edge : current->GetEdges())
		{
			int totalWeight = currentWeight + edge->GetWeight();
			for (vtx_ptr adjacent : edge->GetVertices())
			{
				if (visited.count(adjacent))
					continue;

				int x = adjacent->GetX() - current->GetX();
				int y = adjacent->GetY() - current->GetY();
				//NOTE: calculate distance between vertices.
				int projectedAddition = std::sqrt(x * x + y * y);

				int projectedWeight = totalWeight + projectedAddition;

				if (weights.count(adjacent) && projectedWeight > weights[adjacent])
					continue;

				weights[adjacent] = projectedWeight;
				parents[adjacent] = current;

				//NOTE: if already in queu, remove.
				auto exists = find(queue.begin(), queue.end(), adjacent);
				if (exists != queue.end())
					queue.erase(exists);

				//NOTE: find current place in queue to insert.
				auto insertIndex = queue.begin();
				for (; insertIndex != queue.end(); ++insertIndex)
				{
					if (weights[*insertIndex] > projectedWeight)
						break;
				}

				queue.insert(insertIndex, adjacent);
			}
		}
	}
	
	throw std::exception {"Not found."};
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

std::vector<vtx_ptr> Vertex::MapToVector(std::map<vtx_ptr, vtx_ptr> const& map, vtx_ptr main)
{
	std::vector<vtx_ptr> path;

	//NOTE: only contains search (current) object if path valid and result contains key.
	if (map.count(main))
	{
		//NOTE: result contains key.
		path.push_back(main);
		while (map.count(main))
		{
			main = map.at(main);
			path.push_back(main);
		}
	}

	reverse(path.begin(), path.end());
	return path;
}
