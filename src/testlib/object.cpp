#include "object.h"
#include "object_p.h"

#include "testlib_global_p.h"

namespace testlib {

    Object::Object(int value) : Object(*new Impl(), value) {
    }

    Object::~Object() = default;

    int Object::value() const {
        __impl_t;
        return impl.value;
    }

    void Object::setValue(int value) {
        __impl_t;
        impl.value = value;
    }

    Object::Object(Impl &impl, int value) : _impl(&impl) {
        impl._decl = this;

        impl.value = value;
    }

    Gadget::Gadget(const std::string &s, int value) : Gadget(*new Impl(), s, value) {
    }

    Gadget::~Gadget() {
    }

    std::string Gadget::str() const {
        __impl_t;
        return impl.s;
    }

    void Gadget::setStr(const std::string &s) {
        __impl_t;
        impl.s = s;
    }

    Gadget::Gadget(Impl &impl, const std::string &s, int value) : Object(impl, value) {
        impl.s = s;
    }

}