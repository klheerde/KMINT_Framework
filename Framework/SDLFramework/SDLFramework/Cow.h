#pragma once

#include "IGameObject.h"
#include "Vertex.h"
#include "Rabbit.h"

class Cow : public IGameObject
{
private:
	vtx_ptr vertex;
	SDL_Texture *texture;

	Rabbit const* target;

public:
	Cow(vtx_ptr vertex, Rabbit const* target);
	~Cow();

	void Update(float deltaTime) override;

	void StepRandom();
	void StepSearch();

	vtx_ptr GetVertex() const;
};

