#include "Serializer.h"
#include <iostream>
#include <string>

namespace Serialization 
{

	Serializer::Serializer(const std::filesystem::path& path) : FileStreamWriter(path)
	{
	}

	bool Serializer::WriteString(const std::string content)
	{
		size_t size = content.size();

		WriteData((char*)&size, sizeof(size_t));
		std::cout << "size = " << sizeof(char) * size << std::endl;
		WriteData((char*)content.data(), sizeof(char) * size);

		return true;
	}
	
}
