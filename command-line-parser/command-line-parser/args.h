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
		//std::map<char, ArgumentMarshaller> marshalers;
		std::set<char> argsFound;
		std::string currentArgument;

	public:
		Args(std::string schema, std::vector<std::string> args)
		{
			//std::unordered_map<char, ArgumentMarshaller> marshalers;
			//argsFound

			parseSchema(schema);
			//parseArgumentStrings(args);
		}
	private:
		void parseSchema(std::string  schema)
		{
			/*for(std::string element : schema.find(","))
				if(element.length() > 0)
					parseSchemaElement(element.)*/
		}

		void parseSchemaElement(std::string element)
		{
			// to do
		}




};