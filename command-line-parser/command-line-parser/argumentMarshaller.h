#pragma once

#include <vector>
#include <iterator>

class ArgumentMarshaller {
public:
	virtual void set(std::vector<std::string>::iterator currentArgument) = 0;
};
