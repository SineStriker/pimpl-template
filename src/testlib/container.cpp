#include "container.h"
#include "container_p.h"

namespace pimpl {

    Container::Impl::~Impl() = default;

    Container::Container(int value) : Container(*new Impl(), value) {
    }

    Container::~Container() = default;

    int Container::value() const {
        PIMPL_IMPL(const Container);
        return impl->value;
    }

    void Container::setValue(int value) {
        PIMPL_IMPL(Container);
        impl->value = value;
    }

    int Container::value2() const {
        PIMPL_IMPL_THIS;
        return impl->value;
    }

    void Container::setValue2(int value) {
        PIMPL_IMPL_THIS;
        impl->value = value;
    }

    Container::Container(Impl &impl, int value) : _impl(&impl) {
        impl.value = value;
    }

}