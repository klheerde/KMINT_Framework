#pragma once

#include "AState.h"

class AEntity;

class AEntityState : public AState<void, AEntity*>
{ };

