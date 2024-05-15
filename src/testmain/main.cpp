#include <iostream>

#include <testlib/container.h>

int main(int argc, char *argv[]) {
    pimpl::Container c;
    pimpl::Container c2 = c;

    std::cout << "Begin set value." << std::endl;
    c.setValue(1);

    return 0;
}