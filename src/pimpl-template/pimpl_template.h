#ifndef PIMPL_TEMPLATE_H
#define PIMPL_TEMPLATE_H

#include <memory>
#include <type_traits>

namespace pimpl {

    // Unique Data
    template <class T, class T1 = T>
    inline const T *get_impl(const std::unique_ptr<T1> &d) {
        return static_cast<const T *>(d.get());
    }

    template <class T, class T1 = T>
    inline T *get_impl(std::unique_ptr<T1> &d) {
        return static_cast<T *>(d.get());
    }

    // Shared Data
    template <class T, class T1 = T>
    inline const T *get_impl(const std::shared_ptr<T1> &d) {
        return static_cast<const T *>(d.get());
    }

    template <class T, class T1 = T>
    inline T *get_impl(std::shared_ptr<T1> &d) {
        if (d.use_count() > 1) {
            d = std::make_shared<T>(*static_cast<T *>(d.get())); // detach
        }
        return static_cast<T *>(d.get());
    }

}

#define PIMPL_DECLARE_IMPL(T)                                                                      \
public:                                                                                            \
    class Impl;                                                                                    \
    friend class Impl;

#define PIMPL_DECLARE_INTF(T)                                                                      \
public:                                                                                            \
    using Intf = T;                                                                                \
    friend class T;

#define pimpl_get_impl(T) ::pimpl::get_impl<std::remove_const_t<T::Impl>>(_impl)
#define pimpl_get_intf(T) static_cast<T *>(_intf)

#define PIMPL_IMPL(T) auto &impl = *pimpl_get_impl(T)
#define PIMPL_INTF(T) auto &intf = *pimpl_get_intf(T)

#define PIMPL_IMPL_THIS PIMPL_IMPL(std::remove_pointer_t<decltype(this)>)
#define PIMPL_INTF_THIS PIMPL_INTF(Intf)

#endif // PIMPL_TEMPLATE_H
