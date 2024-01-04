//
// bind/mem_fn_cc.hpp - support for different calling conventions
//
// Do not include this header directly.
//
// Copyright 2001, 2024 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/bind/mem_fn.html for documentation.
//

template<class R, class T, class... A>
_mfi::mf< R (BOOST_MEM_FN_CC T::*) (A...) BOOST_MEM_FN_NOEXCEPT, R, T, A... >
mem_fn( R (BOOST_MEM_FN_CC T::*pmf) (A...) BOOST_MEM_FN_NOEXCEPT )
{
    return pmf;
}

template<class R, class T, class... A>
_mfi::mf< R (BOOST_MEM_FN_CC T::*) (A...) const BOOST_MEM_FN_NOEXCEPT, R, T, A... >
mem_fn( R (BOOST_MEM_FN_CC T::*pmf) (A...) const BOOST_MEM_FN_NOEXCEPT )
{
    return pmf;
}
