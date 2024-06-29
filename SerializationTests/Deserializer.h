#pragma once
#include "SerializationLibrary.h"
#include "BinaryStreamReader.h"

namespace Serialization 
{

    class Deserializer : public BinaryStreamReader
    {
		public:
			Deserializer(const std::filesystem::path& path);

			

			
    };
}

