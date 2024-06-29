#pragma once
#include "SerializationLibrary.h"

#include <filesystem>
#include "BinaryStreamWriter.h"

namespace Serialization
{

	class Serializer : public BinaryStreamWriter
	{

		public:
			Serializer(const std::filesystem::path& path);

			template<typename T>
			bool WriteObject(const T& value) {
#if IsEditor
				binaryStreamWriter.WriteObject(value);
#else	
				binaryStreamWriter.WriteObject(value);
#endif
				return true;
			}


			template<typename T>
			bool WriteRaw(const T& content) {
#if IsEditor
				binaryStreamWriter.WriteRaw(content);
#else	
				binaryStreamWriter.WriteRaw(content);
#endif
				return true;
			}

			template<typename T>
			bool WriteSerializableObject(const T& obj) {
#if IsEditor
				binaryStreamWriter.WriteSerializableObject(obj);
#else	
				binaryStreamWriter.WriteSerializableObject(obj);
#endif
				return true;
			}

			template<typename Key, typename Value>
			void WriteMap(const std::map<Key, Value>& map)
			{
#if IsEditor
				binaryStreamWriter.WriteMap(map);
#else	
				binaryStreamWriter.WriteMap(map);
#endif
			}

			template<typename T>
			void WriteVector(const std::vector<T>& vector) {
#if IsEditor
				binaryStreamWriter.WriteVector(vector);
#else	
				binaryStreamWriter.WriteVector(vector);
#endif
			}

	private:
		#if IsEditor
			BinaryStreamWriter binaryStreamWriter;
		#else	
			BinaryStreamWriter binaryStreamWriter;
		#endif
			
	};

}
