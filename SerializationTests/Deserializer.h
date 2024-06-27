#pragma once
#include "FileStreamReader.h"

namespace Serialization 
{

    class Deserializer : public BinaryStreamReader
    {
		public:
			Deserializer(const std::filesystem::path& path);

			bool ReadString(std::string& target);

			// Ok so templates need to go on the .h
			template<typename T>
			bool ReadRaw(T& target)
			{
				ReadData((char*)&target, sizeof(T));
				return true;
			}

			template<typename T>
			bool ReadObject(T& targetObj)
			{
				T::Deserialize(this, targetObj);
				return true;
			}
    };
}

