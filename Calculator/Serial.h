#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <fstream>
#include <string>

class Serializer
{
public:
	Serializer(const std::string& filename);
	~Serializer();

private:
	std::ofstream stream_;
};

#endif
