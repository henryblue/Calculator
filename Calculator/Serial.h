#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <fstream>
#include <string>

class Serializer
{
public:
	Serializer(const std::string& filename);
	~Serializer();
	Serializer& operator<<(unsigned int data);
	Serializer& operator<<(int data);
	Serializer& operator<<(unsigned long data);
	Serializer& operator<<(long data);
	Serializer& operator<<(double data);
	Serializer& operator<<(const std::string& fileName);
	Serializer& operator<<(bool data);

	Serializer& Put(unsigned int data);
	Serializer& Put(int data);
	Serializer& Put(unsigned long data);
	Serializer& Put(long data);
	Serializer& Put(double data);
	Serializer& Put(const std::string& fileName);
	Serializer& Put(bool data);

private:
	std::ofstream stream_;
};

class DeSerializer
{
public:
	DeSerializer(const std::string& filename);
	~DeSerializer();
	DeSerializer& operator>>(unsigned int& data);
	DeSerializer& operator>>(int& data);
	DeSerializer& operator>>(unsigned long& data);
	DeSerializer& operator>>(long& data);
	DeSerializer& operator>>(double& data);
	DeSerializer& operator>>(std::string& fileName);
	DeSerializer& operator>>(bool& data);

	DeSerializer& Get(unsigned int& data);
	DeSerializer& Get(int& data);
	DeSerializer& Get(unsigned long& data);
	DeSerializer& Get(long& data);
	DeSerializer& Get(double& data);
	DeSerializer& Get(std::string& fileName);
	DeSerializer& Get(bool& data);

private:
	std::ifstream stream_;
};
#endif // _SERIAL_H_
