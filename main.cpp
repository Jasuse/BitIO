#include <iostream>
#include "BitReader.h"
#include "BitWriter.h"
// EXAMPLE FILE
int main()
{
    BitWriter writer(new std::fstream("a.txt", std::fstream::out | std::fstream::binary));
    writer.WriteBit(0);
    writer.WriteBit(1);
    writer.WriteByte(255);
    writer.Close();
    BitReader reader(new std::fstream("a.txt", std::fstream::in | std::fstream::binary));
    while (reader.good())
    {
        std::cout << reader.ReadBit() << "";
    }
    reader.Close();
    return 0;
}