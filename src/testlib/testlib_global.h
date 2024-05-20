#ifndef TESTLIB_GLOBAL_H
#define TESTLIB_GLOBAL_H

#ifdef _MSC_VER
#  define TESTLIB_DECL_EXPORT __declspec(dllexport)
#  define TESTLIB_DECL_IMPORT __declspec(dllimport)
#else
#  define TESTLIB_DECL_EXPORT __attribute__((visibility("default")))
#  define TESTLIB_DECL_IMPORT __attribute__((visibility("default")))
#endif

#ifndef TESTLIB_EXPORT
#  ifdef TESTLIB_STATIC
#    define TESTLIB_EXPORT
#  else
#    ifdef TESTLIB_LIBRARY
#      define TESTLIB_EXPORT TESTLIB_DECL_EXPORT
#    else
#      define TESTLIB_EXPORT TESTLIB_DECL_IMPORT
#    endif
#  endif
#endif

#define TESTLIB_DECLARE_IMPL(T)                                                                    \
public:                                                                                            \
    class Impl;                                                                                    \
    friend class Private;

#define TESTLIB_DECLARE_DECL(T)                                                                    \
public:                                                                                            \
    using Decl = T;                                                                                \
    friend class T;


#endif // TESTLIB_GLOBAL_H
