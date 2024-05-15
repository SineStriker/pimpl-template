#ifndef OBJECT_P_H
#define OBJECT_P_H

#include <testlib/object.h>

namespace pimpl {

    class TESTLIB_EXPORT Object::Impl {
    public:
        virtual ~Impl() = default;

        using Intf = Object;
        friend class Object;
        Object *_intf;

    public:
        int value;

        int value_helper() const;
        void setValue_helper(int val);

        int value_helper2() const;
        void setValue_helper2(int val);
    };

    class TESTLIB_EXPORT Gadget::Impl : public Object::Impl {
    public:
        using Intf = Gadget;
        friend class Gadget;

    public:
        std::string s;
    };

}

#endif // OBJECT_P_H
