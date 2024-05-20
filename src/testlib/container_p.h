#ifndef CONTAINER_P_H
#define CONTAINER_P_H

#include <iostream>

#include <testlib/container.h>

namespace testlib {

    class TESTLIB_EXPORT Container::Impl {
    public:
        Impl() = default;
        Impl(const Impl &other) : value(other.value) {
            std::cout << "Container Impl copied." << std::endl;
        }
        virtual ~Impl();

        int value;
    };

}

#endif // CONTAINER_P_H
