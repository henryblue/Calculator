#include "Serial.h"

using std::ios;

Serializer::Serializer(const::std::string& filename)
:stream_(filename.c_str(), ios::out | ios::binary)
{
}


Serializer::~Serializer()
{
}
