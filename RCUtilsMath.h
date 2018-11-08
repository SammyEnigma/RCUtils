#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "RCUtilsBase.h"

inline float ToRadians(float Deg)
{
	return Deg * ((float)M_PI / 180.0f);
}

inline float ToDegrees(float Rad)
{
	return Rad * (180.0f / (float)M_PI);
}

struct FVector2
{
	union
	{
		float Values[2];
		struct
		{
			float x, y;
		};
		struct
		{
			float u, v;
		};
	};

	static FVector2 GetZero()
	{
		FVector2 New;
		MemZero(New);
		return New;
	}
};

struct FVector3
{
	union
	{
		float Values[3];
		struct
		{
			float x, y, z;
		};
		struct
		{
			float u, v, w;
		};
	};

	void Set(float InX, float InY, float InZ)
	{
		x = InX;
		y = InY;
		z = InZ;
	}

	static FVector3 GetZero()
	{
		FVector3 New;
		MemZero(New);
		return New;
	}

	FVector3 Mul(float f) const
	{
		FVector3 V;
		V.x = x * f;
		V.y = y * f;
		V.z = z * f;
		return V;
	}

	FVector3 Add(const FVector3& V) const
	{
		FVector3 O;
		O.x = x + V.x;
		O.y = y + V.y;
		O.z = z + V.z;
		return O;
	}
};

inline FVector3 Cross(const FVector3& A, const FVector3& B)
{
	FVector3 R;
	float u1 = A.x;
	float u2 = A.y;
	float u3 = A.z;
	float v1 = B.x;
	float v2 = B.y;
	float v3 = B.z;
	R.Set(u2*v3 - u3*v2, u3*v1 - u1*v3, u1*v2 - u2*v1);
	return R;
}

struct FVector4
{
	union
	{
		float Values[4];
		struct
		{
			float x, y, z, w;
		};
	};

	static FVector4 GetZero()
	{
		FVector4 New;
		MemZero(New);
		return New;
	}

	FVector4() {}

	FVector4(const FVector3& V, float W)
	{
		x = V.x;
		y = V.y;
		z = V.z;
		w = W;
	}

	FVector4(float InX, float InY, float InZ, float InW)
	{
		x = InX;
		y = InY;
		z = InZ;
		w = InW;
	}

	void Set(float InX, float InY, float InZ, float InW)
	{
		x = InX;
		y = InY;
		z = InZ;
		w = InW;
	}

	FVector4 Add(const FVector3& V) const
	{
		FVector4 O;
		O.x = x + V.x;
		O.y = y + V.y;
		O.z = z + V.z;
		O.w = w;
		return O;
	}
};

struct FMatrix3x3
{
	union
	{
		float Values[9];
		FVector3 Rows[3];
	};

	FMatrix3x3() {}

	FMatrix3x3 GetTranspose() const
	{
		FMatrix3x3 New;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				New.Values[i * 3 + j] = Values[j * 3 + i];
			}
		}

		return New;
	}

	static FMatrix3x3 GetZero()
	{
		FMatrix3x3 New;
		MemZero(New);
		return New;
	}

	static FMatrix3x3 GetIdentity()
	{
		FMatrix3x3 New;
		MemZero(New);
		New.Values[0] = 1;
		New.Values[4] = 1;
		New.Values[8] = 1;
		return New;
	}

	static FMatrix3x3 GetRotationX(float AngleRad)
	{
		FMatrix3x3 New;
		MemZero(New);
		float Cos = cos(AngleRad);
		float Sin = sin(AngleRad);
		New.Rows[0].x = 1;
		New.Rows[1].y = Cos;
		New.Rows[1].z = -Sin;
		New.Rows[2].y = Sin;
		New.Rows[2].z = Cos;
		return New;
	}

	static FMatrix3x3 GetRotationY(float AngleRad)
	{
		FMatrix3x3 New;
		MemZero(New);
		float Cos = cos(AngleRad);
		float Sin = sin(AngleRad);
		New.Rows[0].x = Cos;
		New.Rows[0].z = Sin;
		New.Rows[1].y = 1;
		New.Rows[2].x = -Sin;
		New.Rows[2].z = Cos;
		return New;
	}

	static FMatrix3x3 GetRotationZ(float AngleRad)
	{
		FMatrix3x3 New;
		MemZero(New);
		float Cos = cos(AngleRad);
		float Sin = sin(AngleRad);
		New.Rows[0].x = Cos;
		New.Rows[0].y = -Sin;
		New.Rows[1].x = Sin;
		New.Rows[1].y = Cos;
		New.Rows[2].z = 1;
		return New;
	}

	void Set(int32 Row, int32 Col, float Value)
	{
		Values[Row * 3 + Col] = Value;
	}
};

