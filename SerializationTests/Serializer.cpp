#include "Serializer.h"
#include <iostream>
#include <string>

namespace Serialization 
{

	Serializer::Serializer(const std::filesystem::path& path) : BinaryStreamWriter(path)
	{
	}
	
}
