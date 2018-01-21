#pragma once

#include "RCUtilsBase.h"

namespace RCUtils
{
	inline std::vector<char> LoadFile(const char* Filename)
	{
		std::vector<char> Data;

		FILE* File = nullptr;
		fopen_s(&File, Filename, "rb");
		check(File);
		fseek(File, 0, SEEK_END);
		auto Size = ftell(File);
		fseek(File, 0, SEEK_SET);
		Data.resize(Size);
		fread(&Data[0], 1, Size, File);
		fclose(File);

		return Data;
	}
}
