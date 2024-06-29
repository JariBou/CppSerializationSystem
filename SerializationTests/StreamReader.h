#pragma once

#include "SerializationLibrary.h"
#include <filesystem>
#include <fstream>

namespace Serialization
{
	class StreamReader // TODO
	{

	public:

		virtual void Close() = 0;
		virtual bool IsStreamGood() const = 0;
		virtual uint64_t GetStreamPosition() = 0;
		virtual void SetStreamPosition(uint64_t position) = 0;

		virtual bool ReadData(char* destination, size_t size) = 0;

	private:
		std::filesystem::path m_Path;
		std::ifstream m_Stream;


	};
}

