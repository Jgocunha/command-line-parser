#pragma once

#include <vector>
#include <iterator>

class ArgumentMarshaller {
	virtual void set(std::vector<std::string>::iterator currentArgument) = 0;
};

class integerArgumentMarshaller : public ArgumentMarshaller
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