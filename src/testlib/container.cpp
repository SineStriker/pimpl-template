#include "container.h"
#include "container_p.h"

#include "testlib_global_p.h"

namespace testlib {

    Container::Impl::~Impl() = default;

    Container::Container(int value) : Container(*new Impl(), value) {
    }

    Container::~Container() = default;

    int Container::value() const {
        __impl_t;
        return impl.value;
    }

    void Container::setValue(int value) {
        __impl_t;
        impl.value = value;
    }

    Container::Container(Impl &impl, int value) : _impl(&impl) {
        impl.value = value;
    }

}