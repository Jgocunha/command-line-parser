#pragma once

#include "argumentMarshaller.h"

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
		catch (...)
		{
			std::cout << "Error integerArgumentMarshaller\n";
		}
	}

	int getValue()
	{
		return integerValue;
	}
};

