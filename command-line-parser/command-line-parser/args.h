#pragma once

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <iterator>

#include "argumentMarshaller.h"
#include "booleanArgumentMarshaller.h"
#include "integerArgumentMarshaller.h"
#include "stringArgumentMarshaller.h"

class Args {
	private:
		std::unordered_map<char, std::shared_ptr<ArgumentMarshaller>> marshalers;
		std::set<char> argsFound;
		std::vector<std::string>::iterator currentArgument;

	public:
		Args(std::string schema, std::vector<std::string> args)
		{
			//std::unordered_map<char, ArgumentMarshaller> marshalers;
			//argsFound

			parseSchema(schema);
			parseArgumentStrings(args);
		}
	private:
		void parseSchema(std::string schema)
		{
			std::string delimiter = ",";
			size_t pos = 0;
			std::string element;
			while ((pos = schema.find(delimiter)) != std::string::npos) {
				element = schema.substr(0, pos);
				parseSchemaElement(element);
				schema.erase(0, pos + delimiter.length());
			}
		}

		void parseSchemaElement(std::string element)
		{
			char elementId = element.front();
			std::string elementTail = element.substr(1);
			validateSchemaElementId(elementId);
			if (elementTail.length() == 0)
				std::cout << "bool\n";
			else if (elementTail == "*")
				std::cout << "str\n";
			else if (elementTail == "#")
			{
				marshalers.insert(std::pair<char, std::shared_ptr<ArgumentMarshaller>>(elementId, std::shared_ptr<IntegerArgumentMarshaller>()));
			}
		}

		void validateSchemaElementId(char elementId)
		{
			// to do EXCEPTION
			if (!std::isalpha(elementId))
				std::cout << "This is an exception! At validateSchemaElementId." << std::endl 
				<< "elementId is not on the alphabet." << elementId << std::endl;
		}

		void parseArgumentStrings(std::vector<std::string> args)
		{
			for (int i = 0; i < args.size(); i++)
			{
				std::string argString = args[i];
				if (argString[0] == '-' )
					parseArgumentCharacters(argString.substr(1));
				else
				{
					// to do 
				}
			}
		}

		void parseArgumentCharacters(std::string argChars)
		{
			for (int i = 0; i < argChars.size(); i++)
				parseArgumentCharacter(argChars[i]);
		}

		void parseArgumentCharacter(char argChar)
		{
			// to do EXCEPTION
			try
			{
				std::shared_ptr<ArgumentMarshaller> m = marshalers.at(argChar);
				argsFound.insert(argChar);
				m->set(currentArgument);
				// to do EXCEPTION
			}
			catch (const std::out_of_range& oor)
			{
				std::cout << "This is an exception! At parseArgumentCharacter." << std::endl
					<< "argChar does not have an associated ArgumentMarshaller." << argChar << std::endl;
				std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
		}

	public:

		bool has(char arg)
		{
			return (argsFound.find(arg) != argsFound.end());
		}

		int nextArgument()
		{
			//return currentArgument. to do
		}

		bool getBoolean(char arg)
		{
			//return BooleanArgumentMarshaller.getValue(marshalers.at(arg)); to do
			return false;
		}

		std::string getString(char arg)
		{
			//return StringArgumentMarshaller.getValue(marshalers.at(arg)); to do
			return std::string{};
		}

		int getInt(char arg)
		{
			//return IntegerArgumentMarshaller.getValue(marshalers.at(arg)); to do
			return 0;
		}
};