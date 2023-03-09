#pragma once

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

#include "argumentMarshaller.h"


class Args {
	private:
		std::map<char, ArgumentMarshaller> marshalers;
		std::set<char> argsFound;
		std::string currentArgument;

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
				marshalers.insert(std::pair<char, ArgumentMarshaller>(elementId, IntegerArgumentMarshaller()));
		}

		void validateSchemaElementId(char elementId)
		{
			// TO DO
		}

		void parseArgumentStrings(std::vector<std::string> args)
		{
			for (size_t i = 0; i < args.size(); i++)
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
			// to do
			std::cout << argChars;
		}

};