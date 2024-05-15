#ifndef OBJECT_H
#define OBJECT_H

#include <string>

#include <testlib/testlib_global.h>

#include <pimpl-template/pimpl_template.h>

namespace pimpl {

    class TESTLIB_EXPORT Object {
        PIMPL_DECLARE_IMPL(Object)
    public:
        explicit Object(int value = 0);
        virtual ~Object();

    public:
        int value() const;
        void setValue(int value);

        int value2() const;
        void setValue2(int value);

    protected:
        std::unique_ptr<Impl> _impl;
        Object(Impl &impl, int value = 0);
    };

    class TESTLIB_EXPORT Gadget : public Object {
        PIMPL_DECLARE_IMPL(Gadget)
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
