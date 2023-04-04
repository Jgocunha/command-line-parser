#include <iostream>
#include <vector>

#include "args.h"
#include "argsException.h"

using namespace std;

int main(int argc, char** argv)
{
    std::vector<std::string> args;

    cout << "You have entered " << (argc-1) << " arguments:" << "\n";

    for (int i = 1; i < argc ; ++i)
    {
        cout << argv[i] << "\n";
        args.push_back(argv[i]);
    }
    
    try 
    {
        //Args arg("l,p#,d*,", args);
        Args arg("l,p#,d*,", args);

        int integer = arg.getInt('p');
        bool boolean = arg.getBoolean('l');
        string string = arg.getString('d');

        cout << "Integer inserted was: " << integer << endl;
        cout << "Boolean inserted was: " << boolean << endl;
        cout << "String inserted was: " << string << endl;
    }
    catch (ArgsException& e)
    {
        std::cerr << "Argument error: " + e.getErrorMessage() + "\n";
    }
    

    return 0;
}