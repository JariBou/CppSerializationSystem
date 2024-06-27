#include "Deserializer.h"
#include <iostream>

namespace Serialization {
	Deserializer::Deserializer(const std::filesystem::path& path) : BinaryStreamReader(path)
	{
	}
	bool Deserializer::ReadString(std::string& target)
	{
		size_t size = 0;

		ReadData((char*)&size, sizeof(size_t));
		target.resize(size);
		ReadData((char*)target.data(), sizeof(char) * size); 

		return true;
	}
}