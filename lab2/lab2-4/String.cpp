#if 0
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include "String.h"
#include <string>
String::String(const char* const ptr)
	: length(strlen(ptr))
{
	sPtr = new char[length + 1];
	strcpy_s(sPtr, rsize_t(length + 1), ptr);
}

String::String(const String& s)
{
	sPtr = s.sPtr;
	length = s.length;
}

String::~String()
{
	delete[] sPtr;
}

const String& String::operator=(const String& s)
{
	delete[]sPtr;
	length = s.length;
	sPtr = new char[length + 1];
	strcpy_s(sPtr, rsize_t(length + 1), s.sPtr);
	return *this;
}

String String::operator+(const String& s)
{
	rsize_t  len = length + s.length + 1;
	char* temp = new char[len];
	strcpy_s(temp, len, sPtr);
	strcat_s(temp, len, s.sPtr);
	return String(temp);
}

ostream& operator<<(ostream& output, const String& s)
{
	for (size_t i = 0; i < s.length; ++i) {
		output << s.sPtr[i];
	}
	return output;
}
