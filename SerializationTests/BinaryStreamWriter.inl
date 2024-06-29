#include "BinaryStreamWriter.h"
#include "SerializableObject.h"

namespace Serialization {

	template<typename T>
	bool BinaryStreamWriter::WriteRaw(const T& content)
	{
		WriteData((char*)&content, sizeof(T));
		return true;
	}

	template<typename T>
	bool BinaryStreamWriter::WriteSerializableObject(const T& obj)
	{
		T::Serialize(this, obj);
		return true;
	}

	template<typename Key, typename Value>
	void BinaryStreamWriter::WriteMap(const std::map<Key, Value>& map)
	{
		// Write size of map
		WriteRaw<uint32_t>((uint32_t)map.size());

		for (const auto& [key, value] : map)
		{
			if constexpr (std::is_base_of_v<std::string, Key>) {
				WriteString(key);
			}
			//else if constexpr (std::is_base_of_v<Serialization::SerializableObject, Key>) {
			//	WriteObject(key);
			//}
			else if constexpr (std::is_trivial<Key>()) {
				WriteRaw<Key>(key);
			}
			else {
				WriteRaw<Key>(key);
				//WriteObject<Key>(key);
			}

			if constexpr (std::is_base_of_v<std::string, Value>) {
				WriteString(value);
			}
			//else if constexpr (std::is_base_of_v<Serialization::SerializableObject, Value>) {
			//	WriteObject(value);
			//}
			else if constexpr (std::is_trivial<Value>()) {
				WriteRaw<Value>(value);
			}
			else {
				WriteRaw<Value>(value);
				//WriteObject<Value>(value);
			}
		}

	}

}