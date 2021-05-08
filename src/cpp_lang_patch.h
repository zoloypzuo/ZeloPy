// cpp_lang_patch.h
// created on 2020/2/4
// author @zoloypzuo

#ifndef ZELOSPEED_CPP_LANG_PATCH_H
#define ZELOSPEED_CPP_LANG_PATCH_H

#include <cstdint>  // for int types

//--------------------------------------------------------------------------------------
// abstract class
//--------------------------------------------------------------------------------------
// mark class as abstract class
#define ZELO_ABSTRACT

//--------------------------------------------------------------------------------------
// interface
//--------------------------------------------------------------------------------------
// mark class as interface
#define ZELO_INTERFACE class
// implement "keyword"
#define ZELO_IMPLEMENTS public

//--------------------------------------------------------------------------------------
// accessor
//--------------------------------------------------------------------------------------
#define ZELO_SET_INTERFACE(t, n) virtual void Set##n(t value) = 0
#define ZELO_GET_INTERFACE(t, n) virtual t Get##n() = 0
#define ZELO_GET_SET_INTERFACE(t, n) ZELO_SET_INTERFACE(t, n); ZELO_GET_INTERFACE(t, n)

#define ZELO_SET_OVERRIDE(t, n) inline void Set##n(t value) override { m_##n = value; }
#define ZELO_GET_OVERRIDE(t, n) inline t Get##n() override { return m_##n; }
#define ZELO_GET_SET_OVERRIDE(t, n) ZELO_SET_OVERRIDE(t, n) ZELO_GET_OVERRIDE(t, n)

#define ZELO_SET(t, n) inline void Set##n(t value) { m_##n = value; }
#define ZELO_GET(t, n) inline t Get##n() { return m_##n; }
#define ZELO_GET_SET(t, n) ZELO_SET(t, n) ZELO_GET(t, n)

//--------------------------------------------------------------------------------------
// misc
//--------------------------------------------------------------------------------------

namespace Zelo {
    // [x] add type U8, U16, U64 if needed
    typedef float F32;
    typedef double F64;
    typedef std::uint32_t U32;
    typedef std::int32_t I32;
    typedef std::uint64_t U64;
    typedef std::int64_t I64;
    typedef std::uint8_t U8;
    typedef std::int8_t I8;
    typedef std::uint16_t U16;
    typedef std::int16_t I16;

    // fast unsigned int
    typedef std::uint_fast32_t U32F;
    // fast int
    typedef std::int_fast32_t I32F;
}

#endif //ZELOSPEED_CPP_LANG_PATCH_H