#pragma once

#include <stdio.h>
#include <vector>

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
	ZeroMemory(&Struct, sizeof(T));
}
