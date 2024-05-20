#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>

#include <testlib/testlib_global.h>

namespace testlib {

    class TESTLIB_EXPORT Object {
        TESTLIB_DECLARE_IMPL(Object)
    public:
        explicit Object(int value = 0);
        virtual ~Object();

    public:
        int value() const;
        void setValue(int value);

    protected:
        Object(Impl &impl, int value = 0);
        std::unique_ptr<Impl> _impl;
    };

    class TESTLIB_EXPORT Gadget : public Object {
        TESTLIB_DECLARE_IMPL(Gadget)
    public:
        explicit Gadget(const std::string &s, int value = 0);
        virtual ~Gadget();

    public:
        std::string str() const;
        void setStr(const std::string &s);

    protected:
        Gadget(Impl &impl, const std::string &s, int value = 0);
    };

}

#endif // OBJECT_H
