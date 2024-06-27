#pragma once

#include <filesystem>
#include <fstream>

namespace Serialization 
{

	class BinaryStreamWriter
	{

	public:
		BinaryStreamWriter(const std::filesystem::path& path);
		virtual ~BinaryStreamWriter();
		void Close();

		bool IsStreamGood() const;
		uint64_t GetStreamPosition();
		void SetStreamPosition(uint64_t position);

		bool WriteData(const char* data, size_t size);


	private:
		std::filesystem::path m_Path;
		std::ofstream m_Stream;

	};
}

