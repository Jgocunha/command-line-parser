#pragma once

#include "argumentMarshaller.h"
#include "argsException.h"

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
		catch (ArgsException& e)
		{
			throw ArgsException(MISSING_STRING);
		}
	}

	std::string getValue()
	{
		return stringValue;
	}
};