
#pragma once

template<typename Return = void, typename Param = void>
class AState
{
public:
	virtual Return Perform(Param) const = 0;
};

