#include "FileStreamReader.h"

namespace Serialization
{
	FileStreamReader::FileStreamReader(const std::filesystem::path& path) : m_Path(path)
	{
		m_Stream = std::ifstream(path, std::ifstream::in | std::ifstream::binary);
	}

	FileStreamReader::~FileStreamReader()
	{
		Close();
	}

	void FileStreamReader::Close()
	{
		m_Stream.close();
	}

	bool FileStreamReader::IsStreamGood() const
	{
		return m_Stream.good();
	}

	uint64_t FileStreamReader::GetStreamPosition()
	{
		return m_Stream.tellg();
	}

	void FileStreamReader::SetStreamPosition(uint64_t position)
	{
		m_Stream.seekg(position);
	}

	bool FileStreamReader::ReadData(char* destination, size_t size)
	{
		m_Stream.read(destination, size);
		return true;
	}
}