#pragma once

#include "IGameObject.h"
#include "Vertex.h"

class Rabbit : public IGameObject
{
private:
	vtx_ptr vertex;
	SDL_Texture *texture;

public:
	Rabbit(vtx_ptr vertex);
	~Rabbit();

	void Update(float deltaTime) override;

	void NextVertex();

	vtx_ptr GetVertex() const;
};

