#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>

#include <testlib/testlib_global.h>

namespace testlib {

    class TESTLIB_EXPORT Container {
        TESTLIB_DECLARE_IMPL(Container)
    public:
        explicit Container(int value = 0);
        virtual ~Container();

    public:
        int value() const;
        void setValue(int value);

    protected:
        Container(Impl &impl, int value = 0);
        std::shared_ptr<Impl> _impl;
    };

}

#endif // CONTAINER_H