struct FMatrix4x4
{
	union
	{
		float Values[16];
		FVector4 Rows[4];
	};

	FMatrix4x4() {}

	FMatrix4x4 GetTranspose() const
	{
		FMatrix4x4 New;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				New.Values[i * 4 + j] = Values[j * 4 + i];
			}
		}

		return New;
	}

	static FMatrix4x4 GetZero()
	{
		FMatrix4x4 New;
		MemZero(New);
		return New;
	}

	static FMatrix4x4 GetIdentity()
	{
		FMatrix4x4 New;
		MemZero(New);
		New.Values[0] = 1;
		New.Values[5] = 1;
		New.Values[10] = 1;
		New.Values[15] = 1;
		return New;
	}

	static FMatrix4x4 GetRotationX(float AngleRad)
	{
		FMatrix4x4 New;
		MemZero(New);
		float Cos = cos(AngleRad);
		float Sin = sin(AngleRad);
		New.Rows[0].x = 1;
		New.Rows[1].y = Cos;
		New.Rows[1].z = -Sin;
		New.Rows[2].y = Sin;
		New.Rows[2].z = Cos;
		New.Rows[3].w = 1;
		return New;
	}

	static FMatrix4x4 GetRotationY(float AngleRad)
	{
		FMatrix4x4 New;
		MemZero(New);
		float Cos = cos(AngleRad);
		float Sin = sin(AngleRad);
		New.Rows[0].x = Cos;
		New.Rows[0].z = Sin;
		New.Rows[1].y = 1;
		New.Rows[2].x = -Sin;
		New.Rows[2].z = Cos;
		New.Rows[3].w = 1;
		return New;
	}

	static FMatrix4x4 GetRotationZ(float AngleRad)
	{
		FMatrix4x4 New;
		MemZero(New);
		float Cos = cos(AngleRad);
		float Sin = sin(AngleRad);
		New.Rows[0].x = Cos;
		New.Rows[0].y = -Sin;
		New.Rows[1].x = Sin;
		New.Rows[1].y = Cos;
		New.Rows[2].z = 1;
		New.Rows[3].w = 1;
		return New;
	}

	void Set(int32 Row, int32 Col, float Value)
	{
		Values[Row * 4 + Col] = Value;
	}
};

inline FMatrix4x4 CalculateProjectionMatrix(float FOVRadians, float Aspect, float NearZ, float FarZ)
{
	const float HalfTanFOV = (float)tan(FOVRadians / 2.0);
	FMatrix4x4 New = FMatrix4x4::GetZero();
	New.Set(0, 0, 1.0f / (Aspect * HalfTanFOV));
	New.Set(1, 1, 1.0f / HalfTanFOV);
	New.Set(2, 3, -1);
	New.Set(2, 2, FarZ / (NearZ - FarZ));
	New.Set(3, 2, -(FarZ * NearZ) / (FarZ - NearZ));
	return New;
}

inline uint32 PackNormalToU32(const FVector3& V)
{
	uint32 Out = 0;
	Out |= ((uint32)((V.x + 1.0f) * 127.5f) & 0xff) << 0;
	Out |= ((uint32)((V.y + 1.0f) * 127.5f) & 0xff) << 8;
	Out |= ((uint32)((V.z + 1.0f) * 127.5f) & 0xff) << 16;
	return Out;
}