//
// bind/mem_fn_template.hpp
//
// Do not include this header directly
//
// Copyright 2001, 2024 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/bind/mem_fn.html for documentation.
//

// mf

template<class R, class T, class... A> class BOOST_MEM_FN_NAME(mf)
{
public:

    typedef R result_type;

private:
    
    typedef R (BOOST_MEM_FN_CC T::*F) (A...);
    F f_;

    template<class U, class... B> R call(U & u, T const *, B&... b) const
    {
        return (u.*f_)(b...);
    }

    template<class U, class... B> R call(U & u, void const *, B&... b) const
    {
        return (get_pointer(u)->*f_)(b...);
    }

public:
    
    explicit BOOST_MEM_FN_NAME(mf)(F f): f_(f) {}

    R operator()(T * p, A... a) const
    {
        return (p->*f_)(a...);
    }

    template<class U> R operator()(U & u, A... a) const
    {
        U const * p = 0;
        return call(u, p, a...);
    }

    template<class U> R operator()(U const & u, A... a) const
    {
        U const * p = 0;
        return call(u, p, a...);
    }

    R operator()(T & t, A... a) const
    {
        return (t.*f_)(a...);
    }

    bool operator==(BOOST_MEM_FN_NAME(mf) const & rhs) const
    {
        return f_ == rhs.f_;
    }

    bool operator!=(BOOST_MEM_FN_NAME(mf) const & rhs) const
    {
        return f_ != rhs.f_;
    }
};

// cmf

template<class R, class T, class... A> class BOOST_MEM_FN_NAME(cmf)
{
public:

    typedef R result_type;

private:
    
    typedef R (BOOST_MEM_FN_CC T::*F) (A...) const;
    F f_;

    template<class U, class... B> R call(U & u, T const *, B&... b) const
    {
        return (u.*f_)(b...);
    }

    template<class U, class... B> R call(U & u, void const *, B&... b) const
    {
        return (get_pointer(u)->*f_)(b...);
    }

public:
    
    explicit BOOST_MEM_FN_NAME(cmf)(F f): f_(f) {}

    R operator()(T const * p, A... a) const
    {
        return (p->*f_)(a...);
    }

    template<class U> R operator()(U const & u, A... a) const
    {
        U const * p = 0;
        return call(u, p, a...);
    }

    R operator()(T const & t, A... a) const
    {
        return (t.*f_)(a...);
    }

    bool operator==(BOOST_MEM_FN_NAME(cmf) const & rhs) const
    {
        return f_ == rhs.f_;
    }

    bool operator!=(BOOST_MEM_FN_NAME(cmf) const & rhs) const
    {
        return f_ != rhs.f_;
    }
};
