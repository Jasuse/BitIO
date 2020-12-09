#include "BitReader.h"
BitReader::BitReader(std::fstream* stream) : m_stream(stream), buffer(0), bitcount(0)
{
    if (!stream->is_open())
    {
        throw std::runtime_error("Unable to initialize closed filestream");
    }
}
bool BitReader::good()
{
    return (m_stream->good() && (m_stream->peek(), !m_stream->eof())) || (bitcount != 0);
}
bool BitReader::ReadBit()
{
    if (!bitcount)
    {
        if (m_stream->good())
        {
            *m_stream >> buffer;
            bitcount = 8;
        }
        else
        {
            throw std::runtime_error("File stream is not good :(");
        }
    }
    --bitcount;
    return (buffer >> bitcount) & 1;
}
unsigned char BitReader::ReadByte()
{
    if (bitcount == 8)
    {
        bitcount = 0;
        return buffer;
    }
    unsigned char res = 0;
    for (int i = 0; i < 8; ++i)
    {
        res |= (ReadBit() << i);
    }
    return res;
}
void BitReader::Close()
{
    m_stream->close();
}
