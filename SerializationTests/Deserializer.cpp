#include "Deserializer.h"
#include <iostream>

#include "Settings.h"


namespace Serialization {

	Deserializer::Deserializer(const std::filesystem::path& path) : BinaryStreamReader(path)
	{
	}

}