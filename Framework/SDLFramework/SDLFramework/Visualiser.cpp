#include "Visualiser.h"

Visualiser::Visualiser(FWApplication* app, grp_ptr graph) :
	app {app},
	graph {graph}
{ }

Visualiser::~Visualiser()
{ }

void Visualiser::Draw() const
{
	//NOTE: draw lines between vertices.
	for (edg_ptr edge : graph->GetEdges())
	{
		app->SetColor(Color(0, 0, 0, 255));
		app->DrawLine(
			edge->GetVertex(0)->GetX(), edge->GetVertex(0)->GetY(), 
			edge->GetVertex(1)->GetX(), edge->GetVertex(1)->GetY()
		);
	}

	//NOTE: draw circles for vertices.
	//TODO is on this diff color
	for (vtx_ptr vertex : graph->GetVertices())
	{
		app->SetColor(Color(0, 0, 255, 255));
		app->DrawCircle(vertex->GetX(), vertex->GetY(), 10, true);
	}

	//NOTE: draw movable objects.
	app->RenderGameObjects();

	//NOTE: set beackground.
	app->SetColor(Color(255, 255, 255, 255));
}
