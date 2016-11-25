#pragma once

#include "AEntity.h"

class ADropEntity : public AEntity
{
public:
	ADropEntity(vtx_ptr vertex, std::string const texturePath);
};
