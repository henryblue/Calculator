#include "Serial.h"
#include "Exception.h"
using std::ios;

const int TRUE_PATTERN = 0xfadcd464;
const int FALSE_PATTERN = 0xfad4d123;
//===================Serializer=============================
Serializer::Serializer(const::std::string& filename)
:stream_(filename.c_str(), ios::out | ios::binary)
{
	if (!stream_)
	{
		throw FileStreamError("Couldn't open file.");
	}
}


Serializer::~Serializer()
{
}

Serializer& Serializer::operator<<(unsigned int data)
{
	return Put(data);
}

Serializer& Serializer::operator<<(int data)
{
	return Put(data);
}

Serializer& Serializer::operator<<(unsigned long data)
{
	return Put(data);
}

Serializer& Serializer::operator<<(long data)
{
	return Put(data);
}

Serializer& Serializer::operator<<(double data)
{
	return Put(data);
}

Serializer& Serializer::operator<<(const std::string& str)
{
	return Put(str);
}

Serializer& Serializer::operator<<(bool data)
{
	return Put(data);
}

Serializer& Serializer::Put(unsigned int data)
{
	stream_.write(reinterpret_cast<char*>(&data), sizeof(unsigned int));
	if (stream_.bad())
	{
		throw FileStreamError("Write file failed.");
	}
	return *this;
}

Serializer& Serializer::Put(int data)
{
	stream_.write(reinterpret_cast<char*>(&data), sizeof(int));
	if (stream_.bad())
	{
		throw FileStreamError("Write file failed.");
	}

	return *this;
}

Serializer& Serializer::Put(unsigned long data)
{
	stream_.write(reinterpret_cast<char*>(&data), sizeof(unsigned long));
	if (stream_.bad())
	{
		throw FileStreamError("Write file failed.");
	}
	return *this;
}

Serializer& Serializer::Put(long data)
{
	stream_.write(reinterpret_cast<char*>(&data), sizeof(long));
	if (stream_.bad())
	{
		throw FileStreamError("Write file failed.");
	}
	return *this;
}

Serializer& Serializer::Put(double data)
{
	stream_.write(reinterpret_cast<char*>(&data), sizeof(double));
	if (stream_.bad())
	{
		throw FileStreamError("Write file failed.");
	}
	return *this;
}

Serializer& Serializer::Put(const std::string& str)
{
	int len = str.length();
	Put(len);
	stream_.write(str.data(), str.length());
	if (stream_.bad())
	{
		throw FileStreamError("Write file failed.");
	}
	return *this;
}

Serializer& Serializer::Put(bool data)
{
	int n = data ? TRUE_PATTERN : FALSE_PATTERN;
	Put(n);
	return *this;
}

//=====================DeSerializer==========================
DeSerializer::DeSerializer(const std::string& filename)
:stream_(filename.c_str(), ios::in | ios::binary)
{
	if (!stream_)
	{
		throw FileStreamError("Couldn't open file.");
	}
}

DeSerializer::~DeSerializer()
{

}

DeSerializer& DeSerializer::operator>>(unsigned int& data)
{
	return Get(data);
}

DeSerializer& DeSerializer::operator>>(int& data)
{
	return Get(data);
}

DeSerializer& DeSerializer::operator>>(unsigned long& data)
{
	return Get(data);
}

DeSerializer& DeSerializer::operator>>(long& data)
{
	return Get(data);
}

DeSerializer& DeSerializer::operator>>(double& data)
{
	return Get(data);
}

DeSerializer& DeSerializer::operator>>(std::string& str)
{
	return Get(str);
}

DeSerializer& DeSerializer::operator>>(bool& data)
{
	return Get(data);
}

DeSerializer& DeSerializer::Get(unsigned int& data)
{
	if (stream_.eof())
	{
		throw FileStreamError("Unexpected end of file.");
	}
	stream_.read(reinterpret_cast<char*>(&data), sizeof(unsigned int));
	if (stream_.bad())
	{
		throw FileStreamError("Read file failed.");
	}
	return *this;
}

DeSerializer& DeSerializer::Get(int& data)
{
	if (stream_.eof())
	{
		throw FileStreamError("Unexpected end of file.");
	}
	stream_.read(reinterpret_cast<char*>(&data), sizeof(int));
	if (stream_.bad())
	{
		throw FileStreamError("Read file failed.");
	}
	return *this;
}

DeSerializer& DeSerializer::Get(unsigned long& data)
{
	if (stream_.eof())
	{
		throw FileStreamError("Unexpected end of file.");
	}
	stream_.read(reinterpret_cast<char*>(&data), sizeof(unsigned long));
	if (stream_.bad())
	{
		throw FileStreamError("Read file failed.");
	}
	return *this;
}

DeSerializer& DeSerializer::Get(long& data)
{
	if (stream_.eof())
	{
		throw FileStreamError("Unexpected end of file.");
	}
	stream_.read(reinterpret_cast<char*>(&data), sizeof(long));
	if (stream_.bad())
	{
		throw FileStreamError("Read file failed.");
	}
	return *this;
}

DeSerializer& DeSerializer::Get(double& data)
{
	if (stream_.eof())
	{
		throw FileStreamError("Unexpected end of file.");
	}
	stream_.read(reinterpret_cast<char*>(&data), sizeof(double));
	if (stream_.bad())
	{
		throw FileStreamError("Read file failed.");
	}
	return *this;
}

DeSerializer& DeSerializer::Get(std::string& str)
{
	int len;
	Get(len);
	if (stream_.eof())
	{
		throw FileStreamError("Unexpected end of file.");
	}
	str.resize(len);
	stream_.read(&str[0], len);
	if (stream_.bad())
	{
		throw FileStreamError("Read file failed.");
	}
	return *this;
}

DeSerializer& DeSerializer::Get(bool& data)
{
	int tmp;
	Get(tmp);
	if (tmp == FALSE_PATTERN)
	{
		data = false;
	}
	else if(tmp == TRUE_PATTERN)
	{
		data = true;
	}
	else
	{
		throw FileStreamError("Data Error.");
	}
	return *this;
}