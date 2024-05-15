#ifndef CONTAINER_H
#define CONTAINER_H

#include <testlib/testlib_global.h>

#include <pimpl-template/pimpl_template.h>

namespace pimpl {

    class TESTLIB_EXPORT Container {
        PIMPL_DECLARE_IMPL(Container)
    public:
        explicit Container(int value = 0);
        virtual ~Container();

    public:
        int value() const;
        void setValue(int value);

        int value2() const;
        void setValue2(int value);

    protected:
        Container(Impl &impl, int value = 0);
        std::shared_ptr<Impl> _impl;
    };

}

#endif // CONTAINER_H
