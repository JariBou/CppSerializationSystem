#include "BinaryStreamWriter.h"
#include <iostream>

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
	bool BinaryStreamWriter::WriteString(const std::string content)
	{
		size_t size = content.size();

		WriteData((char*)&size, sizeof(size_t));
		std::cout << "size = " << sizeof(char) * size << std::endl;
		WriteData((char*)content.data(), sizeof(char) * size);

		return true;
	}
}
