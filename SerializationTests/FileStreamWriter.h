#pragma once

#include <filesystem>
#include <fstream>

namespace Serialization 
{

	class FileStreamWriter
	{

	public:
		FileStreamWriter(const std::filesystem::path& path);
		virtual ~FileStreamWriter();
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

