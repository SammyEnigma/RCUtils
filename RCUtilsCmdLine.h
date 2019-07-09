#pragma once

#include "RCUtilsBase.h"

namespace RCUtils
{
	struct FCmdLine
	{
		static inline FCmdLine& Get()
		{
			static FCmdLine Instance;
			return Instance;
		}

		FCmdLine()
		{
			check(__argc > 0);
			Exe = __argv[0];

			for (int32 i = 1; i < __argc; ++i)
			{
				FullCmdLine += __argv[i];
				FullCmdLine += " ";
				Args.push_back(__argv[i]);
			}
		}

		bool Contains(const char* Value) const
		{
			check(Value && *Value);
			for (const auto& Arg : Args)
			{
				if (!_strcmpi(Value, Arg.c_str()))
				{
					return true;
				}
			}

			return false;
		}

		uint32 TryGetIntPrefix(const char* Prefix, uint32 ValueIfMissing)
		{
			check(Prefix);
			uint32 PrefixLength = (uint32)strlen(Prefix);
			for (const auto& Arg : Args)
			{
				if (!_strnicmp(Arg.c_str(), Prefix, PrefixLength))
				{
					const char* IntString = Arg.c_str() + PrefixLength;
					return atoi(IntString);
				}
			}

			return ValueIfMissing;
		}

		float TryGetFloatPrefix(const char* Prefix, float ValueIfMissing)
		{
			check(Prefix);
			uint32 PrefixLength = (uint32)strlen(Prefix);
			for (const auto& Arg : Args)
			{
				if (!_strnicmp(Arg.c_str(), Prefix, PrefixLength))
				{
					const char* FloatString = Arg.c_str() + PrefixLength;
					return (float)atof(FloatString);
				}
			}

			return ValueIfMissing;
		}

		bool TryGetStringFromPrefix(const char* Prefix, const char*& OutValue)
		{
			check(Prefix);
			uint32 PrefixLength = (uint32)strlen(Prefix);
			for (const auto& Arg : Args)
			{
				if (!_strnicmp(Arg.c_str(), Prefix, PrefixLength))
				{
					OutValue = Arg.c_str() + PrefixLength;
					return true;
				}
			}

			return false;
		}

		std::string Exe;
		std::string FullCmdLine;
		std::vector<std::string> Args;
	};
}
