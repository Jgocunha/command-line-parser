#pragma once

#include <vector>
#include <iterator>

class ArgumentMarshaller {
public:
	virtual void set(std::vector<std::string>::iterator currentArgument) {};
};

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
			catch(...)
			{
				std::cout << "Error integerArgumentMarshaller\n";
			}
		}

};