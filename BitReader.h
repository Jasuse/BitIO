#pragma once
#include <fstream>
class BitReader
{
    public:
    BitReader(std::fstream* stream);
    bool good();
    bool ReadBit();
    unsigned char ReadByte();
    void Close();
    private:
    std::fstream* m_stream;
    unsigned char buffer;
    unsigned char bitcount;
};

