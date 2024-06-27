#pragma once

#include <filesystem>
#include <fstream>

namespace Serialization
{

	class BinaryStreamReader
	{

		public:
			BinaryStreamReader(const std::filesystem::path& path);
			virtual ~BinaryStreamReader();
			void Close();

			bool IsStreamGood() const;
			uint64_t GetStreamPosition();
			void SetStreamPosition(uint64_t position);

			bool ReadData(char* destination, size_t size);


		private:
			std::filesystem::path m_Path;
			std::ifstream m_Stream;

	};
}

