// CPP Program to illustrate concept of virtual functions
// https://www.geeksforgeeks.org/virtual-function-cpp/

#include <iostream>
using namespace std;

class base
{
public:
    virtual void print(/* arguments */)
    {
        std::cout << "Print base class" << '\n';
    }
    void show(/* arguments */)
    {
        std::cout << "Show base class" << '\n';
    }
};

class derived : public base
{
public:
    void print()
    {
        std::cout << "print derived class" << '\n';
    }
    void show()
    {
        std::cout << "show derived class" << '\n';
    }
};

int main(int argc, char const *argv[]) {
    base *bptr;
    derived d;
    bptr = &d;

    //Virtual function. Binded at runtime
    bptr->print();
    //Non-virtual function. Binded at compile
    bptr->show();

    return 0;
}
