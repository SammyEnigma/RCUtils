#pragma once

#include "RCUtilsBase.h"

inline bool IsPowerOfTwo(uint64 N)
{
	return (N != 0) && !(N & (N - 1));
}

template <typename T>
inline T Align(T Value, T Alignment)
{
	check(IsPowerOfTwo(Alignment));
	return (Value + (Alignment - 1)) & ~(Alignment - 1);
}
