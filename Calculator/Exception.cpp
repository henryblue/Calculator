#include "Exception.h"

const char* Exception::what() const throw() {
	return message_.c_str();
}

const char* Exception::StackTrace() const throw()
{
	return stackTrace_.c_str();
}

void Exception::FillStackTrace()
{
	//仅适用linux进行栈回溯
	//const int len = 200;
	//void* buffer[len];
	//int nptr = ::backtrace(buffer, len);
	//char** strings = ::backtrace_symbols(buffer, nptr);
	//if (strings)
	//{
	//	for (int i = 0; i < nptrs; i++)
	//	{
	//		stackTrace_.append(strings[i]);
	//		stackTrace_.push_back('\n');
	//	}
	//	free(strings);
	//}

}