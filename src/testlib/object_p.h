#ifndef OBJECT_P_H
#define OBJECT_P_H

#include <testlib/object.h>

namespace pimpl {

    class TESTLIB_EXPORT Object::Impl {
        PIMPL_DECLARE_INTF(Object)
    public:
        virtual ~Impl() = default;

        Object *_intf;

    public:
        int value;

        int value_helper() const;
        void setValue_helper(int val);

        int value_helper2() const;
        void setValue_helper2(int val);
    };

    class TESTLIB_EXPORT Gadget::Impl : public Object::Impl {
        PIMPL_DECLARE_INTF(Gadget)
    public:
        std::string s;
    };

}

#endif // OBJECT_P_H
