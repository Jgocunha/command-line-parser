#pragma once

#include "argumentMarshaller.h"

class IntegerArgumentMarshaller : public ArgumentMarshaller
{
private:
	int integerValue = 0;

public:
	void set(std::vector<std::string>::iterator currentArgument)
	{
		std::string parameter;

		try
		{
			parameter = *currentArgument++;
			integerValue = stoi(parameter);
		}
		catch (...)
		{
			std::cout << "Error integerArgumentMarshaller\n";
		}
	}

	static int getValue(IntegerArgumentMarshaller am)
	{
		return am.integerValue;
	}
};

