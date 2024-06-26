#include "FileStreamWriter.h"
namespace Serialization
{
	FileStreamWriter::FileStreamWriter(const std::filesystem::path& path) : m_Path(path)
	{
		m_Stream = std::ofstream(path, std::ofstream::out | std::ofstream::binary);
	}

	FileStreamWriter::~FileStreamWriter()
	{
		Close();
	}

	void FileStreamWriter::Close()
	{
		m_Stream.close();
	}

	bool FileStreamWriter::IsStreamGood() const
	{
		return m_Stream.good();
	}

	uint64_t FileStreamWriter::GetStreamPosition()
	{
		return m_Stream.tellp();
	}

	void FileStreamWriter::SetStreamPosition(uint64_t position)
	{
		m_Stream.seekp(position);
	}

	bool FileStreamWriter::WriteData(const char* data, size_t size)
	{
		m_Stream.write(data, size);
		//TODO: check if success 
		return true;
	}
}
