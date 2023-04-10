# command-line-parser

The code is an implementation of a **command-line argument parser**. It receives a ```schema``` string as the first argument, followed by a list of argument strings. The ```schema``` string specifies the expected **arguments' format** and which ones are required or optional. The code then parses the argument strings, matches them with the schema, and generates an object that can be queried for the values of each argument.

The ```Args``` class has three public methods: ```has```, ```getBoolean```, ```getString```, and ```getInt```, which can be used to retrieve the value of a specific argument. These methods take a single argument, which is the character representing the argument. These can be extended to fit your needs.

The private methods include ```parseSchema```, ```parseSchemaElement```, ```validateSchemaElementId```, ```parseArgumentStrings```, ```parseArgumentCharacters```, ```parseArgumentCharacter```.

The ```ArgumentMarshaller``` class is an abstract base class for the ```BooleanArgumentMarshaller```, ```StringArgumentMarshaller```, and ```IntegerArgumentMarshaller``` classes, which handle marshaling the values of different types of arguments.

The ```ArgsException``` class is used to handle exceptions that may occur during parsing.

---

## Command line arguments in Visual Studio

In Visual Studio, you can define command line arguments by following these steps:

1. Open your project in Visual Studio.
2. Right-click on the project in the Solution Explorer and select "Properties".
3. In the Properties window, select "Debugging" from the left-hand menu.
4. In the "Command Arguments" field, enter the command line arguments you want to use.
5. Click "Apply" and then "OK" to save the changes.

When you run your program from within Visual Studio using the "Start Debugging" or "Start Without Debugging" options, the command line arguments you defined will be passed to the program. If you want to run your program outside of Visual Studio, you will need to pass the command line arguments directly to the executable file.
