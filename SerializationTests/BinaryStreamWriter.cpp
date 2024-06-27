#include "BinaryStreamWriter.h"

namespace Serialization
{
	BinaryStreamWriter::BinaryStreamWriter(const std::filesystem::path& path) : m_Path(path)
	{
		m_Stream = std::ofstream(path, std::ofstream::out | std::ofstream::binary);
	}

	BinaryStreamWriter::~BinaryStreamWriter()
	{
		Close();
	}

	void BinaryStreamWriter::Close()
	{
		m_Stream.close();
	}

	bool BinaryStreamWriter::IsStreamGood() const
	{
		return m_Stream.good();
	}

	uint64_t BinaryStreamWriter::GetStreamPosition()
	{
		return m_Stream.tellp();
	}

	void BinaryStreamWriter::SetStreamPosition(uint64_t position)
	{
		m_Stream.seekp(position);
	}

	bool BinaryStreamWriter::WriteData(const char* data, size_t size)
	{
		m_Stream.write(data, size);
		//TODO: check if success 
		return true;
	}
}
