#pragma once

#include <filesystem>
#include "FileStreamWriter.h"

namespace Serialization
{

	class Serializer : public BinaryStreamWriter
	{

		public:
			Serializer(const std::filesystem::path& path);

			bool WriteString(const std::string content);


			// Ok so templates need to go on the .h
			template<typename T>
			bool WriteRaw(const T& content)
			{
				WriteData((char*)&content, sizeof(T));
				return true;
			}

			template<typename T>
			bool WriteObject(const T& obj)
			{
				T::Serialize(this, obj);
				return true;
			}
	};

}
