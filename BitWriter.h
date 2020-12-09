#pragma once
#include <fstream>
class BitWriter
{
public:
    BitWriter(std::fstream* stream);
    void WriteBit(bool bit);
    void WriteByte(unsigned char byte);
    void Close();
private:
    std::fstream* m_stream;
    unsigned char buffer;
    unsigned char bitcount;
};

