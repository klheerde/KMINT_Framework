
#pragma once

#include "IGameObject.h"
#include "Vertex.h"
#include "AEntityState.h"

class AEntity : public IGameObject
{
protected:
	AEntityState* state;
	vtx_ptr vertex;
	SDL_Texture *texture;

public:
	AEntity(vtx_ptr vertex, std::string const texturePath);
	~AEntity();

	void StepRandom(int amount = 1);

	void Update(float deltaTime) override;

	//SETTERS
	void SetState(AEntityState* state);
	void SetVertex(vtx_ptr vertex);

	//GETTERS
	AEntityState const& GetState() const; //TODO const&, you sure?
	vtx_ptr GetVertex() const;

public:
	/**
	* Casts Vertex* to EntityVertex* and adds AEntity*.
	*/
	static void AddEntity(vtx_ptr vertex, AEntity* entity);

	/**
	* Casts Vertex* to EntityVertex* and removes AEntity*.
	*/
	static void RemoveEntity(vtx_ptr vertex, AEntity* entity);

	/**
	* Casts Vertex* to EntityVertex* and gets AEntity*.
	*/
	static std::vector<AEntity*> GetEntities(vtx_ptr vertex);
};
