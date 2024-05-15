#include "object.h"
#include "object_p.h"

namespace pimpl {

    int Object::Impl::value_helper() const {
        PIMPL_INTF(const Object);
        return intf.value();
    }

    void Object::Impl::setValue_helper(int val) {
        PIMPL_INTF(Object);
        intf.setValue(val);
    }

    int Object::Impl::value_helper2() const {
        PIMPL_INTF_THIS;
        return intf.value();
    }

    void Object::Impl::setValue_helper2(int val) {
        PIMPL_INTF_THIS;
        intf.setValue(val);
    }

    Object::Object(int value) : Object(*new Impl(), value) {
    }

    Object::~Object() = default;

    int Object::value() const {
        PIMPL_IMPL(const Object);
        return impl.value;
    }

    void Object::setValue(int value) {
        PIMPL_IMPL(Object);
        impl.value = value;
    }

    int Object::value2() const {
        PIMPL_IMPL_THIS;
        return impl.value;
    }

    void Object::setValue2(int value) {
        PIMPL_IMPL_THIS;
        impl.value = value;
    }

    Object::Object(Impl &impl, int value) : _impl(&impl) {
        impl._intf = this;

        impl.value = value;
    }

    Gadget::Gadget(const std::string &s, int value) : Gadget(*new Impl(), s, value) {
    }

    Gadget::~Gadget() {
    }

    std::string Gadget::str() const {
        PIMPL_IMPL_THIS;
        return impl.s;
    }

    void Gadget::setStr(const std::string &s) {
        PIMPL_IMPL_THIS;
        impl.s = s;
    }

    Gadget::Gadget(Impl &impl, const std::string &s, int value) : Object(impl, value) {
        impl.s = s;
    }

}