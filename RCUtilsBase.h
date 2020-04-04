#pragma once

#pragma warning(disable:4577)

#pragma warning(push)
#pragma warning(disable:4530)
#include <stdio.h>
#include <string>
#include <list>
#include <vector>
#include <map>
#pragma warning(pop)

typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef int16_t		int16;
typedef uint32_t	uint32;
typedef int32_t		int32;
typedef uint64_t	uint64;
typedef int64_t		int64;

#define check(x) if (!(x)) __debugbreak();

template <typename T>
inline void MemZero(T& Struct)
{
	memset(&Struct, 0, sizeof(T));
}

template <typename T>
inline T Min(T A, T B)
{
	return A < B ? A : B;
}

template <typename T>
inline T Max(T A, T B)
{
	return A > B ? A : B;
}

inline float Clamp(float InMin, float Value, float InMax)
{
	return Min<float>(InMax, Max<float>(Value, InMin));
}

inline double Clamp(double InMin, double Value, double InMax)
{
	return Min<double>(InMax, Max<double>(Value, InMin));
}

template <typename T>
inline void ZeroMem(T& Object)
{
	const auto Size = sizeof(T);
	memset(&Object, 0, Size);
}
