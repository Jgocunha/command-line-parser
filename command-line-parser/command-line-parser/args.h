#pragma once

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

#include "argumentMarshaller.h"


class Args {
	private:
		std::map<char, ArgumentMarshaller> marshalers;
		std::set<char> argsFound;
		std::string currentArgument;

	public:
		Args(std::string schema, std::string args)
		{
			//std::unordered_map<char, ArgumentMarshaller> marshalers;
			//argsFound

			parseSchema(schema);
			//parseArgumentStrings(args);
		}
	private:
		void parseSchema(std::string  schema)
		{
			// to do
		}

		void parseSchemaElement(std::string element)
		{
			// to do
		}




};