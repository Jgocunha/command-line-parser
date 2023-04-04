#pragma once

#include "argumentMarshaller.h"


class BooleanArgumentMarshaller : public ArgumentMarshaller
{
private:
	bool booleanValue;
public:
	BooleanArgumentMarshaller()
	{
		booleanValue = false;
	}

	void set(std::vector<std::string>::iterator currentArgument)
	{
		booleanValue = true;
	}

	bool getValue()
	{
		return booleanValue;
	}
};