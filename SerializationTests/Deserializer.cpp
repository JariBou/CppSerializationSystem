#include "Deserializer.h"
#include <iostream>

namespace Serialization {
	Deserializer::Deserializer(const std::filesystem::path& path) : FileStreamReader(path)
	{
	}
	bool Deserializer::ReadString(std::string& target)
	{
		size_t size = 0;

		ReadData((char*)&size, sizeof(size_t));
		std::cout << size << std::endl;
		ReadData((char*)&target, sizeof(char) * size); // raises a memory access violation | wait what? its not this?
		// Ok so ReadData correctly reads the full string
		// But it doesn't come back up here
		return true;
	}
}