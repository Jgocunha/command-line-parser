#pragma once

#include <vector>
#include <iterator>

class ArgumentMarshaller {
public:
	virtual void set(std::vector<std::string>::iterator currentArgument) = 0;
};

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}