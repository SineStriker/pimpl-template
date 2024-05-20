#ifndef OBJECT_P_H
#define OBJECT_P_H

#include <testlib/object.h>

namespace testlib {

    class TESTLIB_EXPORT Object::Impl {
        TESTLIB_DECLARE_DECL(Object)
    public:
        virtual ~Impl() = default;

        Object *_decl;

    public:
        int value;
    };

    class TESTLIB_EXPORT Gadget::Impl : public Object::Impl {
        TESTLIB_DECLARE_DECL(Gadget)
    public:
        std::string s;
    };

}

#endif // OBJECT_P_H
