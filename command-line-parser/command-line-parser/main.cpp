#include <iostream>
#include <vector>

#include "args.h"

using namespace std;


int main(int argc, char** argv)
{
    std::vector<std::string> args;

    cout << "You have entered " << (argc-1) << " arguments:" << "\n";

    for (int i = 1; i < argc - 1; ++i)
    {
        cout << argv[i] << "\n";
        args.push_back(argv[i]);
    }
    
    Args arg("l,p#,d*", args);

    return 0;
}