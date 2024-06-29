#include "BinaryStreamReader.h"
#include "SerializableObject.h"

namespace Serialization
{
	template<typename T>
	bool BinaryStreamReader::ReadRaw(T& target)
	{
		ReadData((char*)&target, sizeof(T));
		return true;
	}

	template<typename T>
	bool BinaryStreamReader::ReadSerializableObject(T& targetObj)
	{
		T::Deserialize(this, targetObj);
		return true;
	}

	template<typename Key, typename Value>
	void BinaryStreamReader::ReadMap(std::map<Key, Value>& map)
	{
		// Write size of map
		uint32_t size = 0;
		ReadRaw<uint32_t>(size);

		for (uint32_t i = 0; i < size; i++) {
			std::cout << "Looping" << std::endl;

			// Ok so if one of the types is a string if goes to shit
			Key key{};

			if constexpr (std::is_base_of_v<std::string, Key>) {
				ReadString(key);
			}
			//else if constexpr (std::is_base_of_v<Serialization::SerializableObject, Key>) {
			//	ReadObject(key);
			//}
			else if constexpr (std::is_trivial<Key>()) {
				ReadRaw<Key>(key);
			}
			else {
				ReadRaw<Key>(key);
				//ReadObject<Key>(key);
			}

			//Value value{};
			if constexpr (std::is_base_of_v<std::string, Value>) {
				ReadString(map[key]);
			}
			//else if constexpr (std::is_base_of_v<Serialization::SerializableObject, Value>) {
			//	ReadObject(map[key]);
			//}
			else if constexpr (std::is_trivial<Value>()) {
				ReadRaw<Value>(map[key]);
			}
			else {
				ReadRaw<Value>(map[key]);
				//ReadObject<Value>(value);
			}

			//map[key] = value;
		}
	}

}