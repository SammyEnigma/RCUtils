#pragma once

#include "RCUtilsBase.h"

namespace RCUtils
{
	inline std::vector<char> LoadFileToArray(const char* Filename, bool* OutSuccess = nullptr)
	{
		std::vector<char> OutData;
		bool bSuccess = false;
		FILE* File = nullptr;
		fopen_s(&File, Filename, "rb");
		if (File)
		{
			fseek(File, 0, SEEK_END);
			long Size = ftell(File);
			fseek(File, 0, SEEK_SET);
			check(Size > 0);
			OutData.resize(Size);
			fread(&OutData[0], 1, Size, File);
			fclose(File);
			bSuccess = true;
		}

		if (OutSuccess)
		{
			*OutSuccess = bSuccess;
		}

		return OutData;
	}

	inline std::string LoadFileToString(const char* Filename, bool* OutSuccess = nullptr)
	{
		bool bSuccess = false;
		std::string OutString;
		FILE* File;
		fopen_s(&File, Filename, "rb");
		if (File)
		{
			fseek(File, 0, SEEK_END);
			long Size = ftell(File);
			check(Size > 0);
			std::vector<char> Data;
			Data.resize(Size);
			fseek(File, 0, SEEK_SET);
			fread(&Data[0], 1, Size, File);
			fclose(File);
			OutString.resize(Size);
			OutString = &Data[0];
			bSuccess = true;
		}

		if (OutSuccess)
		{
			*OutSuccess = bSuccess;
		}

		return OutString;
	}
}
