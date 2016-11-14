#pragma once

#include "IGameObject.h"
#include "Vertex.h"

class Cow : public IGameObject
{
private:
	vtx_ptr vertex;
	SDL_Texture *texture;

public:
	Cow(vtx_ptr vertex);
	~Cow();

	void Update(float deltaTime) override;

	void NextVertex();

	vtx_ptr GetVertex() const;
};

