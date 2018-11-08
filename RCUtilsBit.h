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


// Naive implementation some compilers compile out to intrinsics
template <typename T>
inline uint32 GetNumberOfBitsSet(T N)
{
	uint32 Count = 0;
	while (N > 0)
	{
		if (N & 1)
		{
			++Count;
		}

		N = N >> (T)1;
	}

	return Count;
}
