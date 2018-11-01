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

		std::string Exe;
		std::string FullCmdLine;
		std::vector<std::string> Args;
	};
}
