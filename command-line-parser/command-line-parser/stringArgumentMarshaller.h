#pragma once

#include "argumentMarshaller.h"

class StringArgumentMarshaller : public ArgumentMarshaller
{
private:
	std::string stringValue;
public:
	StringArgumentMarshaller()
	{
		stringValue = {};
	}

	void set(std::vector<std::string>::iterator currentArgument)
	{
		try
		{
			stringValue = *++currentArgument;
		}
		catch (...)
		{
			std::cout << "Error stringArgumentMarshaller\n";
		}
	}

	std::string getValue()
	{
		return stringValue;
	}
};