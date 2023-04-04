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
#include "argsException.h"

class Args {
	private:
		std::unordered_map<char, std::shared_ptr<ArgumentMarshaller>> marshalers;
		std::set<char> argsFound;
		std::vector<std::string>::iterator currentArgument;

	public:
		Args(std::string schema, std::vector<std::string> args)
		{
			marshalers = {};
			argsFound = {};
			currentArgument = {};

			parseSchema(schema);
			parseArgumentStrings(args);
			
		}
	private:
		void parseSchema(std::string& schema)
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

		void parseSchemaElement(const std::string& element)
		{
			char elementId = element.front();
			std::string elementTail = element.substr(1);
			validateSchemaElementId(elementId);
			if (elementTail.length() == 0)
				marshalers.insert(std::make_pair(elementId, std::make_shared<BooleanArgumentMarshaller>()));
			else if (elementTail == "*")
				marshalers.insert(std::make_pair(elementId, std::make_shared<StringArgumentMarshaller>()));
			else if (elementTail == "#")
				marshalers.insert(std::make_pair(elementId, std::make_shared<IntegerArgumentMarshaller>()));
			else
				throw ArgsException(INVALID_ARGUMENT_FORMAT, elementId, elementTail);
		}

		void validateSchemaElementId(char elementId)
		{
			if (!std::isalpha(elementId))
				throw ArgsException(INVALID_ARGUMENT_NAME, elementId);
		}

		void parseArgumentStrings(std::vector<std::string>& args)
		{
			for (currentArgument = args.begin(); currentArgument != args.end(); currentArgument++) {
				std::string argString = *currentArgument;
				if (argString.find("-") == 0) {
					parseArgumentCharacters(argString.substr(1));
				}
			}
		}

		void parseArgumentCharacters(const std::string& argChars)
		{
			for (int i = 0; i < argChars.size(); i++)
				parseArgumentCharacter(argChars[i]);
		}

		void parseArgumentCharacter(char argChar)
		{
			auto it = marshalers.find(argChar);
			if (it != marshalers.end()) {
				std::shared_ptr<ArgumentMarshaller> m = marshalers.at(argChar);
				if (m == NULL)
					throw ArgsException(UNEXPECTED_ARGUMENT, argChar);
				try
				{
					argsFound.insert(argChar);
					m->set(currentArgument);
				}
				catch (ArgsException& e)
				{
					e.setErrorArgumentId(argChar);
					throw e;
				}
			}
		}

	public:

		bool has(char arg)
		{
			return (argsFound.find(arg) != argsFound.end());
		}

		bool getBoolean(char arg)
		{
			auto it = marshalers.find(arg);
			if (it != marshalers.end()) {
				ArgumentMarshaller* am = it->second.get(); 
				if (BooleanArgumentMarshaller* iAm = dynamic_cast<BooleanArgumentMarshaller*>(am)) { 
					return iAm->getValue(); 
				}
			}
			return false; 
		}

		std::string getString(char arg)
		{
			auto it = marshalers.find(arg);
			if (it != marshalers.end()) { 
				ArgumentMarshaller* am = it->second.get(); 
				if (StringArgumentMarshaller* iAm = dynamic_cast<StringArgumentMarshaller*>(am)) {
					return iAm->getValue(); 
				}
			}
			return std::string{};
		}

		int getInt(char arg)
		{
			auto it = marshalers.find(arg);
			if (it != marshalers.end()) { // if argument found in the map
				ArgumentMarshaller* am = it->second.get(); // get the ArgumentMarshaller shared pointer
				if (IntegerArgumentMarshaller* iAm = dynamic_cast<IntegerArgumentMarshaller*>(am)) { // cast to IntegerArgumentMarshaller
					return iAm->getValue(); // call the getIntValue method
				}
			}
			return 0; // return 0 if argument not found or not of type IntegerArgumentMarshaller
		}
};