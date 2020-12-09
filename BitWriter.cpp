#include "BitWriter.h"
BitWriter::BitWriter(std::fstream* stream) : m_stream(stream), buffer(0), bitcount(0)
{
    if (!stream->is_open())
    {
        throw std::runtime_error("Unable to initialize closed filestream");
    }
}
void BitWriter::WriteBit(bool bit)
{
    if (bitcount == 8)
    {
        *m_stream << buffer;
        bitcount = 0;
        buffer = 0;
    }
    buffer = buffer | ((bit ? 1 : 0) << (7 - bitcount));
    ++bitcount;
}
void BitWriter::WriteByte(unsigned char byte)
{
    if (bitcount == 0)
    {
        *m_stream << byte;
    }
    else {
        for (int i = 0; i < 8; ++i)
        {
            WriteBit((byte >> (7 - i)) & 1);
        }
    }
}
void BitWriter::Close()
{
    if (bitcount)
    {
        *m_stream << buffer;

        bitcount = 0;
        buffer = 0;
    }
    m_stream->close();
}