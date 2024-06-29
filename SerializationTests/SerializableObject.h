#pragma once
//#include "Serializer.h"
//#include "Deserializer.h"
//TODO check if maybe a forward declaration wouldn't be better

namespace Serialization
{
	class Serializer;
	class Deserializer;

	class SerializableObject
	{

	public:
		void Serialize(Serialization::Serializer* serializer, const SerializableObject& instance) const {
			instance.OnSerialize(serializer);
		}
		void Deserialize(Serialization::Deserializer* deserializer, SerializableObject& instance) {
			instance.OnDeserialize(deserializer);
		}
	
	protected:
		virtual void OnSerialize(Serialization::Serializer* serializer) const = 0;
		virtual void OnDeserialize(Serialization::Deserializer* deserializer) = 0;

	};
}

