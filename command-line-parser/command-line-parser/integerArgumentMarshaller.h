#pragma once

#include "argumentMarshaller.h"
#include "argsException.h"

class IntegerArgumentMarshaller : public ArgumentMarshaller
{
private:
	int integerValue;

public:
	IntegerArgumentMarshaller()
	{
		integerValue = 0;
	}

	void set(std::vector<std::string>::iterator currentArgument)
	{
		std::string parameter;

		try
		{
			parameter = *++currentArgument;
			integerValue = stoi(parameter);
		}
		catch (ArgsException& e)
		{
			throw ArgsException(MISSING_INTEGER);
		}
		//catch (ArgsException e)
		//{
		//	throw new ArgsException(INVALID_INTEGER, parameter);
		//}
	}

	int getValue()
	{
		return integerValue;
	}
};

