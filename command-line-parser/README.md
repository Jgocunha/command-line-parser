# command-line-parser

The code is an implementation of a **command-line argument parser**. It receives a ```schema``` string as the first argument, followed by a list of argument strings. The ```schema``` string specifies the expected **arguments' format** and which ones are required or optional. The code then parses the argument strings, matches them with the schema, and generates an object that can be queried for the values of each argument.

The ```Args``` class has three public methods: ```has```, ```getBoolean```, ```getString```, and ```getInt```, which can be used to retrieve the value of a specific argument. These methods take a single argument, which is the character representing the argument. These can be extended to fit your needs.

The private methods include ```parseSchema```, ```parseSchemaElement```, ```validateSchemaElementId```, ```parseArgumentStrings```, ```parseArgumentCharacters```, ```parseArgumentCharacter```.

The ```ArgumentMarshaller``` class is an abstract base class for the ```BooleanArgumentMarshaller```, ```StringArgumentMarshaller```, and ```IntegerArgumentMarshaller``` classes, which handle marshaling the values of different types of arguments.

The ```ArgsException``` class is used to handle exceptions that may occur during parsing.