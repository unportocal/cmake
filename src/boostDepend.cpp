#include <iostream>
#include "boost/shared_ptr.hpp"
#include "boost/filesystem.hpp"

int main(int argc, char const *argv[]) {
    std::cout << "Hello from boost include library" << '\n';

// Use a shared_ptr:
    boost::shared_ptr<int> myIsp(new int(100));

// Simple use of filesystem:
    boost::filesystem::path myPath = "usr/share/cmake/modules";
    if(myPath.is_relative())
    {
        std::cout << "The path is relative" << '\n';
    }
    else
    {
        std::cout << "The path is not relative, i.e. absolute" << '\n';
    }
    
    return 0;
}
